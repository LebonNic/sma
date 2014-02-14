#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <ctime>

#include "World.h"
#include "WorldView.h"

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = NULL);
    ~MainWindow();
private slots:
    void on_actionExit_triggered();
	void refreshWorld();

private:
    Ui::MainWindow *ui;
    WorldView *m_WorldView;
    World *m_World;
};

#endif // MAINWINDOW_H
