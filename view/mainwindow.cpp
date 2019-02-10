#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <array>

#include <QString>
#include <QFontDatabase>
#include <QTimer>

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
    pos_max_x_ = width_ = 900;
    pos_max_y_ = height_ = 700;

    /* Setting up basic configuration for MainWindow */
    ui_->setupUi(this);
    this->setWindowTitle("TempoEX: Reloaded");
    this->setFixedSize(width_, height_); // Fixed window size - Temporary
    //this->resize(w, h); // Flexible window size

    /* Setting up configuration of main view */
    ui_->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui_->view->setSceneRect(0, 0, width_, height_);
    ui_->view->resize(width_, height_);

    /* Loading custom 8-Bit font */
    int id = QFontDatabase::addApplicationFont(":/res/res/8-Bit Wonder.TTF");
    QString pixelFontURL = QFontDatabase::applicationFontFamilies(id).at(0);
    pixelFont_.setFamily(pixelFontURL);
    pixelFont_.setPointSize(20);

    menuController_ = new MenuController();
    /* Connecting signal from MenuController to receiver-slot of MainWindow */
    connect(menuController_, &MenuController::keyPressed, this, &MainWindow::keyPressed);

    menuView_ = new MenuView(this);
    ui_->view->setScene(menuView_);

    /* Creating splash screen */
    ter_splash_ = new QMovie(":/res/res/gif/ter_splash.gif");
    startViewBG_ = new QLabel();
    startViewBG_->move(0, 0);
    startViewBG_->resize(width(), height_);
    startViewBG_->setStyleSheet("QLabel { background-color: transparent; }");
    startViewBG_->setMovie(ter_splash_);
    ter_splash_->start();
    menuView_->addWidget(startViewBG_);

    /* Creating dynamic stars screen */
    stars_bg_ = new QMovie(":/res/res/gif/stars_bg.gif");
    starsViewBG_ = new QLabel();
    starsViewBG_->move(0, 0);
    starsViewBG_->resize(width(), height_);
    starsViewBG_->setStyleSheet("QLabel { background-color: transparent; }");
    starsViewBG_->setMovie(stars_bg_);
    stars_bg_->start();
    menuView_->addWidget(startViewBG_);

    std::array<bool, 5> viewSelector;
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui_;
    delete menuView_;
}

/**
 * @brief MainWindow::keyPressed
 * @param key
 */
void MainWindow::keyPressed(QString keyName)
{
    const int MAX_X = width_;
    const int MAX_Y = height_;

    int interval = 32;
    QTimer *ease = new QTimer();
    ease->setInterval(interval);
    i_ = 0;
    connect(ease, &QTimer::timeout, this, [=]() {
        QPoint p = startViewBG_->pos();
        i_++;
        int i = i_ * (5 - i_); // Sigma formular for cubic bezier curve

        if(p.y() >= MAX_Y) {
            startViewBG_->move(p.x(), MAX_Y);
            i_ = 0;
            ease->stop();
        }

        if(keyName == "W") {
            startViewBG_->move(p.x(), p.y()-i);
        } else if(keyName == "A") {

        } else if(keyName == "S") {

        } else {

        }
    });
    ease->start();
}

/* IGNORE */
void MainWindow::keyPressEvent(QKeyEvent *event) { menuController_->keyPressEvent(event); }
