#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <array>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    int w = 700;
    int h = 500;

    this->setFixedSize(w, h);
    ui_->setupUi(this);

    setWindowTitle("TempoEX: Reloaded");

    ui_->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui_->view->setSceneRect(0, 0, w, h);
    ui_->view->resize(w, h);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui_;
}
