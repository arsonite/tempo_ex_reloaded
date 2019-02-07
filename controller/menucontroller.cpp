#include "menucontroller.h"

#include <QDebug>
#include <QApplication>

MenuController::MenuController() {}

MenuController::~MenuController() {}

void MenuController::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
}

void MenuController::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << event->key();
}
