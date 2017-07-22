#include "mainwindow.h"
#include <QApplication>

#include "library.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Library library;

    Platform p = Platform("PS1", "C:/Users/gibso/Desktop/ePSXe/ePSXe.exe", "D:/GAMES/Playstation 1", ".cue");

    Game g = Game("Tomb raider", "D:/GAMES/Playstation 1/Tomb Raider/Tomb Raider (v1.6).cue");

    p.launchGame(g);

    MainWindow w;

    //w.setWindowState(Qt::WindowFullScreen);

    w.show();


    return a.exec();
    //return 0;
}
