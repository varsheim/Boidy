#include "mainwindow.h"
#include "environment.h"
#include "algorithm.h"
#include "creature.h"
#include "boid.h"
#include "predator.h"

#include <QtWidgets>
#include <QtOpenGL>
#include <QList>

Environment::Environment(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //*** TWORZENIE PIERWSZYCH BOIDOW ***
    createBoidSwarmOnStart(Algorithm::onStartBoidQuantity,
                           Algorithm::startXPos,
                           Algorithm::startYPos,
                           Algorithm::startXVelo,
                           Algorithm::startYVelo);

    //*** TWORZENIE PIERWSZYCH PREDATOROW ***
    createPredatorSwarmOnStart(Algorithm::onStartPredatorQuantity,
                               Algorithm::startXPos,
                               Algorithm::startYPos,
                               Algorithm::startXVelo,
                               Algorithm::startYVelo);

    //*** TWORZENIE PIERWSZYCH PRZESZKOD ***
    createObstaclesOnStart(Algorithm::onStartObstacleQuantity);

    //timer rysujacy wszystko
    drawingDelay = 10; //co ile ms odswieza mape
    QTimer *drawingTimer = new QTimer(this);
    connect(drawingTimer, SIGNAL(timeout()), this, SLOT(updateEnvironment()));
    drawingTimer->start(drawingDelay);

    //inicjalizacja timera liczacego z klasy Algorithm
    connect(Algorithm::getCalculatingTimer(), SIGNAL(timeout()), this, SLOT(updateCreatures()));
    Algorithm::initialize();
}

Environment::~Environment()
{
    qDeleteAll(boidSwarm->begin(), boidSwarm->end());
    boidSwarm->clear();
    delete boidSwarm;

    qDeleteAll(predatorSwarm->begin(), predatorSwarm->end());
    predatorSwarm->clear();
    delete predatorSwarm;

    qDeleteAll(obstacles->begin(), obstacles->end());
    obstacles->clear();
    delete obstacles;
}

void Environment::createBoidSwarmOnStart(int quantity,
                                         float startXPos,
                                         float startYPos,
                                         float startXVelo,
                                         float startYVelo)
{
    boidSwarm = new QList<Boid *>;
    Position2D tempPosition;
    Velocity2D tempVelocity;

    tempVelocity.xVelocity = startXVelo;
    tempVelocity.yVelocity = startYVelo;

    for (int i = 0; i < quantity; i++){
        tempPosition.x = startXPos * (i + 1);
        tempPosition.y = startYPos * (i + 1);
        boidSwarm->append(new Boid(tempPosition, tempVelocity));
    }
}

void Environment::createPredatorSwarmOnStart(int quantity,
                                             float startXPos,
                                             float startYPos,
                                             float startXVelo,
                                             float startYVelo)
{
    predatorSwarm = new QList<Predator *>;
    Position2D tempPosition;
    Velocity2D tempVelocity;

    tempVelocity.xVelocity = startXVelo;
    tempVelocity.yVelocity = startYVelo;

    for(int i = 0; i < quantity; i++){
        tempPosition.x = -startXPos*i;
        tempPosition.y = -startYPos*i;
        predatorSwarm->append(new Predator(tempPosition, tempVelocity));
    }
}

void Environment::createObstaclesOnStart(int quantity)
{
    Position2D tempPosition;

    obstacles = new QList<Obstacle *>;
    for(int i = 0; i < quantity; i++){
        tempPosition.x = (qrand() % 200 - 100) / 50.0;
        tempPosition.y = (qrand() % 200 - 100) / 50.0;
        obstacles->append(new Obstacle(tempPosition));
    }
}

//eventy myszy
void Environment::boidMousePressEvent(QMouseEvent *event)
{
    Position2D mousePosition;
    mousePosition.x = (event->x() - 300)/150.0;
    mousePosition.y = (- event->y() + 300)/150.0;

    Velocity2D tempVelocity;
    tempVelocity.xVelocity = Algorithm::startXVelo;
    tempVelocity.yVelocity = Algorithm::startXVelo;

    if(event->button() == Qt::LeftButton){
        boidSwarm->append(new Boid(mousePosition, tempVelocity));
    }
    else if(event->button() == Qt::RightButton){
        if(boidSwarm->length() > 2){
            delete boidSwarm->takeLast();
        }
    }
}

