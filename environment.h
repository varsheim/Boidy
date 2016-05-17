#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QWidget>
#include <QGLWidget>

#include "boid.h"
#include "predator.h"
#include "obstacle.h"

class Environment : public QGLWidget
{
    Q_OBJECT
public:
    explicit Environment(QWidget *parent = 0);
    ~Environment();

    void switchBoidDrawing(bool);
    void switchPredatorDrawing(bool);
    void switchObstacleDrawing(bool);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

private:
    float startXPos;
    float startYPos;
    float startXVelo;
    float startYVelo;
    int boidQuantity;
    int predatorQuantity;
    int obstacleQuantity;

    int drawingDelay;
    int calculatingDelay;

    void draw();
    void drawBoidSwarm(QList<Boid *> *swarm);
    void drawPredatorSwarm(QList<Predator *> *swarm);
    void drawObstacles(QList<Obstacle *> *obstacles);

    void createBoidSwarmOnStart(int quantity, float startXPos, float startYPos, float startXVelo, float startYVelo);
    void createPredatorSwarmOnStart(int quantity, float startXPos, float startYPos, float startXVelo, float startYVelo);
    void createObstaclesOnStart(int quantity); //DO DOKONCZENIA!

    QList<Boid *> *boidSwarm;
    QList<Predator *> *predatorSwarm;
    QList<Obstacle *> *obstacles;

    //obsluga myszy
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void boidMousePressEvent(QMouseEvent *event);
    void predatorMousePressEvent(QMouseEvent *event);

    Position2D mouseOldPosition;
    void mouseDrawObstacles();

    bool mouseLeftDown;
    bool mouseRightDown;

    bool boidDrawingOn;
    bool predatorDrawingOn;
    bool obstacleDrawingOn;

signals:
    void sendNeighboursAmount(float, float, float);

private slots:
    void updateEnvironment();
    void updateCreatures();
};

#endif // ENVIRONMENT_H
