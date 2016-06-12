#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QtWidgets>
/*!
 * \brief The Algorithm class. Contains parameters used in program calculations. Singleton pattern is applied to this class
 * All the variables describe behavior of boids, predators etc.
 */
class Algorithm
{
public:
    /*!
     * \brief Returns the only instance of the Algorithm class
     * \return
     */
    static Algorithm& getInstance()
    {
        static Algorithm instance;
        return instance;
    }

    /*!
     * \brief Prohibits copying instances of the Algorithm class
     */
    Algorithm(Algorithm const&) = delete;
    /*!
     * \brief Prohibits assigning Alghorithm instances (to disallow copying instances)
     */
    void operator=(Algorithm const&) = delete;

    /*!
     * \brief Initial amount of Boid objects
     */
    const int onStartBoidQuantity;
    /*!
     * \brief Initial amount of Predator objects
     */
    const int onStartPredatorQuantity;
    /*!
     * \brief Initial amount of Obstacle objects
     */
    const int onStartObstacleQuantity;
    /*!
     * \brief Initial X position of boids & predators swarm
     */
    const float startXPos;
    /*!
     * \brief Initial Y position of boids & predators swarm
     */
    const float startYPos;
    /*!
     * \brief Initial X velocity of boids & predators
     */
    const float startXVelo;
    /*!
     * \brief Initial Y velocity of boids & predators
     */
    const float startYVelo;
    /*!
     * \brief Method which initializes QTimer (used to calculate everything) and seeds the qsrand() - to initialy draw obstacles in random places
     */
    void initialize();
    /*!
     * \brief Getter of onStartBoidQuantity
     * \return int value of onStartBoidQuantity
     */
    int getOnStartBoidQuantity();

    /*!
     * \brief Getter of onStartPredatorQuantity
     * \return int value of onStartPredatorQuantity
     */
    int getOnStartPredatorQuantity();
    /*!
     * \brief Getter of onStartObstacleQuantity
     * \return int value of onStartObstacleQuantity
     */
    int getOnStartObstacleQuantity();

    //gettery i settery parametrow boida
    /*!
     * \brief Getter of neighboursVelocityFitFactor
     * \return float value of neighboursVelocityFitFactor
     */
    float getNeighboursVelocityFitFactor();
    /*!
     * \brief Getter of neighboursGroupFitFactor
     * \return float value of neighboursGroupFitFactor
     */
    float getNeighboursGroupFitFactor();
    /*!
     * \brief Getter of neighboursMinDistanceFactor
     * \return float value of neighboursMinDistanceFactor
     */
    float getNeighboursMinDistanceFactor();
    /*!
     * \brief Getter of minDistance
     * \return float value of minDistance
     */
    float getMinDistance();
    /*!
     * \brief Getter of predatorMinDistance
     * \return float value of predatorMinDistance
     */
    float getPredatorMinDistance();
    /*!
     * \brief Getter of predatorMinDistanceFactor
     * \return float value of predatorMinDistanceFactor
     */
    float getPredatorMinDistanceFactor();
    /*!
     * \brief Getter of predatorSightDistance
     * \return float value of predatorSightDistance
     */
    float getPredatorSightDistance();
    /*!
     * \brief Getter of predatorSightAngle
     * \return float value of predatorSightAngle
     */
    float getPredatorSightAngle();
    /*!
     * \brief Getter of boidMaxVelocity
     * \return float value of boidMaxVelocity
     */
    float getBoidMaxVelocity();
    /*!
     * \brief Getter of boidSightDistance
     * \return float value of boidSightDistance
     */
    float getBoidSightDistance();

    /*!
     * \brief Setter of neighboursVelocityFitFactor
     * \param value float value to set neighboursVelocityFitFactor
     */
    void setNeighboursVelocityFitFactor(float value);
    /*!
     * \brief Setter of neighboursGroupFitFactor
     * \param value float value to set neighboursGroupFitFactor
     */
    void setNeighboursGroupFitFactor(float value);
    /*!
     * \brief Setter of neighboursMinDistanceFactor
     * \param value float value to set neighboursMinDistanceFactor
     */
    void setNeighboursMinDistanceFactor(float value);
    /*!
     * \brief Setter of minDistance
     * \param value float value to set minDistance
     */
    void setMinDistance(float value);
    /*!
     * \brief Setter of predatorMinDistance
     * \param value float value to set predatorMinDistance
     */
    void setPredatorMinDistance(float value);
    /*!
     * \brief Setter of predatorMinDistanceFactor
     * \param value float value to set predatorMinDistanceFactor
     */
    void setPredatorMinDistanceFactor(float value);
    /*!
     * \brief Setter of predatorSightDistance
     * \param value float value to set predatorSightDistance
     */
    void setPredatorSightDistance(float value);
    /*!
     * \brief Setter of predatorSightAngle
     * \param value float value to set predatorSightAngle
     */
    void setPredatorSightAngle(float value);
    /*!
     * \brief Setter of boidMaxVelocity
     * \param value float value to set boidMaxVelocity
     */
    void setBoidMaxVelocity(float value);
    /*!
     * \brief Setter of boidSightDistance
     * \param value float value to set boidSightDistance
     */
    void setBoidSightDistance(float value);

    //gettery i settery parametrow predatora
    /*!
     * \brief Getter of isOffensive
     * \return bool value of isOffensive
     */
    bool getIsOffensive();
    /*!
     * \brief Getter of targetChaseFactor
     * \return float value of targetChaseFactor
     */
    float getTargetChaseFactor();
    /*!
     * \brief Getter of predatorMaxVelocity
     * \return float value of predatorMaxVelocity
     */
    float getPredatorMaxVelocity();
    /*!
     * \brief Getter of predatorSelfSightDistance
     * \return float value of predatorSelfSightDistance
     */
    float getPredatorSelfSightDistance();

