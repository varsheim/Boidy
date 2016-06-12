#ifndef BOID_H
#define BOID_H

#include <QList>

#include "creature.h"

class Predator;
/*!
 * \brief The Boid class inherits from Creature.
 * Boids are moving objects behaving like swarm
 */
class Boid : public Creature
{
public:
    /*!
     * \brief Constructor of the Boid class
     * \param position: defines starting position of a boid
     * \param velocity: defines starting velocity of a boid
     */
    Boid(Position2D position, Velocity2D velocity);
    ~Boid();
    /*!
     * \brief Method returning the amount of boid neighbours
     * \return amount of neighbours of a boid
     */
    int getNeighboursAmount();
    /*!
     * \brief Method returning average velocity of neighbours
     * \return Velocity2D struct, returned value is kept separately as xVelocity & yVelocity members
     */
    Velocity2D getNeighboursAverageVelocity();
    /*!
     * \brief Method returning average distance of neighbours
     * \return average neighbours distance as a float value
     */
    float getNeighboursAverageDistance();
    /*!
     * \brief Method returning list of boid neighbours
     * \return list of pointers to Boid objects
     */
    QList<Boid *> getNeighbours();
    /*!
     * \brief Method returning list of close predators
     * \return list of pointers to Predator objects
     */
    QList<Predator *> getClosePredators();
    /*!
     * \brief Method searching for boids which are in sight area of a particular boid
     * \param allBoids list of boids to iterate through and pick neighbours
     * \return list of pointers to Boid objects
     */
    QList<Boid *> findNeighbours(QList<Boid *> *allBoids);
    /*!
     * \brief Method searching for predators which are in sight area of a particular boid
     * \param allPredators list of predators to iterate through and pick close predators
     * \return list of pointers to Predator objects
     */
    QList<Predator *> findPredators(QList<Predator *> *allPredators);
    /*!
     * \brief Method calculating velocity of the boid. Every factor is considered inside this method
     * \return calculated velocity of the boid
     */
    Velocity2D calculateVelocity();

protected:


private:
    QList<Boid *> *neighbours;
    QList<Predator *> *closePredators;

    int neighboursAmount;
    Velocity2D neighboursAverageVelocity;
    float neighboursAverageDistance;

    Velocity2D calculateNeighboursAverageVelocity();
    void calculateNeighboursAverageDistance();
    void calculateVelocityBasedOnVelocity(Velocity2D&, Velocity2D, Velocity2D);
    void calculateVelocityBasedOnPosition(Velocity2D&);
    void calculateVelocityBasedOnDistance(Velocity2D&);
    void calculateVelocityBasedOnPredators(Velocity2D&);
};

#endif // BOID_H
