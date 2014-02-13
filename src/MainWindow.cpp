#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    m_World = new World(100,0.05, rand()); //FIX THIS put rand() instead of 1
    m_World->populateMap(0.005, 0.15, 0.005);
    m_WorldView = new WorldView(m_World, this);
    this->setCentralWidget(m_WorldView);
    m_WorldView->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
