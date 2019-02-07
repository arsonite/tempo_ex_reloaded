#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menuview.h"
#include "controller/menucontroller.h"

#include <QMainWindow>
#include <QGraphicsScene>

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

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui_;

    QFont pixelFont_;

    QGraphicsScene *menuScene_;

    MenuController *menuController_;
    MenuView *menuView_;
    //SoundController *soundController_;

    int width_;
    int height_;
};

#endif // MAINWINDOW_H
