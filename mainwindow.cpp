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
    setNeighboursIndicator(10, 20, 20);

    connect(ui->environment, SIGNAL(sendNeighboursAmount(float,float,float)), this, SLOT(setNeighboursIndicator(float,float,float)));

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
}

void MainWindow::setNeighboursIndicator(float a, float b, float c) //abc to trzy liczby do wyswietlenia
{
    ui->neighboursIndicator->setText(QString::number(a) + " " + QString::number(b) + " " + QString::number(c));
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