    /*!
     * \brief Setter of isOffensive
     * \param value bool value to set isOffensive
     */
    void setIsOffensive(bool value);
    /*!
     * \brief Setter of targetChaseFactor
     * \param value float value to set targetChaseFactor
     */
    void setTargetChaseFactor(float value);
    /*!
     * \brief Setter of predatorMaxVelocity
     * \param value float value to set predatorMaxVelocity
     */
    void setPredatorMaxVelocity(float value);
    /*!
     * \brief Setter of predatorSelfSightDistance
     * \param value float value to set predatorSelfSightDistance
     */
    void setPredatorSelfSightDistance(float value);

    //gettery i settery parametrow wspolnych
    /*!
     * \brief Getter of maxVelocity
     * \return float value of maxVelocity
     */
    float getMaxVelocity();
    /*!
     * \brief Getter of sightDistance
     * \return float value of sightDistance
     */
    float getSightDistance();
    /*!
     * \brief Getter of sightAngle
     * \return float value of sightAngle
     */
    float getSightAngle();
    /*!
     * \brief Getter of velocityLimitFactor
     * \return float value of velocityLimitFactor
     */
    float getVelocityLimitFactor();
    /*!
     * \brief Getter of randomFactor
     * \return float value of randomFactor
     */
    float getRandomFactor();
    /*!
     * \brief Getter of obstacleSightDistance
     * \return float value of obstacleSightDistance
     */
    float getObstacleSightDistance();
    /*!
     * \brief Getter of obstacleMinDistance
     * \return float value of obstacleMinDistance
     */
    float getObstacleMinDistance();
    /*!
     * \brief Getter of obstacleMinDistanceFactor
     * \return float value of obstacleMinDistanceFactor
     */
    float getObstacleMinDistanceFactor();

    /*!
     * \brief Setter of maxVelocity
     * \param value float value to set maxVelocity
     */
    void setMaxVelocity(float value);
    /*!
     * \brief Setter of sightDistance
     * \param value float value to set sightDistance
     */
    void setSightDistance(float value);
    /*!
     * \brief Setter of sightAngle
     * \param value float value to set sightAngle
     */
    void setSightAngle(float value);
    /*!
     * \brief Setter of velocityLimitFactor
     * \param value float value to set velocityLimitFactor
     */
    void setVelocityLimitFactor(float value);
    /*!
     * \brief Setter of randomFactor
     * \param value float value to set randomFactor
     */
    void setRandomFactor(float value);
    /*!
     * \brief Setter of obstacleSightDistance
     * \param value float value to set obstacleSightDistance
     */
    void setObstacleSightDistance(float value);
    /*!
     * \brief Setter of obstacleMinDistance
     * \param value float value to set obstacleMinDistance
     */
    void setObstacleMinDistance(float value);
    /*!
     * \brief Setter of obstacleMinDistanceFactor
     * \param value float value to set obstacleMinDistanceFactor
     */
    void setObstacleMinDistanceFactor(float value);

    //timery
    /*!
     * \brief Getter of calculatingDelay
     * \return int value of calculatingDelay
     */
    int getCalculatingDelay();
    /*!
     * \brief Setter of calculatingDelay
     * \param value int value to set calculatingDelay
     */
    void setCalculatingDelay(int value);
    /*!
     * \brief Getter of calculatingTimer
     * \return QTimer timer created in Algorithm::initialize()
     */
    QTimer *getCalculatingTimer();

    //stale przechowujace poczatkowe parametry z ui
    /*!
     * \brief Method setting parameters (available from ui) to default values
     */
    void setDefaultParameters();
    /*!
     * \brief Default value of minDistance
     */
    const float defaultMinDistance;
    /*!
     * \brief Default value of boidMaxVelocity
     */
    const float defaultBoidMaxVelocity;
    /*!
     * \brief Default value of boidSightDistance
     */
    const float defaultBoidSightDistance;
    /*!
     * \brief Default value of sightAngle
     */
    const float defaultSightAngle;
    /*!
     * \brief Default value of neighboursVelocityFitFactor
     */
    const float defaultNeighboursVelocityFitFactor;
    /*!
     * \brief Default value of neighboursGroupFitFactor
     */
    const float defaultNeighboursGroupFitFactor;
    /*!
     * \brief Default value of neighboursMinDistanceFactor
     */
    const float defaultNeighboursMinDistanceFactor;
    /*!
     * \brief Default value of predatorMinDistanceFactor
     */
    const float defaultPredatorMinDistanceFactor;
    /*!
     * \brief Default value of randomFactor
     */
    const float defaultRandomFactor;
    /*!
     * \brief Default value of obstacleMinDistance
     */
    const float defaultObstacleMinDistance;
    /*!
     * \brief Default value of predatorMaxVelocity
     */
    const float defaultPredatorMaxVelocity;

private:
    //prywatny konstruktor
    Algorithm();

    //parametry boida
    float neighboursVelocityFitFactor;
    float neighboursGroupFitFactor;
    float neighboursMinDistanceFactor;
    float minDistance;
    float predatorMinDistance;
    float predatorMinDistanceFactor;
    float predatorSightDistance;
    float predatorSightAngle;
    float boidMaxVelocity;
    float boidSightDistance;

    //parametry predatora
    bool isOffensive;
    float targetChaseFactor;
    float predatorMaxVelocity;
    float predatorSelfSightDistance;

    //parametry wspolne
    float sightAngle;
    float velocityLimitFactor;
    float randomFactor;
    float obstacleSightDistance;
    float obstacleMinDistance;
    float obstacleMinDistanceFactor;

    //timery
    int calculatingDelay;
    QTimer *calculatingTimer;
};

#endif // ALGORITHM_H