void Environment::predatorMousePressEvent(QMouseEvent *event)
{
    Position2D mousePosition;
    mousePosition.x = (event->x() - 300)/150.0;
    mousePosition.y = (- event->y() + 300)/150.0;

    Velocity2D tempVelocity;
    tempVelocity.xVelocity = Algorithm::startXVelo;
    tempVelocity.yVelocity = Algorithm::startXVelo;

    if(event->button() == Qt::LeftButton){
        predatorSwarm->append(new Predator(mousePosition, tempVelocity));
    }
    else if(event->button() == Qt::RightButton){
        if(predatorSwarm->length() > 0){
            delete predatorSwarm->takeLast();
        }
    }
}

void Environment::obstacleMousePressEvent(QMouseEvent *event)
{
    Position2D mousePosition;
    mousePosition.x = (event->x() - 300)/150.0;
    mousePosition.y = (- event->y() + 300)/150.0;

    if(event->button() == Qt::LeftButton){
        obstacles->append(new Obstacle(mousePosition));
    }
    else if(event->button() == Qt::RightButton){
        if(obstacles->length() > 0){
            delete obstacles->takeLast();
        }
    }
}

void Environment::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        mouseLeftDown = true;
    }
    else if(event->button() == Qt::RightButton){
        mouseRightDown = true;
    }
    mouseOldPosition.x = (event->x() - 300)/150.0;
    mouseOldPosition.y = (- event->y() + 300)/150.0;

    emit sendNeighboursAmount(obstacles->length(), 0, 0);
}

void Environment::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        mouseLeftDown = false;
    }
    else if(event->button() == Qt::RightButton){
        mouseRightDown = false;
    }
}

QSize Environment::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize Environment::sizeHint() const
{
    return QSize(400, 400);
}

void Environment::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void Environment::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0); //wektor translacji, przsuniecie x, y i oddalenie z
    glRotatef(0, 1.0, 0.0, 0.0); //pierwszy argument opisuje kat obrotu wokol osi oznaczonej przez "1.0"
    glRotatef(0, 0.0, 1.0, 0.0);
    glRotatef(0, 0.0, 0.0, 1.0);
    draw();
}

void Environment::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void Environment::updateCreatures()
{
    //ponizej petle zawierajace: 1.okresl sasiadow 2.przelicz predkosc
    for(int i = 0; i < boidSwarm->length(); i++){
        boidSwarm->at(i)->findNeighbours(boidSwarm);
        boidSwarm->at(i)->findPredators(predatorSwarm);
        boidSwarm->at(i)->findObstacles(obstacles);
    }

    for(int i = 0; i < boidSwarm->length(); i++){
        boidSwarm->at(i)->calculateVelocity(); //obliczenie przyszlej predkosci
    }

    for(int i = 0; i < predatorSwarm->length(); i++){
        predatorSwarm->at(i)->findTarget(boidSwarm);
        predatorSwarm->at(i)->findObstacles(obstacles);
    }

    for(int i = 0; i < predatorSwarm->length(); i++){
        predatorSwarm->at(i)->calculateVelocity(); //obliczenie przyszlej predkosci
    }
}

void Environment::updateEnvironment()
{
    for(int i = 0; i < boidSwarm->length(); i++){
        boidSwarm->at(i)->updateVelocity(); //ustawienie velocity = futureVelocity
        boidSwarm->at(i)->updatePosition(height(), width());
    }

    for(int i = 0; i < predatorSwarm->length(); i++){
        predatorSwarm->at(i)->updateVelocity(); //ustawienie velocity = futureVelocity
        predatorSwarm->at(i)->updatePosition(height(), width());
    }

    mouseDrawObstacles();
    updateGL(); //rysuj wszystko
}

