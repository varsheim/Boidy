#ifndef CREATURE_H
#define CREATURE_H

#include <QtCore/qmath.h>

#include "typedefs.h"
#include "obstacle.h"

class Creature
{
public:
    Creature();
    virtual ~Creature();

    float getSize();
    float getWidth();
    float getLength();
    void setSize(float size);
    void setWidth(float width);
    void setLength(float length);

    Position2D getPosition();
    Velocity2D getVelocity();
    float getVelocityAngle();
    QList<Obstacle *> getCloseObstacles();

    QList<Obstacle *> findObstacles(QList<Obstacle *> *allObstacles);
    virtual Velocity2D calculateVelocity() = 0;
    void updateVelocity();
    void updatePosition(int, int); //do x,y dodawane sa wartosci vx i vy

protected:
    float size;
    float width;
    float length;

    Position2D position;
    Velocity2D futureVelocity;
    Velocity2D velocity;
    float actualVelocity;
    float velocityAngle;

    void checkMaxVelocity(float);
    void addRandomNoise(Velocity2D&, float);

    QList<Obstacle *> *closeObstacles;

    void calculateVelocityBasedOnObstacles(Velocity2D&);

private:
    void checkBorders(int, int);
};

#endif // CREATURE_H
