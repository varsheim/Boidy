#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QtWidgets>
/*!
 * \brief The Algorithm class. Contains parameters used in program calculations.
 * All the variables describe behavior of boids, predators etc.
 */
class Algorithm
{
public:
    /*!
     * \brief Contructor of the class, is never called since there is no object of Algorithm class
     */
    Algorithm();
    /*!
     * \brief Initial amount of Boid objects
     */
    static const int onStartBoidQuantity;
    /*!
     * \brief Initial amount of Predator objects
     */
    static const int onStartPredatorQuantity;
    /*!
     * \brief Initial amount of Obstacle objects
     */
    static const int onStartObstacleQuantity;
    /*!
     * \brief Initial X position of boids & predators swarm
     */
    static const float startXPos;
    /*!
     * \brief Initial Y position of boids & predators swarm
     */
    static const float startYPos;
    /*!
     * \brief Initial X velocity of boids & predators
     */
    static const float startXVelo;
    /*!
     * \brief Initial Y velocity of boids & predators
     */
    static const float startYVelo;
    /*!
     * \brief Method which initializes QTimer (used to calculate everything) and seeds the qsrand() - to initialy draw obstacles in random places
     */
    static void initialize();
    /*!
     * \brief Getter of onStartBoidQuantity
     * \return int value of onStartBoidQuantity
     */
    static int getOnStartBoidQuantity();

    /*!
     * \brief Getter of onStartPredatorQuantity
     * \return int value of onStartPredatorQuantity
     */
    static int getOnStartPredatorQuantity();
    /*!
     * \brief Getter of onStartObstacleQuantity
     * \return int value of onStartObstacleQuantity
     */
    static int getOnStartObstacleQuantity();

    //gettery i settery parametrow boida
    /*!
     * \brief Getter of neighboursVelocityFitFactor
     * \return float value of neighboursVelocityFitFactor
     */
    static float getNeighboursVelocityFitFactor();
    /*!
     * \brief Getter of neighboursGroupFitFactor
     * \return float value of neighboursGroupFitFactor
     */
    static float getNeighboursGroupFitFactor();
    /*!
     * \brief Getter of neighboursMinDistanceFactor
     * \return float value of neighboursMinDistanceFactor
     */
    static float getNeighboursMinDistanceFactor();
    /*!
     * \brief Getter of minDistance
     * \return float value of minDistance
     */
    static float getMinDistance();
    /*!
     * \brief Getter of predatorMinDistance
     * \return float value of predatorMinDistance
     */
    static float getPredatorMinDistance();
    /*!
     * \brief Getter of predatorMinDistanceFactor
     * \return float value of predatorMinDistanceFactor
     */
    static float getPredatorMinDistanceFactor();
    /*!
     * \brief Getter of predatorSightDistance
     * \return float value of predatorSightDistance
     */
    static float getPredatorSightDistance();
    /*!
     * \brief Getter of predatorSightAngle
     * \return float value of predatorSightAngle
     */
    static float getPredatorSightAngle();
    /*!
     * \brief Getter of boidMaxVelocity
     * \return float value of boidMaxVelocity
     */
    static float getBoidMaxVelocity();
    /*!
     * \brief Getter of boidSightDistance
     * \return float value of boidSightDistance
     */
    static float getBoidSightDistance();

    /*!
     * \brief Setter of neighboursVelocityFitFactor
     * \param value float value to set neighboursVelocityFitFactor
     */
    static void setNeighboursVelocityFitFactor(float value);
    /*!
     * \brief Setter of neighboursGroupFitFactor
     * \param value float value to set neighboursGroupFitFactor
     */
    static void setNeighboursGroupFitFactor(float value);
    /*!
     * \brief Setter of neighboursMinDistanceFactor
     * \param value float value to set neighboursMinDistanceFactor
     */
    static void setNeighboursMinDistanceFactor(float value);
    /*!
     * \brief Setter of minDistance
     * \param value float value to set minDistance
     */
    static void setMinDistance(float value);
    /*!
     * \brief Setter of predatorMinDistance
     * \param value float value to set predatorMinDistance
     */
    static void setPredatorMinDistance(float value);
    /*!
     * \brief Setter of predatorMinDistanceFactor
     * \param value float value to set predatorMinDistanceFactor
     */
    static void setPredatorMinDistanceFactor(float value);
    /*!
     * \brief Setter of predatorSightDistance
     * \param value float value to set predatorSightDistance
     */
    static void setPredatorSightDistance(float value);
    /*!
     * \brief Setter of predatorSightAngle
     * \param value float value to set predatorSightAngle
     */
    static void setPredatorSightAngle(float value);
    /*!
     * \brief Setter of boidMaxVelocity
     * \param value float value to set boidMaxVelocity
     */
    static void setBoidMaxVelocity(float value);
    /*!
     * \brief Setter of boidSightDistance
     * \param value float value to set boidSightDistance
     */
    static void setBoidSightDistance(float value);

