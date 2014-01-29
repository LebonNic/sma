#include "MainWindow.h"
#include "ui_MainWindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    m_World = new World(25,25,0.05,rand());
    m_World->populateMap(0.05,0.15,0.05);
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
