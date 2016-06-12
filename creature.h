#ifndef CREATURE_H
#define CREATURE_H

#include <QtCore/qmath.h>

#include "typedefs.h"
#include "obstacle.h"

/*!
 * \brief The Creature class.
 * Base class of Predator and Boid
 */
class Creature
{
public:
    /*!
     * \brief Constructor of the Creature class
     */
    Creature();
    /*!
     * \brief Virtual destructor of the Creature class
     */
    virtual ~Creature();
    /*!
     * \brief Method returning size of a Creature object
     * \return float value representing creature size (used to draw creatures)
     */
    float getSize();
    /*!
     * \brief Method returning width of a Creature object
     * \return float value representing creature width (used to draw creatures)
     */
    float getWidth();
    /*!
     * \brief Method returning length of a Creature object
     * \return float value representing creature length (used to draw creatures)
     */
    float getLength();
    /*!
     * \brief Sets size of a Creature object
     * \param size float value representing object size
     */
    void setSize(float size);
    /*!
     * \brief Sets width of a Creature object
     * \param width float value representing object width
     */
    void setWidth(float width);
    /*!
     * \brief Sets length of a Creature object
     * \param length float value representing object length
     */
    void setLength(float length);
    /*!
     * \brief Method returning current position of a creature
     * \return current position as a Position2D struct (float x & float y)
     */
    Position2D getPosition();
    /*!
     * \brief Method returning current position of a creature
     * \return current position as a Position2D struct (float x & float y)
     */
    Velocity2D getVelocity();
    /*!
     * \brief Method returning velocity vector angle
     * \return float value representing velocity vector angle (0 - PI)
     */
    float getVelocityAngle();
    /*!
     * \brief Method returning list of obstacles close to a creature
     * \return list of pointers to Obstacle objects
     */
    QList<Obstacle *> getCloseObstacles();
    /*!
     * \brief Method finding obstacles which are close to a creature
     * \param allObstacles list of all created Obstacle objects
     * \return list of pointers to Obstacle objects
     */
    QList<Obstacle *> findObstacles(QList<Obstacle *> *allObstacles);
    /*!
     * \brief Pure virtual method, calculates velocity of objects of derived classes
     * \return Velocity2D struct containing xVelocity & yVelocity
     */
    virtual Velocity2D calculateVelocity() = 0;
    /*!
     * \brief Method updating creatures velocity, writes calculated velocity to actual velocity of a creature
     */
    void updateVelocity();
    /*!
     * \brief Method updating position of a creature, adds calculated velocity to x & y position members
     * \param height drawing window height (for border checking purpose)
     * \param width drawing window width (for border checking purpose)
     */
    void updatePosition(int height, int width); //do x,y dodawane sa wartosci vx i vy

protected:
    /*!
     * \brief Size of a creature (drawing usage)
     */
    float size;
    /*!
     * \brief Width of a creature (drawing usage)
     */
    float width;
    /*!
     * \brief Length of a creature (drawing usage)
     */
    float length;
    /*!
     * \brief Position2D struct containing x & y position of a creature
     */
    Position2D position;
    /*!
     * \brief Velocity2D struct containing x & y future (just calculated) velocity of a creature
     */
    Velocity2D futureVelocity;
    /*!
     * \brief Velocity2D struct containing x & y current velocity of a creature
     */
    Velocity2D velocity;
    /*!
     * \brief float value representing absolute value of current velocity of a creature
     */
    float actualVelocity;
    /*!
     * \brief float value representing velocity vector angle (0 - PI)
     */
    float velocityAngle;

    /*!
     * \brief Method reducing velocity if exceeds max value
     * \param compareMaxVelocity max velocity value
     */
    void checkMaxVelocity(float compareMaxVelocity);
    /*!
     * \brief Adds random values to creature velocity, does not exceed max velocity value
     * \param futureVelocity reference of creature velocity
     * \param compareMaxVelocity max velocity value - passed here so method won't exceed the value
     */
    void addRandomNoise(Velocity2D& futureVelocity, float compareMaxVelocity);
    /*!
     * \brief list of Obstacle objects which are currently close to a creature
     */
    QList<Obstacle *> *closeObstacles;
    /*!
     * \brief Modifies creature velocity according to close Obstacle objects
     * \param futureVelocity reference of creature velocity to be modified
     */
    void calculateVelocityBasedOnObstacles(Velocity2D& futureVelocity);

private:
    void checkBorders(int, int);
};

#endif // CREATURE_H
