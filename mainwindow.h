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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