    //gettery i settery parametrow predatora
    /*!
     * \brief Getter of isOffensive
     * \return bool value of isOffensive
     */
    static bool getIsOffensive();
    /*!
     * \brief Getter of targetChaseFactor
     * \return float value of targetChaseFactor
     */
    static float getTargetChaseFactor();
    /*!
     * \brief Getter of predatorMaxVelocity
     * \return float value of predatorMaxVelocity
     */
    static float getPredatorMaxVelocity();
    /*!
     * \brief Getter of predatorSelfSightDistance
     * \return float value of predatorSelfSightDistance
     */
    static float getPredatorSelfSightDistance();

    /*!
     * \brief Setter of isOffensive
     * \param value bool value to set isOffensive
     */
    static void setIsOffensive(bool value);
    /*!
     * \brief Setter of targetChaseFactor
     * \param value float value to set targetChaseFactor
     */
    static void setTargetChaseFactor(float value);
    /*!
     * \brief Setter of predatorMaxVelocity
     * \param value float value to set predatorMaxVelocity
     */
    static void setPredatorMaxVelocity(float value);
    /*!
     * \brief Setter of predatorSelfSightDistance
     * \param value float value to set predatorSelfSightDistance
     */
    static void setPredatorSelfSightDistance(float value);

    //gettery i settery parametrow wspolnych
    /*!
     * \brief Getter of maxVelocity
     * \return float value of maxVelocity
     */
    static float getMaxVelocity();
    /*!
     * \brief Getter of sightDistance
     * \return float value of sightDistance
     */
    static float getSightDistance();
    /*!
     * \brief Getter of sightAngle
     * \return float value of sightAngle
     */
    static float getSightAngle();
    /*!
     * \brief Getter of velocityLimitFactor
     * \return float value of velocityLimitFactor
     */
    static float getVelocityLimitFactor();
    /*!
     * \brief Getter of randomFactor
     * \return float value of randomFactor
     */
    static float getRandomFactor();
    /*!
     * \brief Getter of obstacleSightDistance
     * \return float value of obstacleSightDistance
     */
    static float getObstacleSightDistance();
    /*!
     * \brief Getter of obstacleMinDistance
     * \return float value of obstacleMinDistance
     */
    static float getObstacleMinDistance();
    /*!
     * \brief Getter of obstacleMinDistanceFactor
     * \return float value of obstacleMinDistanceFactor
     */
    static float getObstacleMinDistanceFactor();

    /*!
     * \brief Setter of maxVelocity
     * \param value float value to set maxVelocity
     */
    static void setMaxVelocity(float value);
    /*!
     * \brief Setter of sightDistance
     * \param value float value to set sightDistance
     */
    static void setSightDistance(float value);
    /*!
     * \brief Setter of sightAngle
     * \param value float value to set sightAngle
     */
    static void setSightAngle(float value);
    /*!
     * \brief Setter of velocityLimitFactor
     * \param value float value to set velocityLimitFactor
     */
    static void setVelocityLimitFactor(float value);
    /*!
     * \brief Setter of randomFactor
     * \param value float value to set randomFactor
     */
    static void setRandomFactor(float value);
    /*!
     * \brief Setter of obstacleSightDistance
     * \param value float value to set obstacleSightDistance
     */
    static void setObstacleSightDistance(float value);
    /*!
     * \brief Setter of obstacleMinDistance
     * \param value float value to set obstacleMinDistance
     */
    static void setObstacleMinDistance(float value);
    /*!
     * \brief Setter of obstacleMinDistanceFactor
     * \param value float value to set obstacleMinDistanceFactor
     */
    static void setObstacleMinDistanceFactor(float value);

    //timery
    /*!
     * \brief Getter of calculatingDelay
     * \return int value of calculatingDelay
     */
    static int getCalculatingDelay();
    /*!
     * \brief Setter of calculatingDelay
     * \param value int value to set calculatingDelay
     */
    static void setCalculatingDelay(int value);
    /*!
     * \brief Getter of calculatingTimer
     * \return QTimer timer created in Algorithm::initialize()
     */
    static QTimer *getCalculatingTimer();

    //stale przechowujace poczatkowe parametry z ui
    /*!
     * \brief Method setting parameters (available from ui) to default values
     */
    static void setDefaultParameters();
    /*!
     * \brief Default value of minDistance
     */
    static const float defaultMinDistance;
    /*!
     * \brief Default value of boidMaxVelocity
     */
    static const float defaultBoidMaxVelocity;
    /*!
     * \brief Default value of boidSightDistance
     */
    static const float defaultBoidSightDistance;
    /*!
     * \brief Default value of sightAngle
     */
    static const float defaultSightAngle;
    /*!
     * \brief Default value of neighboursVelocityFitFactor
     */
    static const float defaultNeighboursVelocityFitFactor;
    /*!
     * \brief Default value of neighboursGroupFitFactor
     */
    static const float defaultNeighboursGroupFitFactor;
    /*!
     * \brief Default value of neighboursMinDistanceFactor
     */
    static const float defaultNeighboursMinDistanceFactor;
    /*!
     * \brief Default value of predatorMinDistanceFactor
     */
    static const float defaultPredatorMinDistanceFactor;
    /*!
     * \brief Default value of randomFactor
     */
    static const float defaultRandomFactor;
    /*!
     * \brief Default value of obstacleMinDistance
     */
    static const float defaultObstacleMinDistance;
    /*!
     * \brief Default value of predatorMaxVelocity
     */
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
