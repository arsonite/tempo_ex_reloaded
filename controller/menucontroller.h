#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QObject>
#include <QKeyEvent>

class MenuController: public QObject
{
Q_OBJECT
public:
    explicit MenuController();
    virtual ~MenuController() override;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MENUCONTROLLER_H
