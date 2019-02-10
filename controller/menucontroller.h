#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <map>

#include <QMainWindow>
#include <QKeyEvent>

class MenuController: public QMainWindow
{
Q_OBJECT
public:
    explicit MenuController();
    virtual ~MenuController() override;

    /* The default keys for the menu */
    const std::map<int, QString> DEFAULT_KEYS_ = {
        {Qt::Key_W, "W"},
        {Qt::Key_A, "A"},
        {Qt::Key_S, "S"},
        {Qt::Key_D, "D"}};

public slots:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void keyPressed(QString keyName);
};

#endif // MENUCONTROLLER_H
