#include "dialog.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myMainWindow mainWindow;  //生命周期与app一样
    Dialog* w=new Dialog(&mainWindow);
    w->show();
    return a.exec();
}
