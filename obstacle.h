#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "typedefs.h"
/*!
 * \brief The Obstacle class, obstacle objects are avoided by boids and predators. These are shown as white rectangles
 */
class Obstacle
{
public:
    /*!
     * \brief Constructor of the Obstacle class, creates new obstacle with set position
     * \param position passed position of the obstacle
     */
    Obstacle(Position2D position);
    ~Obstacle();

    /*!
     * \brief Method returning position of an obstacle
     * \return position is returned in Position2D struct which hols xPos & yPos
     */
    Position2D getPosition();
    /*!
     * \brief Method returning size of an obstacle
     * \return size is returned in Size2D struct which hold xSize & ySize
     */
    Size2D getSize();

protected:

private:
    Position2D position;
    Size2D size;
};

#endif // OBSTACLE_H
