#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "environment.h"
#include "boid.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setNeighboursIndicator(10, 20, 20);

    connect(ui->environment, SIGNAL(sendNeighboursAmount(float,float,float)), this, SLOT(setNeighboursIndicator(float,float,float)));

    MainWindow::on_radioBoidButton_toggled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
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
