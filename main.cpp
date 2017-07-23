#include "mainwindow.h"
#include <QApplication>


#include "library.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    Library library;

    Platform p = Platform("PS1", "C:/Users/gibso/Desktop/ePSXe/ePSXe.exe", "D:/GAMES/Playstation 1");
    Platform citra = Platform("Citra", "C:/Users/gibso/Desktop/Nuova cartella/citra-qt.exe", "C:/Users/gibso/Desktop/Citra");

    Game g = Game("Tomb raider", "D:/GAMES/Playstation 1/Tomb Raider/Tomb Raider (v1.6).cue");
    Game zelda = Game("The legend of zelda", "C:/Users/gibso/Desktop/Citra/Zelda Ocarina of Time 3D.3ds");


    citra.loadCmdStr();

    citra.launchGame(zelda);


    //p.launchGame(g);

    return 0;
    /*
    MainWindow w;

    //w.setWindowState(Qt::WindowFullScreen);

    w.show();


    return a.exec();
    //return 0;
    */
}
