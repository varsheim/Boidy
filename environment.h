#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QWidget>
#include <QGLWidget>

#include "boid.h"
#include "predator.h"
#include "obstacle.h"

/*!
 * \brief The Environment class.
 * Everything is drawn in the instance of this class.
 */
class Environment : public QGLWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Constructor of the Environment class, initializes starting parameters of the simulation
     * \param parent pointer to the parent widget
     */
    explicit Environment(QWidget *parent = 0);
    ~Environment();

    /*!
     * \brief Switches (according to the argument) to boid drawing mode
     * \param checked bool argument, true - on click boid drawing enabled
     */
    void switchBoidDrawing(bool checked);
    /*!
     * \brief Switches (according to the argument) to predator drawing mode
     * \param checked bool argument, true - on click predator drawing enabled
     */
    void switchPredatorDrawing(bool checked);
    /*!
     * \brief Switches (according to the argument) to obstacles drawing mode
     * \param checked bool argument, true - on click obstacle drawing enabled
     */
    void switchObstacleDrawing(bool checked);

protected:
    /*!
     * \brief Sets initial parameters of the OpenGL window
     */
    void initializeGL();
    /*!
     * \brief Virtual method - paints OpenGL window. This method is called mostly when update() is used.
     */
    void paintGL();
    /*!
     * \brief Method called every time OpenGL window is resized. The new size is passed through arguments.
     * \param width int value representing width of the OpenGL window
     * \param height int value representing height of the OpenGL window
     */
    void resizeGL(int width, int height);
    /*!
     * \brief The property holds the minimum size recommended for the OpenGL window
     * \return minimum size of the widget (in QSize format)
     */
    QSize minimumSizeHint() const;
    /*!
     * \brief The property holds the recommended size for the widget
     * \return recommended size of the widget if no layout was defined fot he widget
     */
    QSize sizeHint() const;

private:
    float startXPos;
    float startYPos;
    float startXVelo;
    float startYVelo;
    int boidQuantity;
    int predatorQuantity;
    int obstacleQuantity;

    int drawingDelay;
    int calculatingDelay;

    void draw();
    void drawFilledCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides);
    void drawBoidSwarm(QList<Boid *> *swarm);
    void drawPredatorSwarm(QList<Predator *> *swarm);
    void drawObstacles(QList<Obstacle *> *obstacles);

    void createBoidSwarmOnStart(int quantity, float startXPos, float startYPos, float startXVelo, float startYVelo);
    void createPredatorSwarmOnStart(int quantity, float startXPos, float startYPos, float startXVelo, float startYVelo);
    void createObstaclesOnStart(int quantity); //DO DOKONCZENIA!

    QList<Boid *> *boidSwarm;
    QList<Predator *> *predatorSwarm;
    QList<Obstacle *> *obstacles;

    //obsluga myszy
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void boidMousePressEvent(QMouseEvent *event);
    void predatorMousePressEvent(QMouseEvent *event);

    Position2D mouseOldPosition;
    void mouseDrawObstacles();

    bool mouseLeftDown;
    bool mouseRightDown;

    bool boidDrawingOn;
    bool predatorDrawingOn;
    bool obstacleDrawingOn;

signals:

private slots:
    void updateEnvironment();
    void updateCreatures();
};

#endif // ENVIRONMENT_H
