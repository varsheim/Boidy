#ifndef PREDATOR_H
#define PREDATOR_H

#include "creature.h"

class Boid;
/*!
 * \brief The Predator class, objects of this class are pursuing boids
 */
class Predator : public Creature
{
public:
    /*!
     * \brief Constructor of the Predator method, sets the initial parameters by passing position and velocity arguments
     * \param position Starting position passed in Position2D struct
     * \param velocity Starting velocity passed in Velocity2D struct
     */
    Predator(Position2D position, Velocity2D velocity);
    ~Predator();
    /*!
     * \brief Method searching through the list of all boids looking for the closest target boid
     * \param allBoids list of all Boid objects
     * \return pointer to the closest Boids object which becomes a target
     */
    Boid* findTarget(QList<Boid *> *allBoids);
    /*!
     * \brief Method calculating velocity of a predator according to the target
     * \return calculated velocity of a predator contained in Velocity2D struct
     */
    Velocity2D calculateVelocity();

private:
    float targetBoidDistance;

    Boid *targetBoid;

    void calculateVelocityBasedOnTarget(Velocity2D&);
};

#endif // PREDATOR_H
