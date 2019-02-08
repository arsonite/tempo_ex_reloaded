#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <map>

#include <QObject>
#include <QKeyEvent>

/* The default keys for the menu */

class MenuController: public QObject
{
Q_OBJECT
public:
    explicit MenuController();
    virtual ~MenuController() override;

    void keyPressEvent(QKeyEvent *event);

    const std::map<int, QString> DEFAULT_KEYS_ = {
        {Qt::Key_W, "W"},
        {Qt::Key_A, "A"},
        {Qt::Key_S, "S"},
        {Qt::Key_D, "D"}};
};

#endif // MENUCONTROLLER_H
