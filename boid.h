#ifndef BOID_H
#define BOID_H

#include <QList>

#include "creature.h"

class Predator;

class Boid : public Creature
{
public:
    //Boid();
    Boid(Position2D position, Velocity2D velocity);
    ~Boid();

    int getNeighboursAmount();
    Velocity2D getNeighboursAverageVelocity();
    float getNeighboursAverageDistance();
    QList<Boid *> getNeighbours();
    QList<Predator *> getClosePredators();

    QList<Boid *> findNeighbours(QList<Boid *> *allBoids);
    QList<Predator *> findPredators(QList<Predator *> *allPredators);

    Velocity2D calculateVelocity();

protected:


private:
    float neighboursVelocityFitFactor;
    float neighboursGroupFitFactor;
    float neighboursMinDistanceFactor;
    float minDistance;
    float predatorMinDistance;
    float predatorMinDistanceFactor;
    float predatorSightDistance;
    float predatorSightAngle;

    QList<Boid *> *neighbours;
    QList<Predator *> *closePredators;

    int neighboursAmount;
    Velocity2D neighboursAverageVelocity;
    float neighboursAverageDistance;

    int countNeighbours();
    Velocity2D calculateNeighboursAverageVelocity();
    void calculateNeighboursAverageDistance();
    void calculateVelocityBasedOnVelocity(Velocity2D&, Velocity2D, Velocity2D);
    void calculateVelocityBasedOnPosition(Velocity2D&);
    void calculateVelocityBasedOnDistance(Velocity2D&);
    void calculateVelocityBasedOnPredators(Velocity2D&);
};

#endif // BOID_H
