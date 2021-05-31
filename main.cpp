#include "mainwindow.h"

#include <QApplication>

//   Головна функція
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
