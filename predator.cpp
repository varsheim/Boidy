#include "predator.h"
#include "boid.h"
#include "algorithm.h"

Predator::Predator(Position2D position, Velocity2D velocity)
{
    size = 12;
    width = 5;
    length = 0.07;

    this->position = position;
    this->velocity = velocity;
    futureVelocity = velocity;
}

Predator::~Predator()
{

}

Boid* Predator::findTarget(QList<Boid *> *allBoids)
{
    static float tempDistance, tempVelocityAngle, tempNeighbourAngle, tempSightAngle, minTempDistance;
    Position2D positionDifference;

    //wstepne przypisanie targetBoid i minTempDistance zeby mozna bylo potem porownywac jego wartosc

    targetBoid = allBoids->at(1);
    positionDifference = allBoids->at(1)->getPosition() - position;
    minTempDistance = qSqrt(qPow(positionDifference.x, 2) +
                            qPow(positionDifference.y, 2));

    for (int i = 0; i < allBoids->length(); i++){ //przelot po wszystkich boidach
        //obliczenie odleglosci do kolejnego Boida
        positionDifference = allBoids->at(i)->getPosition() - position;
        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));

        if(tempDistance < Algorithm::getInstance().getPredatorSelfSightDistance()){
            //jesli boid jest w promieniu mniejszym od sightDistance
            //sprawdzam dalej czy boid znajduje sie w kacie widzenia
            tempVelocityAngle = qAtan2(velocity.yVelocity, velocity.xVelocity);
            tempNeighbourAngle = qAtan2(positionDifference.y, positionDifference.x);
            tempSightAngle = qAbs(tempVelocityAngle - tempNeighbourAngle);
            if(tempSightAngle < Algorithm::getInstance().getSightAngle()){
                //jesli boid jest najblizej w sasiedztwie to namierz go
                if(tempDistance <= minTempDistance){
                    targetBoid = allBoids->at(i);
                    minTempDistance = tempDistance;
                }
            }
        }
    }


    targetBoidDistance = minTempDistance;
    return targetBoid;
}

void Predator::calculateVelocityBasedOnTarget(Velocity2D &futureVelocity)
{
    static Position2D positionDifference;
    positionDifference = targetBoid->getPosition() - position;

    futureVelocity += positionDifference * Algorithm::getInstance().getTargetChaseFactor();
}

Velocity2D Predator::calculateVelocity()
{
    // *** PREDATOR GONI NAJBLIZSZEGO BOIDA ***
    calculateVelocityBasedOnTarget(futureVelocity);

    // *** PREDATOR OMIJA PRZESZKODY ***
    calculateVelocityBasedOnObstacles(futureVelocity);

    // *** LOSOWE ZAKLOCENIA ***
    addRandomNoise(futureVelocity, Algorithm::getInstance().getPredatorMaxVelocity());

    // *** OGRANICZ PREDKOSC ***
    checkMaxVelocity(Algorithm::getInstance().getPredatorMaxVelocity());

    return velocity;
}
