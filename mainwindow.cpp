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
    ui->minDistanceLabel->setText(QString::number(Algorithm::getInstance().getMinDistance()));
    ui->boidMaxVelocityLabel->setText(QString::number(Algorithm::getInstance().getBoidMaxVelocity()));
    ui->boidSightDistanceLabel->setText(QString::number(Algorithm::getInstance().getBoidSightDistance()));
    ui->boidSightAngleLabel->setText(QString::number(Algorithm::getInstance().getSightAngle() * 360 / 3.1416) + "º");
    ui->neighboursVelocityFitFactorLabel->setText(QString::number(Algorithm::getInstance().getNeighboursVelocityFitFactor()));
    ui->neighboursGroupFitFactorLabel->setText(QString::number(Algorithm::getInstance().getNeighboursGroupFitFactor()));
    ui->neighboursMinDistanceFactorLabel->setText(QString::number(Algorithm::getInstance().getNeighboursMinDistanceFactor()));
    ui->predatorMinDistanceFactorLabel->setText(QString::number(Algorithm::getInstance().getPredatorMinDistanceFactor()));
    ui->randomFactorLabel->setText(QString::number(Algorithm::getInstance().getRandomFactor()));
    ui->obstacleMinDistanceLabel->setText(QString::number(Algorithm::getInstance().getObstacleMinDistance()));
    ui->predatorMaxVelocityLabel->setText(QString::number(Algorithm::getInstance().getPredatorMaxVelocity()));
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
    Algorithm::getInstance().setMinDistance(normalValue);
    ui->minDistanceLabel->setText(QString::number(Algorithm::getInstance().getMinDistance()));
}

void MainWindow::on_boidMaxVelocitySlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::getInstance().setBoidMaxVelocity(normalValue);
    ui->boidMaxVelocityLabel->setText(QString::number(Algorithm::getInstance().getBoidMaxVelocity()));
}

void MainWindow::on_boidSightDistanceSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::getInstance().setBoidSightDistance(normalValue);
    ui->boidSightDistanceLabel->setText(QString::number(Algorithm::getInstance().getBoidSightDistance()));
}

void MainWindow::on_boidSightAngleSlider_valueChanged(int value)
{
    float normalValue = value / 360.0 * 3.1415;
    Algorithm::getInstance().setSightAngle(normalValue);
    ui->boidSightAngleLabel->setText(QString::number(Algorithm::getInstance().getSightAngle() * 360 / 3.1415) + "º");
}

void MainWindow::on_neighboursVelocityFitFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::getInstance().setNeighboursVelocityFitFactor(normalValue);
    ui->neighboursVelocityFitFactorLabel->setText(QString::number(Algorithm::getInstance().getNeighboursVelocityFitFactor()));
}

void MainWindow::on_neighboursGroupFitFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::getInstance().setNeighboursGroupFitFactor(normalValue);
    ui->neighboursGroupFitFactorLabel->setText(QString::number(Algorithm::getInstance().getNeighboursGroupFitFactor()));
}

void MainWindow::on_neighboursMinDistanceFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::getInstance().setNeighboursMinDistanceFactor(normalValue);
    ui->neighboursMinDistanceFactorLabel->setText(QString::number(Algorithm::getInstance().getNeighboursMinDistanceFactor()));
}

void MainWindow::on_predatorMinDistanceFactorSlider_valueChanged(int value)
{
    float normalValue = value / 1000.0;
    Algorithm::getInstance().setPredatorMinDistanceFactor(normalValue);
    ui->predatorMinDistanceFactorLabel->setText(QString::number(Algorithm::getInstance().getPredatorMinDistanceFactor()));
}

void MainWindow::on_randomFactorSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::getInstance().setRandomFactor(normalValue);
    ui->randomFactorLabel->setText(QString::number(Algorithm::getInstance().getRandomFactor()));
}

void MainWindow::on_obstacleMinDistanceSlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::getInstance().setObstacleMinDistance(normalValue);
    ui->obstacleMinDistanceLabel->setText(QString::number(Algorithm::getInstance().getObstacleMinDistance()));
}

void MainWindow::on_predatorMaxVelocitySlider_valueChanged(int value)
{
    float normalValue = value / 100.0;
    Algorithm::getInstance().setPredatorMaxVelocity(normalValue);
    ui->predatorMaxVelocityLabel->setText(QString::number(Algorithm::getInstance().getPredatorMaxVelocity()));
}

void MainWindow::setDefaultSliders()
{
    ui->minDistanceSlider->setValue(int(Algorithm::getInstance().defaultMinDistance * 100));
    ui->boidMaxVelocitySlider->setValue(int(Algorithm::getInstance().defaultBoidMaxVelocity * 100));
    ui->boidSightDistanceSlider->setValue(int(Algorithm::getInstance().defaultBoidSightDistance * 100));
    ui->boidSightAngleSlider->setValue(int(Algorithm::getInstance().defaultSightAngle * 360 / 3.14));
    ui->neighboursVelocityFitFactorSlider->setValue(int(Algorithm::getInstance().defaultNeighboursVelocityFitFactor * 1000));
    ui->neighboursGroupFitFactorSlider->setValue(int(Algorithm::getInstance().defaultNeighboursGroupFitFactor * 1000));
    ui->neighboursMinDistanceFactorSlider->setValue(int(Algorithm::getInstance().defaultNeighboursMinDistanceFactor * 1000));
    ui->predatorMinDistanceFactorSlider->setValue(int(Algorithm::getInstance().defaultPredatorMinDistanceFactor * 1000));
    ui->randomFactorSlider->setValue(int(Algorithm::getInstance().defaultRandomFactor * 100));
    ui->obstacleMinDistanceSlider->setValue(int(Algorithm::getInstance().defaultObstacleMinDistance * 100));
    ui->predatorMaxVelocitySlider->setValue(int(Algorithm::getInstance().defaultPredatorMaxVelocity * 100));
}

void MainWindow::on_resetButton_clicked()
{
    Algorithm::getInstance().setDefaultParameters();
    setDefaultSliders();
}
