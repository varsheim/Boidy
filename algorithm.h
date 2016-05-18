#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QtWidgets>

class Algorithm
{
public:
    Algorithm();

    static const int onStartBoidQuantity;
    static const int onStartPredatorQuantity;
    static const int onStartObstacleQuantity;
    static const float startXPos;
    static const float startYPos;
    static const float startXVelo;
    static const float startYVelo;

    static void initialize();
    static int getOnStartBoidQuantity();
    static int getOnStartPredatorQuantity();
    static int getOnStartObstacleQuantity();

    //gettery i settery parametrow boida
    static float getNeighboursVelocityFitFactor();
    static float getNeighboursGroupFitFactor();
    static float getNeighboursMinDistanceFactor();
    static float getMinDistance();
    static float getPredatorMinDistance();
    static float getPredatorMinDistanceFactor();
    static float getPredatorSightDistance();
    static float getPredatorSightAngle();
    static float getBoidMaxVelocity();
    static float getBoidSightDistance();

    static void setNeighboursVelocityFitFactor(float value);
    static void setNeighboursGroupFitFactor(float value);
    static void setNeighboursMinDistanceFactor(float value);
    static void setMinDistance(float value);
    static void setPredatorMinDistance(float value);
    static void setPredatorMinDistanceFactor(float value);
    static void setPredatorSightDistance(float value);
    static void setPredatorSightAngle(float value);
    static void setBoidMaxVelocity(float value);
    static void setBoidSightDistance(float value);

    //gettery i settery parametrow predatora
    static bool getIsOffensive();
    static float getTargetChaseFactor();
    static float getPredatorMaxVelocity();
    static float getPredatorSelfSightDistance();

    static void setIsOffensive(bool value);
    static void setTargetChaseFactor(float value);
    static void setPredatorMaxVelocity(float value);
    static void setPredatorSelfSightDistance(float value);

    //gettery i settery parametrow wspolnych
    static float getMaxVelocity();
    static float getSightDistance();
    static float getSightAngle();
    static float getVelocityLimitFactor();
    static float getRandomFactor();
    static float getObstacleSightDistance();
    static float getObstacleMinDistance();
    static float getObstacleMinDistanceFactor();

    static void setMaxVelocity(float value);
    static void setSightDistance(float value);
    static void setSightAngle(float value);
    static void setVelocityLimitFactor(float value);
    static void setRandomFactor(float value);
    static void setObstacleSightDistance(float value);
    static void setObstacleMinDistance(float value);
    static void setObstacleMinDistanceFactor(float value);

    //timery
    static int getCalculatingDelay();
    static void setCalculatingDelay(int value);
    static QTimer *getCalculatingTimer();

    //stale przechowujace poczatkowe parametry z ui
    static void setDefaultParameters();
    static const float defaultMinDistance;
    static const float defaultBoidMaxVelocity;
    static const float defaultBoidSightDistance;
    static const float defaultSightAngle;
    static const float defaultNeighboursVelocityFitFactor;
    static const float defaultNeighboursGroupFitFactor;
    static const float defaultNeighboursMinDistanceFactor;
    static const float defaultPredatorMinDistanceFactor;
    static const float defaultRandomFactor;
    static const float defaultObstacleMinDistance;
    static const float defaultPredatorMaxVelocity;

private:
    //parametry boida
    static float neighboursVelocityFitFactor;
    static float neighboursGroupFitFactor;
    static float neighboursMinDistanceFactor;
    static float minDistance;
    static float predatorMinDistance;
    static float predatorMinDistanceFactor;
    static float predatorSightDistance;
    static float predatorSightAngle;
    static float boidMaxVelocity;
    static float boidSightDistance;


    //parametry predatora
    static bool isOffensive;
    static float targetChaseFactor;
    static float predatorMaxVelocity;
    static float predatorSelfSightDistance;

    //parametry wspolne
    static float sightAngle;
    static float velocityLimitFactor;
    static float randomFactor;
    static float obstacleSightDistance;
    static float obstacleMinDistance;
    static float obstacleMinDistanceFactor;

    //timery
    static int calculatingDelay;
    static QTimer *calculatingTimer;
};

#endif // ALGORITHM_H
