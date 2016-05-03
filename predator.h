#ifndef PREDATOR_H
#define PREDATOR_H

#include "creature.h"

class Boid;

class Predator : public Creature
{
public:
    Predator(Position2D position, Velocity2D velocity);
    ~Predator();

    void setOffense(bool offense);
    bool getOffense();

    Boid* findTarget(QList<Boid *> *allBoids);
    Velocity2D calculateVelocity();

private:
    bool isOffensive;
    float targetBoidDistance;
    float targetChaseFactor;

    Boid *targetBoid;

    void calculateVelocityBasedOnTarget(Velocity2D&);
};

#endif // PREDATOR_H
