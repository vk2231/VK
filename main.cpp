#include <QApplication>
#include "ident.h"
#include "mainwindow.h"
#include<QObject>
#include<Qt>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    return a.exec();
}

