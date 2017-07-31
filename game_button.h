#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include <QObject>
#include <QPushButton>
#include "platform.h"

class GButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GButton(QWidget *parent = 0, Platform* platform = 0, Game* game = 0);

signals:

public slots:
    void launchGame();

private:
    Platform* platform;
    Game* game;
};

#endif // GAME_BUTTON_H
