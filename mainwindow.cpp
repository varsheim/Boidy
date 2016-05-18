#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"
#include "boid.h"
#include "algorithm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::on_radioBoidButton_toggled(true);

    setLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabels()
{
    ui->minDistanceLabel->setText(QString::number(Algorithm::getMinDistance()));
    ui->boidMaxVelocityLabel->setText(QString::number(Algorithm::getBoidMaxVelocity()));
    ui->boidSightDistanceLabel->setText(QString::number(Algorithm::getBoidSightDistance()));
    ui->boidSightAngleLabel->setText(QString::number(Algorithm::getSightAngle() * 360 / 3.1416) + "º");
    ui->neighboursVelocityFitFactorLabel->setText(QString::number(Algorithm::getNeighboursVelocityFitFactor()));
    ui->neighboursGroupFitFactorLabel->setText(QString::number(Algorithm::getNeighboursGroupFitFactor()));
    ui->neighboursMinDistanceFactorLabel->setText(QString::number(Algorithm::getNeighboursMinDistanceFactor()));
    ui->predatorMinDistanceFactorLabel->setText(QString::number(Algorithm::getPredatorMinDistanceFactor()));
    ui->randomFactorLabel->setText(QString::number(Algorithm::getRandomFactor()));
    ui->obstacleMinDistanceLabel->setText(QString::number(Algorithm::getObstacleMinDistance()));
    ui->predatorMaxVelocityLabel->setText(QString::number(Algorithm::getPredatorMaxVelocity()));
}

Environment* MainWindow::getEnvironment()
{
    return ui->environment;
}

void MainWindow::on_radioBoidButton_toggled(bool checked)
{
    ui->environment->switchBoidDrawing(checked);
    ui->environment->switchObstacleDrawing(!checked);
    ui->environment->switchPredatorDrawing(!checked);
}

void MainWindow::on_radioButtonPredator_toggled(bool checked)
{
    ui->environment->switchBoidDrawing(!checked);
    ui->environment->switchObstacleDrawing(!checked);
    ui->environment->switchPredatorDrawing(checked);
}

void MainWindow::on_radioButtonObstacle_toggled(bool checked)
{
    ui->environment->switchBoidDrawing(!checked);
    ui->environment->switchObstacleDrawing(checked);
    ui->environment->switchPredatorDrawing(!checked);
}

void MainWindow::on_minDistanceSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::setMinDistance(normalValue);
    ui->minDistanceLabel->setText(QString::number(Algorithm::getMinDistance()));
}

void MainWindow::on_boidMaxVelocitySlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::setBoidMaxVelocity(normalValue);
    ui->boidMaxVelocityLabel->setText(QString::number(Algorithm::getBoidMaxVelocity()));
}

void MainWindow::on_boidSightDistanceSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::setBoidSightDistance(normalValue);
    ui->boidSightDistanceLabel->setText(QString::number(Algorithm::getBoidSightDistance()));
}

void MainWindow::on_boidSightAngleSlider_valueChanged(int value)
{
    float normalValue = value / 360.0 * 3.1415;
    Algorithm::setSightAngle(normalValue);
    ui->boidSightAngleLabel->setText(QString::number(Algorithm::getSightAngle() * 360 / 3.1415) + "º");
}

void MainWindow::on_neighboursVelocityFitFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::setNeighboursVelocityFitFactor(normalValue);
    ui->neighboursVelocityFitFactorLabel->setText(QString::number(Algorithm::getNeighboursVelocityFitFactor()));
}

void MainWindow::on_neighboursGroupFitFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::setNeighboursGroupFitFactor(normalValue);
    ui->neighboursGroupFitFactorLabel->setText(QString::number(Algorithm::getNeighboursGroupFitFactor()));
}

void MainWindow::on_neighboursMinDistanceFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::setNeighboursMinDistanceFactor(normalValue);
    ui->neighboursMinDistanceFactorLabel->setText(QString::number(Algorithm::getNeighboursMinDistanceFactor()));
}

void MainWindow::on_predatorMinDistanceFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::setPredatorMinDistanceFactor(normalValue);
    ui->predatorMinDistanceFactorLabel->setText(QString::number(Algorithm::getPredatorMinDistanceFactor()));
}

void MainWindow::on_randomFactorSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::setRandomFactor(normalValue);
    ui->randomFactorLabel->setText(QString::number(Algorithm::getRandomFactor()));
}

void MainWindow::on_obstacleMinDistanceSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::setObstacleMinDistance(normalValue);
    ui->obstacleMinDistanceLabel->setText(QString::number(Algorithm::getObstacleMinDistance()));
}

void MainWindow::on_predatorMaxVelocitySlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::setPredatorMaxVelocity(normalValue);
    ui->predatorMaxVelocityLabel->setText(QString::number(Algorithm::getPredatorMaxVelocity()));
}

void MainWindow::setDefaultSliders()
{
    ui->minDistanceSlider->setValue(int(Algorithm::defaultMinDistance * 100));
    ui->boidMaxVelocitySlider->setValue(int(Algorithm::defaultBoidMaxVelocity * 100));
    ui->boidSightDistanceSlider->setValue(int(Algorithm::defaultBoidSightDistance * 100));
    ui->boidSightAngleSlider->setValue(int(Algorithm::defaultSightAngle * 360 / 3.14));
    ui->neighboursVelocityFitFactorSlider->setValue(int(Algorithm::defaultNeighboursVelocityFitFactor * 1000));
    ui->neighboursGroupFitFactorSlider->setValue(int(Algorithm::defaultNeighboursGroupFitFactor * 1000));
    ui->neighboursMinDistanceFactorSlider->setValue(int(Algorithm::defaultNeighboursMinDistanceFactor * 1000));
    ui->predatorMinDistanceFactorSlider->setValue(int(Algorithm::defaultPredatorMinDistanceFactor * 1000));
    ui->randomFactorSlider->setValue(int(Algorithm::defaultRandomFactor * 100));
    ui->obstacleMinDistanceSlider->setValue(int(Algorithm::defaultObstacleMinDistance * 100));
    ui->predatorMaxVelocitySlider->setValue(int(Algorithm::defaultPredatorMaxVelocity * 100));
}

void MainWindow::on_resetButton_clicked()
{
    Algorithm::setDefaultParameters();
    setDefaultSliders();
}
