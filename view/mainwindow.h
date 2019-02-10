#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menuview.h"
#include "controller/menucontroller.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMovie>
#include <QLabel>

namespace Ui
{
class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow: public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

public slots:
    /* Receiver of keyPress-signal */
    void keyPressed(QString keyName);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui_;

    QFont pixelFont_;

    MenuController *menuController_;
    MenuView *menuView_;
    //SoundController *soundController_;

    /* Splash screen */
    QMovie *ter_splash_;
    QLabel *startViewBG_;

    /* Star screen */
    QMovie *stars_bg_;
    QLabel *starsViewBG_;

    int width_;
    int height_;
    int pos_max_x_;
    int pos_max_y_;

    int i_;
    int counter_;
};

#endif // MAINWINDOW_H
