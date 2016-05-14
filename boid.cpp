#include <QList>
#include <QtCore/qmath.h>

#include "boid.h"
#include "predator.h"
#include "environment.h"

Boid::Boid(Position2D position, Velocity2D velocity)
{
    neighbours = new QList<Boid *>;
    closePredators = new QList<Predator *>;

    size = 10;
    width = 4;
    length = 0.07;

    this->position = position;
    this->velocity = velocity;
    futureVelocity = velocity;
    neighboursAverageVelocity.xVelocity = 0;
    neighboursAverageVelocity.yVelocity = 0;
    neighboursAverageDistance = 0;
    sightDistance = 0.75; //wymiary mapy to 4x4!!!!!!
    sightAngle = 0.7 * 3.1416; //kat widzenia, 1*3.14 - 360 stopni (bo liczony jest oddzielnie w obie strony po 180 stopni
    predatorSightDistance = 1.0;
    predatorSightAngle = 1 * 3.1416; //360 stopni

    neighboursVelocityFitFactor = 0.02;
    neighboursGroupFitFactor = 0.005;
    neighboursMinDistanceFactor = 0.005;
    minDistance = 0.20;
    predatorMinDistanceFactor = 0.04;
    predatorMinDistance = 1.0;
    maxVelocity = 0.20;
    velocityLimitFactor = 0.80;
    randomFactor = 0.08;
}

Boid::~Boid()
{
    delete neighbours;
    delete closePredators;
}

QList<Boid *> Boid::getNeighbours()
{
    return *neighbours;
}

QList<Predator *> Boid::getClosePredators()
{
    return *closePredators;
}

int Boid::getNeighboursAmount()
{
    return neighbours->length();
}

Velocity2D Boid::getNeighboursAverageVelocity()
{
    return neighboursAverageVelocity;
}

QList<Boid *> Boid::findNeighbours(QList<Boid *> *allBoids)
{
    neighbours->clear(); //wyczyszczenie przed nowym przeliczeniem
    static float tempDistance, tempVelocityAngle, tempNeighbourAngle, tempSightAngle;
    Position2D positionDifference;

    for (int i = 0; i < allBoids->length(); i++){ //przelot po wszystkich boidach, wyznaczenie sasiadow
        if(allBoids->at(i) == this){ //pomijanie samego siebie
            continue;
        }
        //obliczenie odleglosci do kolejnego Boida
        positionDifference = allBoids->at(i)->position - position;
        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));
        if(tempDistance < sightDistance){
            //jesli boid jest w promieniu rownym sightDistance
            //sprawdzam dalej czy boid znajduje sie w kacie widzenia
            tempVelocityAngle = qAtan2(velocity.yVelocity, velocity.xVelocity);
            tempNeighbourAngle = qAtan2(positionDifference.y, positionDifference.x);
            tempSightAngle = qAbs(tempVelocityAngle - tempNeighbourAngle);
            if(tempSightAngle < sightAngle){
                neighbours->append(allBoids->at(i));
            }
        }
    }

    return *neighbours;
}

QList<Predator *> Boid::findPredators(QList<Predator *> *allPredators)
{
    closePredators->clear();
    static float tempDistance, tempVelocityAngle, tempNeighbourAngle, tempSightAngle;
    Position2D positionDifference;

    for (int i = 0; i < allPredators->length(); i++){ //przelot po wszystkich predatorach, wyznaczenie bliskich predatorow
        //obliczenie odleglosci do kolejnego Predatora
        positionDifference = allPredators->at(i)->getPosition() - position;
        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));
        if(tempDistance < predatorSightDistance){
            //jesli Predator jest w promieniu rownym sightDistance
            //sprawdzam dalej czy Predator znajduje sie w kacie widzenia
            tempVelocityAngle = qAtan2(velocity.yVelocity, velocity.xVelocity);
            tempNeighbourAngle = qAtan2(positionDifference.y, positionDifference.x);
            tempSightAngle = qAbs(tempVelocityAngle - tempNeighbourAngle);
            if(tempSightAngle < predatorSightAngle){
                closePredators->append(allPredators->at(i));
            }
        }
    }

    return *closePredators;
}

Velocity2D Boid::calculateNeighboursAverageVelocity()
{
    neighboursAverageVelocity = 0;

    if(neighbours->isEmpty()){
        return neighboursAverageVelocity;
    }

    for(int i = 0; i < neighbours->length(); i++){
        neighboursAverageVelocity += neighbours->at(i)->getVelocity();
    }

    neighboursAverageVelocity = neighboursAverageVelocity / neighbours->length();

    return neighboursAverageVelocity;
}

