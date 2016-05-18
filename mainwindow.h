#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class Environment;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Environment *getEnvironment();

public slots:
    void setNeighboursIndicator(float, float, float);

private slots:
    void on_radioBoidButton_toggled(bool checked);
    void on_radioButtonPredator_toggled(bool checked);
    void on_radioButtonObstacle_toggled(bool checked);

    void on_minDistanceSlider_valueChanged(int value);

    void on_boidMaxVelocitySlider_valueChanged(int value);

    void on_boidSightDistanceSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    void setLabels();
};

#endif // MAINWINDOW_H
