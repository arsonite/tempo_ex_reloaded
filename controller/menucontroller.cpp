#include "menucontroller.h"

#include <QApplication>

#include <QDebug>

MenuController::MenuController()
{

}

MenuController::~MenuController() {}

void MenuController::keyPressEvent(QKeyEvent *event)
{
    auto key = event->key();
    if(DEFAULT_KEYS_.find(key) == DEFAULT_KEYS_.end()) return;
    qDebug() << key;
}
