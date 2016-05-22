#include "creature.h"
#include "environment.h"
#include "algorithm.h"

Creature::Creature()
{
    closeObstacles = new QList<Obstacle *>;
}

Creature::~Creature()
{
    delete closeObstacles;
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

QList<Obstacle *> Creature::getCloseObstacles()
{
    return *closeObstacles;
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

void Creature::checkMaxVelocity(float compareMaxVelocity)
{
    actualVelocity = qSqrt(qPow(futureVelocity.xVelocity, 2) +
                           qPow(futureVelocity.yVelocity, 2));

    if(actualVelocity >= compareMaxVelocity){
        int signX;

        if(futureVelocity.xVelocity >= 0){
            signX = 1;
        }
        else{
            signX = -1;
        }

        float velocityCoefficient = futureVelocity.yVelocity / futureVelocity.xVelocity;
        futureVelocity.xVelocity = signX * Algorithm::getVelocityLimitFactor()
                                 * compareMaxVelocity / qSqrt(qPow(velocityCoefficient, 2) + 1);
        futureVelocity.yVelocity = futureVelocity.xVelocity * velocityCoefficient;
    }
}

void Creature::addRandomNoise(Velocity2D &futureVelocity, float compareMaxVelocity)
{
    futureVelocity.xVelocity += Algorithm::getRandomFactor() * (qrand() % 200 - 100) * compareMaxVelocity / 200;
    futureVelocity.yVelocity += Algorithm::getRandomFactor() * (qrand() % 200 - 100) * compareMaxVelocity / 200;
}

void Creature::updateVelocity()
{
    velocity = futureVelocity;
}

QList<Obstacle *> Creature::findObstacles(QList<Obstacle *> *allObstacles)
{
    closeObstacles->clear();
    static float tempDistance, tempVelocityAngle, tempNeighbourAngle, tempSightAngle;
    Position2D positionDifference;

    for (int i = 0; i < allObstacles->length(); i++){ //przelot po wszystkich predatorach, wyznaczenie bliskich predatorow
        //obliczenie odleglosci do kolejnego Predatora
        positionDifference = allObstacles->at(i)->getPosition() - position;
        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));
        if(tempDistance < Algorithm::getObstacleSightDistance()){
            //jesli Predator jest w promieniu rownym sightDistance
            //sprawdzam dalej czy Predator znajduje sie w kacie widzenia
            tempVelocityAngle = qAtan2(velocity.yVelocity, velocity.xVelocity);
            tempNeighbourAngle = qAtan2(positionDifference.y, positionDifference.x);
            tempSightAngle = qAbs(tempVelocityAngle - tempNeighbourAngle);
            if(tempSightAngle < Algorithm::getSightAngle()){
                closeObstacles->append(allObstacles->at(i));
            }
        }
    }

    return *closeObstacles;
}

void Creature::calculateVelocityBasedOnObstacles(Velocity2D &futureVelocity)
{
    if(closeObstacles->isEmpty()) {
        return;
    }

    for(int i = 0; i < closeObstacles->length(); i++) {
        Position2D obstaclePosition = closeObstacles->at(i)->getPosition();
        Position2D positionDifference;
        positionDifference = obstaclePosition - position; //przeciazony operator odejmowania

        static float tempDistance = 0;

        //odleglosc w trzeciej potedze do polepszenia dzialania
        tempDistance = qPow((qPow(positionDifference.x, 2)
                       + qPow(positionDifference.y, 2)), 1.5);
        float distanceRatio = Algorithm::getObstacleMinDistance() / tempDistance;

        futureVelocity -= positionDifference * Algorithm::getObstacleMinDistanceFactor() * (distanceRatio - 1); //przeciazone operatory
    }
}
