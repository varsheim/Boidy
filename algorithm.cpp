#include "algorithm.h"
#include "mainwindow.h"
#include <cstdio>
#include <ctime>

const int Algorithm::onStartBoidQuantity = 20;
const int Algorithm::onStartPredatorQuantity = 2;
const int Algorithm::onStartObstacleQuantity = 5;
const float Algorithm::startXPos = 0.002;
const float Algorithm::startYPos = 0.002;
const float Algorithm::startXVelo = 0.05;
const float Algorithm::startYVelo = 0.05;

//parametry boida
float Algorithm::neighboursVelocityFitFactor = 0.02;
float Algorithm::neighboursGroupFitFactor = 0.005;
float Algorithm::neighboursMinDistanceFactor = 0.005;
float Algorithm::minDistance = 0.20;
float Algorithm::predatorMinDistance = 1.0;
float Algorithm::predatorMinDistanceFactor = 0.04;
float Algorithm::predatorSightDistance = 1.0;
float Algorithm::predatorSightAngle = 1 * 3.1416; //360 stopni
float Algorithm::boidMaxVelocity = 0.20;
float Algorithm::boidSightDistance = 0.75;

//parametry predatora
bool Algorithm::isOffensive = true;
float Algorithm::targetChaseFactor = 0.02;
float Algorithm::predatorMaxVelocity = 0.25;
float Algorithm::predatorSelfSightDistance = 2;

//parametry wspolne
float Algorithm::sightAngle = 0.7 * 3.1416;
float Algorithm::velocityLimitFactor = 0.80;
float Algorithm::randomFactor = 0.08;
float Algorithm::obstacleSightDistance = 0.50;
float Algorithm::obstacleMinDistance = 0.15;
float Algorithm::obstacleMinDistanceFactor = 0.003;

//timery
int Algorithm::calculatingDelay = 10;
QTimer *Algorithm::calculatingTimer = new QTimer();

//default
const float Algorithm::defaultMinDistance = 0.20;
const float Algorithm::defaultBoidMaxVelocity = 0.20;
const float Algorithm::defaultBoidSightDistance = 0.75;
const float Algorithm::defaultSightAngle = 0.7 * 3.1416;
const float Algorithm::defaultNeighboursVelocityFitFactor = 0.02;
const float Algorithm::defaultNeighboursGroupFitFactor = 0.005;
const float Algorithm::defaultNeighboursMinDistanceFactor = 0.005;
const float Algorithm::defaultPredatorMinDistanceFactor = 0.04;
const float Algorithm::defaultRandomFactor = 0.08;
const float Algorithm::defaultObstacleMinDistance = 0.15;
const float Algorithm::defaultPredatorMaxVelocity = 0.25;

Algorithm::Algorithm()
{

}

void Algorithm::initialize()
{
    Algorithm::calculatingTimer->start(Algorithm::calculatingDelay);
    qsrand(time(NULL));
}

void Algorithm::setDefaultParameters()
{
    Algorithm::minDistance = Algorithm::defaultMinDistance;
    Algorithm::boidMaxVelocity = Algorithm::defaultBoidMaxVelocity;
    Algorithm::boidSightDistance = Algorithm::defaultBoidSightDistance;
    Algorithm::sightAngle = Algorithm::defaultSightAngle;
    Algorithm::neighboursVelocityFitFactor = Algorithm::defaultNeighboursVelocityFitFactor;
    Algorithm::neighboursGroupFitFactor = Algorithm::defaultNeighboursGroupFitFactor;
    Algorithm::neighboursMinDistanceFactor = Algorithm::defaultNeighboursMinDistanceFactor;
    Algorithm::predatorMinDistanceFactor = Algorithm::defaultPredatorMinDistanceFactor;
    Algorithm::randomFactor = Algorithm::defaultRandomFactor;
    Algorithm::obstacleMinDistance = Algorithm::defaultObstacleMinDistance;
    Algorithm::predatorMaxVelocity = Algorithm::defaultPredatorMaxVelocity;
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

