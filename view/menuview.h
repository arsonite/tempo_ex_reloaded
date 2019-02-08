#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QKeyEvent>

class MenuView: public QGraphicsScene
{
Q_OBJECT
public:
    explicit MenuView(QMainWindow *parent = nullptr);
    virtual ~MenuView() override;
};

#endif // MENUVIEW_H
