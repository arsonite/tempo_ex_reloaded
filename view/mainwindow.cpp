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
    /* Pointer to current selected menu navigation point, standard is startView */
    navIndex_ = 4;

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
    menuView_->setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    ui_->view->setScene(menuView_);

    /* Creating splash screen */
    ter_splash_ = new QMovie(":/res/res/gif/ter_splash.gif");
    startViewBG_ = new QLabel();
    startViewBG_->move(0, 0);
    startViewBG_->resize(width_, height_);
    startViewBG_->setStyleSheet("QLabel { background-color: transparent; }");
    startViewBG_->setMovie(ter_splash_);
    ter_splash_->start();
    menuView_->addWidget(startViewBG_);

    /* Creating dynamic stars screen */
    stars_bg_ = new QMovie(":/res/res/gif/stars_bg.gif");
    starsViewBG_ = new QLabel();
    starsViewBG_->move(1000, 1000);
    starsViewBG_->resize(width_, height_);
    starsViewBG_->setStyleSheet("QLabel { background-color: transparent; }");
    starsViewBG_->setMovie(stars_bg_);
    //starsViewBG_->setVisible(false);
    stars_bg_->start();
    menuView_->addWidget(starsViewBG_);

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

    /* "Cleaning" array */
    for(int i = 0, n = nav_.size(); i < n; i++) {
        if(nav_[i] != "X") nav_[i] = " ";
    }

    prevNavIndex_ = navIndex_;
    if(keyName == "W") navIndex_-= 3; // Go up in abstract "2d array"
    else if(keyName == "A") navIndex_ -= 1; // Go left in abstract "2d array"
    else if(keyName == "S") navIndex_+= 3; // Go down in abstract "2d array"
    else navIndex_ += 1; // Go right in abstract "2d array"

    /* Inspects the set boundaries of the navigation array */
    if(navIndex_ > nav_.size()
            || navIndex_ < 0
            || nav_[navIndex_] == "X") {
        navIndex_ = prevNavIndex_;
        return;
    }
    nav_[navIndex_] = "O"; // Select current index

    if(keyName == "W") starsViewBG_->move(0, -height_-(height_/2));
    else if(keyName == "A") starsViewBG_->move(-width_-(width_/2), 0);
    else if(keyName == "S") starsViewBG_->move(0, height_+(height_/2));
    else starsViewBG_->move(width_+(width_/2), 0);

    int interval = 32;
    QTimer *ease = new QTimer();
    ease->setInterval(interval);
    i_ = 0;
    connect(ease, &QTimer::timeout, this, [=]() {
        i_++;
        int i = i_ * (5 - i_); // Sigma formular for cubic bezier curve

        if(startViewBG_->pos().y() >= MAX_Y) {
            startViewBG_->move(startViewBG_->pos().x(), MAX_Y);

            i_ = 0;
            ease->stop();
        }

        switch(navIndex_) {
            case 1: // Up
                starsViewBG_->move(starsViewBG_->pos().x(), starsViewBG_->pos().y()-i);
                startViewBG_->move(startViewBG_->pos().x(), startViewBG_->pos().y()-i);
                break;
        }

        if(keyName == "W") {
        } else if(keyName == "A") {
            //starsViewBG_->move(starsViewBG_->pos().x(), starsViewBG_->pos().y());
            //startViewBG_->move(startViewBG_->pos().x(), startViewBG_->pos().y());
        } else if(keyName == "S") {
        } else {
        }
    });
    ease->start();
}

/* IGNORE */
void MainWindow::keyPressEvent(QKeyEvent *event) { if(i_ == 0) menuController_->keyPressEvent(event); }
