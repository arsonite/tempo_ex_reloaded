#include "controller/menucontroller.h"

#include "view/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MenuController mC;

    MainWindow mW;
    mW.show();

    return a.exec();
}