void Environment::mouseDrawObstacles()
{
    Position2D tempMousePosition;
    tempMousePosition.x = (this->mapFromGlobal(QCursor::pos()).x() - 300) / 150.0;
    tempMousePosition.y = (- this->mapFromGlobal(QCursor::pos()).y() + 300) / 150.0;

    float tempMouseDistance;
    tempMouseDistance = qSqrt(qPow((tempMousePosition.x - mouseOldPosition.x), 2) +
                              qPow((tempMousePosition.y - mouseOldPosition.y), 2));

    if(mouseLeftDown && tempMouseDistance > 0.05){
        mouseOldPosition = tempMousePosition;
        obstacles->append(new Obstacle(tempMousePosition));
    }
    else if(mouseRightDown){
        float tempObstacleDistance;
        for(int i = 0; i < obstacles->length(); i++){
            tempObstacleDistance = qSqrt(qPow((tempMousePosition.x - obstacles->at(i)->getPosition().x), 2) +
                                         qPow((tempMousePosition.y - obstacles->at(i)->getPosition().y), 2));
            if(tempObstacleDistance < 0.1){
                delete obstacles->takeAt(i);
            }
        }
    }
}

void Environment::drawObstacles(QList<Obstacle *> *obstacles)
{
    for(int i = 0; i < obstacles->length(); i++){
        qglColor(Qt::white);
            glRectf((obstacles->at(i)->getPosition() - obstacles->at(i)->getSize()).x,
                    (obstacles->at(i)->getPosition() - obstacles->at(i)->getSize()).y,
                    (obstacles->at(i)->getPosition() + obstacles->at(i)->getSize()).x,
                    (obstacles->at(i)->getPosition() + obstacles->at(i)->getSize()).y);
    }
}

void Environment::drawBoidSwarm(QList<Boid *> *boidSwarm)
{
    for(int i = 0; i < boidSwarm->length(); i++){
        glPointSize(boidSwarm->at(i)->getSize());
        glLineWidth(boidSwarm->at(i)->getWidth());
        qglColor(Qt::blue);
        glBegin(GL_POINTS);
            glVertex2f(boidSwarm->at(i)->getPosition().x, boidSwarm->at(i)->getPosition().y);
        glEnd();

        qglColor(Qt::yellow);
        glBegin(GL_LINES);
            glVertex2f(boidSwarm->at(i)->getPosition().x,
                       boidSwarm->at(i)->getPosition().y);
            glVertex2f(boidSwarm->at(i)->getPosition().x
                       + boidSwarm->at(i)->getLength() * qCos(boidSwarm->at(i)->getVelocityAngle()),
                       boidSwarm->at(i)->getPosition().y
                       + boidSwarm->at(i)->getLength() * qSin(boidSwarm->at(i)->getVelocityAngle()));
        glEnd();
    }
}

void Environment::drawPredatorSwarm(QList<Predator *> *predatorSwarm)
{
    for(int i = 0; i < predatorSwarm->length(); i++){
        glPointSize(predatorSwarm->at(i)->getSize());
        glLineWidth(predatorSwarm->at(i)->getWidth());
        qglColor(Qt::red);
        glBegin(GL_POINTS);
            glVertex2f(predatorSwarm->at(i)->getPosition().x, predatorSwarm->at(i)->getPosition().y);
        glEnd();

        qglColor(Qt::red);
        glBegin(GL_LINES);
            glVertex2f(predatorSwarm->at(i)->getPosition().x,
                       predatorSwarm->at(i)->getPosition().y);
            glVertex2f(predatorSwarm->at(i)->getPosition().x
                       + predatorSwarm->at(i)->getLength() * qCos(predatorSwarm->at(i)->getVelocityAngle()),
                       predatorSwarm->at(i)->getPosition().y
                       + predatorSwarm->at(i)->getLength() * qSin(predatorSwarm->at(i)->getVelocityAngle()));
        glEnd();
    }
}

void Environment::draw()
{
    // *** RYSOWANIE BOIDOW ***
    drawBoidSwarm(boidSwarm);

    //*** RYSOWANIE PREDATOROW ***
    drawPredatorSwarm(predatorSwarm);

    //*** RYSOWANIE PRZESZKOD ***
    drawObstacles(obstacles);
}
