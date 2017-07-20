#include "mainwindow.h"
#include <QApplication>

#include "platform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    QDir dir = QDir("C:/Users/gibso/Desktop");
    QFileInfoList list = dir.entryInfoList();

    for (int i=0;i<list.size();++i) {
        qDebug() << list.at(i).baseName();
    }
    */

    Platform p = Platform("Playstation 1", QUrl());
    p.Write();
    p.Read();

    return a.exec();
}
