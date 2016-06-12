#include "algorithm.h"
#include "mainwindow.h"
#include <cstdio>
#include <ctime>



Algorithm::Algorithm()
    :onStartBoidQuantity(20),
     onStartPredatorQuantity(1),
     onStartObstacleQuantity(5),
     startXPos(0.002),
     startYPos(0.002),
     startXVelo(0.05),
     startYVelo(0.05),

     //default
     defaultMinDistance(0.20),
     defaultBoidMaxVelocity(0.20),
     defaultBoidSightDistance(0.75),
     defaultSightAngle(0.7 * 3.1416),
     defaultNeighboursVelocityFitFactor(0.02),
     defaultNeighboursGroupFitFactor(0.005),
     defaultNeighboursMinDistanceFactor(0.005),
     defaultPredatorMinDistanceFactor(0.04),
     defaultRandomFactor(0.08),
     defaultObstacleMinDistance(0.15),
     defaultPredatorMaxVelocity(0.25)
{
    //parametry boida
    neighboursVelocityFitFactor = 0.02;
    neighboursGroupFitFactor = 0.005;
    neighboursMinDistanceFactor = 0.005;
    minDistance = 0.20;
    predatorMinDistance = 1.0;
    predatorMinDistanceFactor = 0.04;
    predatorSightDistance = 1.0;
    predatorSightAngle = 1 * 3.1416; //360 stopni
    boidMaxVelocity = 0.20;
    boidSightDistance = 0.75;

    //parametry predatora
    isOffensive = true;
    targetChaseFactor = 0.02;
    predatorMaxVelocity = 0.25;
    predatorSelfSightDistance = 2;

    //parametry wspolne
    sightAngle = 0.7 * 3.1416;
    velocityLimitFactor = 0.80;
    randomFactor = 0.08;
    obstacleSightDistance = 0.50;
    obstacleMinDistance = 0.15;
    obstacleMinDistanceFactor = 0.003;

    //timery
    calculatingDelay = 10;
    calculatingTimer = new QTimer();
}

void Algorithm::initialize()
{
    calculatingTimer->start(calculatingDelay);
    qsrand(time(NULL));
}

void Algorithm::setDefaultParameters()
{
    minDistance = defaultMinDistance;
    boidMaxVelocity = defaultBoidMaxVelocity;
    boidSightDistance = defaultBoidSightDistance;
    sightAngle = defaultSightAngle;
    neighboursVelocityFitFactor = defaultNeighboursVelocityFitFactor;
    neighboursGroupFitFactor = defaultNeighboursGroupFitFactor;
    neighboursMinDistanceFactor = defaultNeighboursMinDistanceFactor;
    predatorMinDistanceFactor = defaultPredatorMinDistanceFactor;
    randomFactor = defaultRandomFactor;
    obstacleMinDistance = defaultObstacleMinDistance;
    predatorMaxVelocity = defaultPredatorMaxVelocity;
}

float Algorithm::getNeighboursVelocityFitFactor()
{
    return neighboursVelocityFitFactor;
}

float Algorithm::getNeighboursGroupFitFactor()
{
    return neighboursGroupFitFactor;
}

float Algorithm::getNeighboursMinDistanceFactor()
{
    return neighboursMinDistanceFactor;
}

float Algorithm::getMinDistance()
{
    return minDistance;
}

float Algorithm::getPredatorMinDistance()
{
    return predatorMinDistance;
}

float Algorithm::getPredatorMinDistanceFactor()
{
    return predatorMinDistanceFactor;
}

float Algorithm::getPredatorSightDistance()
{
    return predatorSightDistance;
}

float Algorithm::getPredatorSightAngle()
{
    return predatorSightAngle;
}

void Algorithm::setNeighboursVelocityFitFactor(float value)
{
    neighboursVelocityFitFactor = value;
}

void Algorithm::setNeighboursGroupFitFactor(float value)
{
    neighboursGroupFitFactor = value;
}

void Algorithm::setNeighboursMinDistanceFactor(float value)
{
    neighboursMinDistanceFactor = value;
}

void Algorithm::setMinDistance(float value)
{
    minDistance = value;
}

void Algorithm::setPredatorMinDistance(float value)
{
    predatorMinDistance = value;
}

void Algorithm::setPredatorMinDistanceFactor(float value)
{
    predatorMinDistanceFactor = value;
}

void Algorithm::setPredatorSightDistance(float value)
{
    predatorSightDistance = value;
}

void Algorithm::setPredatorSightAngle(float value)
{
    predatorSightAngle = value;
}

bool Algorithm::getIsOffensive()
{
    return isOffensive;
}

void Algorithm::setIsOffensive(bool value)
{
    isOffensive = value;
}

float Algorithm::getTargetChaseFactor()
{
    return targetChaseFactor;
}

void Algorithm::setTargetChaseFactor(float value)
{
    targetChaseFactor = value;
}

float Algorithm::getSightAngle()
{
    return sightAngle;
}

void Algorithm::setSightAngle(float value)
{
    sightAngle = value;
}

float Algorithm::getVelocityLimitFactor()
{
    return velocityLimitFactor;
}

void Algorithm::setVelocityLimitFactor(float value)
{
    velocityLimitFactor = value;
}

float Algorithm::getRandomFactor()
{
    return randomFactor;
}

void Algorithm::setRandomFactor(float value)
{
    randomFactor = value;
}

float Algorithm::getObstacleSightDistance()
{
    return obstacleSightDistance;
}

void Algorithm::setObstacleSightDistance(float value)
{
    obstacleSightDistance = value;
}

float Algorithm::getObstacleMinDistance()
{
    return obstacleMinDistance;
}

void Algorithm::setObstacleMinDistance(float value)
{
    obstacleMinDistance = value;
}

float Algorithm::getObstacleMinDistanceFactor()
{
    return obstacleMinDistanceFactor;
}

void Algorithm::setObstacleMinDistanceFactor(float value)
{
    obstacleMinDistanceFactor = value;
}

int Algorithm::getCalculatingDelay()
{
    return calculatingDelay;
}

void Algorithm::setCalculatingDelay(int value)
{
    calculatingDelay = value;
}

QTimer *Algorithm::getCalculatingTimer()
{
    return calculatingTimer;
}

int Algorithm::getOnStartBoidQuantity()
{
    return onStartBoidQuantity;
}

int Algorithm::getOnStartPredatorQuantity()
{
    return onStartPredatorQuantity;
}

int Algorithm::getOnStartObstacleQuantity()
{
    return onStartObstacleQuantity;
}

float Algorithm::getPredatorMaxVelocity()
{
    return predatorMaxVelocity;
}

void Algorithm::setPredatorMaxVelocity(float value)
{
    predatorMaxVelocity = value;
}

float Algorithm::getPredatorSelfSightDistance()
{
    return predatorSelfSightDistance;
}

void Algorithm::setPredatorSelfSightDistance(float value)
{
    predatorSelfSightDistance = value;
}

float Algorithm::getBoidMaxVelocity()
{
    return boidMaxVelocity;
}

void Algorithm::setBoidMaxVelocity(float value)
{
    boidMaxVelocity = value;
}

float Algorithm::getBoidSightDistance()
{
    return boidSightDistance;
}

void Algorithm::setBoidSightDistance(float value)
{
    boidSightDistance = value;
}

