#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "typedefs.h"

class Obstacle
{
public:
    Obstacle(Position2D position);
    ~Obstacle();

    Position2D getPosition();
    Size2D getSize();

    void setPosition(Position2D);
    void setSize(Size2D);

protected:

private:
    Position2D position;
    Size2D size;
};

#endif // OBSTACLE_H
