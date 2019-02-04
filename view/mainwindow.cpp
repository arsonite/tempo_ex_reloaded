#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <array>

#include <QString>
#include <QFontDatabase>

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
    int w = 900;
    int h = 700;

    ui_->setupUi(this);
    this->setWindowTitle("TempoEX: Reloaded");
    this->resize(w, h);

    // Mandatory menu and start view
    menuView_ = new QGraphicsScene();
    menuView_->setSceneRect(0, 0, w, h);
    menuView_->setBackgroundBrush(Qt::black);
    ui_->view->setScene(menuView_);

    // Setting up configuration of main view
    ui_->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui_->view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui_->view->setSceneRect(0, 0, w, h);
    ui_->view->resize(w, h);

    // Loading custom 8-Bit font
    int id = QFontDatabase::addApplicationFont(":/res/res/8-Bit Wonder.TTF");
    QString pixelFontURL = QFontDatabase::applicationFontFamilies(id).at(0);
    pixelFont_.setFamily(pixelFontURL);
    pixelFont_.setPointSize(20);


    menuView_->addItem();
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
