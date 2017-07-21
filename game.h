#ifndef GAME_H
#define GAME_H

#include <QString>

class Game
{
private:
    QString name;
    QString path;

public:
    Game();
    Game(QString name, QString path);
};

#endif // GAME_H
