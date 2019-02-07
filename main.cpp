#include "controller/menucontroller.h"

#include "view/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mW;
    mW.show();

    return a.exec();
}
