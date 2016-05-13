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

    void setSize(float size);
    void setWidth(float width);
    void setLength(float length);
    float getSize();
    float getWidth();
    float getLength();

    Position2D getPosition();
    Velocity2D getVelocity();
    float getMaxVelocity();
    float getSightDistance();
    float getSightAngle();
    float getVelocityAngle();
    QList<Obstacle *> getCloseObstacles();

    QList<Obstacle *> findObstacles(QList<Obstacle *> *allObstacles);
    virtual Velocity2D calculateVelocity() = 0;
    void updateVelocity();

    void setPosition(Position2D);
    void setVelocity(Velocity2D);
    void setMaxVelocity(float);
    void setSightDistance(float);
    void setSightAngle(float);

    void updatePosition(int, int); //do x,y dodawane sa wartosci vx i vy

protected:
    float size;
    float width;
    float length;

    Position2D position;
    Velocity2D futureVelocity;
    Velocity2D velocity;

    float maxVelocity;
    float sightDistance;
    float sightAngle;
    float velocityAngle;
    float actualVelocity;
    float velocityLimitFactor;
    float randomFactor;

    void checkMaxVelocity();
    void addRandomNoise(Velocity2D&);

    QList<Obstacle *> *closeObstacles;

    void calculateVelocityBasedOnObstacles(Velocity2D&);

private:
    void checkBorders(int, int);
};

#endif // CREATURE_H
