#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <array>

#include <QString>
#include <QFontDatabase>
#include <QMovie>
#include <QLabel>

#include <QDebug>

/**
 * Main and only window.
 *
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    width_ = 900;
    height_ = 700;

    // Setting up basic configuration for MainWindow
    ui_->setupUi(this);
    this->setWindowTitle("TempoEX: Reloaded");
    this->setFixedSize(width_, height_); // Fixed window size - Temporary
    //this->resize(w, h); // Flexible window size

    // Setting up configuration of main view
    ui_->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui_->view->setSceneRect(0, 0, width_, height_);
    ui_->view->resize(width_, height_);

    // Loading custom 8-Bit font
    int id = QFontDatabase::addApplicationFont(":/res/res/8-Bit Wonder.TTF");
    QString pixelFontURL = QFontDatabase::applicationFontFamilies(id).at(0);
    pixelFont_.setFamily(pixelFontURL);
    pixelFont_.setPointSize(20);

    // Mandatory menu and start view
    menuView_ = new QGraphicsScene(this);
    ui_->view->setScene(menuView_);

    QMovie *ter_splash = new QMovie(":/res/res/gif/ter_splash.gif");
    QLabel *startViewBG = new QLabel();
    startViewBG->move(0, 0);
    startViewBG->resize(width(), height_);
    startViewBG->setStyleSheet("QLabel { background-color: transparent; }");
    startViewBG->setMovie(ter_splash);
    ter_splash->start();
    menuView_->addWidget(startViewBG);

    std::array<bool, 5> viewSelector;
}

/**
 *
 *
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui_;
}
