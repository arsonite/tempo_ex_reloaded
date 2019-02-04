#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui
{
class MainWindow;
}

class MainWindow: public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() override;

private:
    Ui::MainWindow *ui_;

    //SoundController *sC_;

    QGraphicsScene *menuView_;
};

#endif // MAINWINDOW_H
