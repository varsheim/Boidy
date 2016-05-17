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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
