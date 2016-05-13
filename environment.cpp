#include "mainwindow.h"
#include "environment.h"
#include "creature.h"
#include "boid.h"
#include "predator.h"

#include <QtWidgets>
#include <QtOpenGL>
#include <QList>

Environment::Environment(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    startXPos = 0.002;
    startYPos = 0.002;
    startXVelo = 0.05;
    startYVelo = 0.05;
    boidQuantity = 50;
    predatorQuantity = 2;
    obstacleQuantity = 10;

    drawingDelay = 10; //co ile ms odswieza mape
    calculatingDelay = 10; // co ile ms przelicza obiekty

    //*** TWORZENIE BOIDOW ***
    createBoidSwarmOnStart(boidQuantity, startXPos, startYPos, startXVelo, startYVelo);

    //*** TWORZENIE PREDATOROW ***
    createPredatorSwarmOnStart(predatorQuantity, startXPos, startYPos, startXVelo, startYVelo);

    //*** TWORZENIE PRZESZKOD ***
    createObstaclesOnStart(obstacleQuantity);

    //timer rysujacy wszystko
    QTimer *drawingTimer = new QTimer(this);
    connect(drawingTimer, SIGNAL(timeout()), this, SLOT(updateEnvironment()));
    drawingTimer->start(drawingDelay);

    //timer liczacy wszystko
    QTimer *calculatingTimer = new QTimer(this);
    connect(calculatingTimer, SIGNAL(timeout()), this, SLOT(updateCreatures()));
    calculatingTimer->start(calculatingDelay);
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
        tempPosition.x = startXPos*i;
        tempPosition.y = startYPos*i;
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
    //wyrzucanie wybranego info na ekran
    emit sendNeighboursAmount(boidSwarm->at(0)->getCloseObstacles().length(),
                              boidSwarm->at(1)->getCloseObstacles().length(),
                              boidSwarm->at(2)->getCloseObstacles().length());

    for(int i = 0; i < predatorSwarm->length(); i++){
        predatorSwarm->at(i)->updateVelocity(); //ustawienie velocity = futureVelocity
        predatorSwarm->at(i)->updatePosition(height(), width());
    }

    updateGL(); //rysuj wszystko
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