void Boid::calculateNeighboursAverageDistance()
{
    neighboursAverageDistance = 0;

    if(neighbours->isEmpty()){
        return;
    }

    static float tempDist = 0;
    Position2D positionDifference;

    for(int i = 0; i < neighbours->length(); i++){
        positionDifference = position - neighbours->at(i)->position;
        tempDist = qSqrt(qPow(positionDifference.x, 2) +
                         qPow(positionDifference.y, 2));
        neighboursAverageDistance += tempDist;
    }
    neighboursAverageDistance = neighboursAverageDistance / neighbours->length();

}

void Boid::calculateVelocityBasedOnVelocity(Velocity2D &futureVelocity,
                                            Velocity2D neighboursVelocity,
                                            Velocity2D currentVelocity)
{
    if(neighbours->isEmpty()){
        return;
    }

    futureVelocity += (neighboursVelocity - currentVelocity) * neighboursVelocityFitFactor;
}

void Boid::calculateVelocityBasedOnPosition(Velocity2D &futureVelocity)
{
    if(neighbours->isEmpty()){
        return;
    }

    for(int i = 0; i < neighbours->length(); i++){
        Position2D neighbourPosition = neighbours->at(i)->position;
        Position2D positionDifference;
        positionDifference = neighbourPosition - position; //przeciazony operator odejmowania

        static float tempDistance = 0;

        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));

        float neighbourDistanceCoefficient = (tempDistance - neighboursAverageDistance) / tempDistance;

        futureVelocity += (positionDifference * neighbourDistanceCoefficient) * neighboursGroupFitFactor;
    }
}

void Boid::calculateVelocityBasedOnDistance(Velocity2D &futureVelocity)
{
    if(neighbours->isEmpty()) {
        return;
    }

    for(int i = 0; i < neighbours->length(); i++) {
        Position2D neighbourPosition = neighbours->at(i)->position;
        Position2D positionDifference;
        positionDifference = neighbourPosition - position; //przeciazony operator odejmowania

        static float tempDistance = 0;

        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));
        float distanceRatio = minDistance / tempDistance;

        futureVelocity -= positionDifference * neighboursMinDistanceFactor * (distanceRatio - 1); //przeciazone operatory
    }
}

void Boid::calculateVelocityBasedOnPredators(Velocity2D &futureVelocity)
{
    if(closePredators->isEmpty()){
        return;
    }

    for(int i = 0; i < closePredators->length(); i++) {
        Position2D closePredatorPosition = closePredators->at(i)->getPosition();
        Position2D positionDifference;
        positionDifference = closePredatorPosition - position; //przeciazony operator odejmowania

        static float tempDistance;

        tempDistance = qSqrt(qPow(positionDifference.x, 2) +
                             qPow(positionDifference.y, 2));
        float distanceRatio = predatorMinDistance / tempDistance;

        futureVelocity -= positionDifference * predatorMinDistanceFactor * (distanceRatio - 1); //przeciazone operatory
    }
}

Velocity2D Boid::calculateVelocity()
{
    //obliczam srednia predkosc sasiadow (oddzielnie x, y)
    calculateNeighboursAverageVelocity();

    //*** DOPASOWANIE PREDKOSCI BOIDA DO PREDKOSCI SASIADOW ***
    calculateVelocityBasedOnVelocity(futureVelocity,
                                     neighboursAverageVelocity,
                                     velocity);

    //*** KAŻDY BOID STARA SIĘ BYĆ W ŚRODKU GRUPY BOIDÓW ***
    calculateNeighboursAverageDistance();
    calculateVelocityBasedOnPosition(futureVelocity);

    //*** KAŻDY BOID ZACHOWUJE BEZPIECZNĄ MINIMALNĄ ODLEGŁOŚĆ OD SĄSIADÓW ***
    calculateVelocityBasedOnDistance(futureVelocity);

    //*** BOIDY UCIEKAJA OD PREDATOROW ***
    calculateVelocityBasedOnPredators(futureVelocity);

    //*** BOIDY OMIJAJA PRZESZKODY ***
    calculateVelocityBasedOnObstacles(futureVelocity);

    //*** LOSOWE ZAKLOCENIA ***
    addRandomNoise(futureVelocity);

    //*** OGRANICZ PREDKOSC ***
    checkMaxVelocity();

    return velocity;
}

