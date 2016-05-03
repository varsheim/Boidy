#include "creature.h"
#include "environment.h"

Creature::Creature()
{

}

Creature::~Creature()
{

}

void Creature::setSize(float size)
{
    this->size = size;
}

void Creature::setLength(float length)
{
    this->length = length;
}

void Creature::setWidth(float width)
{
    this->width = width;
}

float Creature::getSize()
{
    return size;
}

float Creature::getLength()
{
    return length;
}

float Creature::getWidth()
{
    return width;
}

Position2D Creature::getPosition()
{
    return position;
}

Velocity2D Creature::getVelocity()
{
    return velocity;
}

void Creature::updatePosition(int height, int width)
{
    this->position.x += 0.1*this->velocity.xVelocity;
    this->position.y += 0.1*this->velocity.yVelocity;

    checkBorders(height, width);
}

void Creature::checkBorders(int height, int width)
{
    if(position.x > width/300) position.x = -width/300;
    if(position.x < -width/300) position.x = width/300;
    if(position.y > height/300) position.y = -height/300;
    if(position.y < -height/300) position.y = height/300;
}

float Creature::getVelocityAngle()
{
    return qAtan2(velocity.yVelocity, velocity.xVelocity);
}

void Creature::checkMaxVelocity()
{
    actualVelocity = qSqrt(qPow(futureVelocity.xVelocity, 2) +
                           qPow(futureVelocity.yVelocity, 2));

    if(actualVelocity >= maxVelocity){
        futureVelocity = futureVelocity * velocityLimitFactor;
    }
}

void Creature::addRandomNoise(Velocity2D &futureVelocity)
{
    futureVelocity.xVelocity += randomFactor * (qrand() % 200 - 100) * maxVelocity / 200;
    futureVelocity.yVelocity += randomFactor * (qrand() % 200 - 100) * maxVelocity / 200;
}

void Creature::updateVelocity()
{
    velocity = futureVelocity;
}
