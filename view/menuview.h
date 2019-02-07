#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QObject>
#include <QMainWindow>
#include <QKeyEvent>

class MenuView: public QMainWindow
{
Q_OBJECT
public:
    explicit MenuView(QMainWindow *parent = nullptr);
    virtual ~MenuView() override;
};

#endif // MENUVIEW_H
