#include "obstacle.h"

Obstacle::Obstacle(Position2D position)
{
    this->position = position;

    this->size.xSize = 0.04;
    this->size.ySize = 0.04;
}

Obstacle::~Obstacle()
{

}

Position2D Obstacle::getPosition()
{
    return position;
}

Size2D Obstacle::getSize()
{
    return size;
}
