#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class Environment;

namespace Ui {
class MainWindow;
}
/*!
 * \brief The MainWindow class, creates the main window of the program
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor of the MainWindow class, sets all created labels and sliders
     * \param parent pointer to the parent widget
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_radioBoidButton_toggled(bool checked);
    void on_radioButtonPredator_toggled(bool checked);
    void on_radioButtonObstacle_toggled(bool checked);
    void on_minDistanceSlider_valueChanged(int value);
    void on_boidMaxVelocitySlider_valueChanged(int value);
    void on_boidSightDistanceSlider_valueChanged(int value);
    void on_boidSightAngleSlider_valueChanged(int value);
    void on_neighboursVelocityFitFactorSlider_valueChanged(int value);
    void on_neighboursGroupFitFactorSlider_valueChanged(int value);
    void on_neighboursMinDistanceFactorSlider_valueChanged(int value);
    void on_predatorMinDistanceFactorSlider_valueChanged(int value);
    void on_randomFactorSlider_valueChanged(int value);
    void on_obstacleMinDistanceSlider_valueChanged(int value);
    void on_predatorMaxVelocitySlider_valueChanged(int value);
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;

    void setLabels();
    void setDefaultSliders();
};

#endif // MAINWINDOW_H
