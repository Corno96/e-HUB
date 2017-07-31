#include <QObject>
#include <QPushButton>
#include <QDebug>

#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "library.h"

#include "game_button.h"

class PButton : public QPushButton
{
    Q_OBJECT

public:
    PButton(QWidget *parent = 0, MainWindow* main_window = 0, Platform* platform = 0);
    void drawGrid(QVector<Game> vec);

public slots:
    void choosePlatform();

signals:

private:
    MainWindow* main_window;
    Platform *platform;
};
