#ifndef GAME_H
#define GAME_H

#include <QString>

class Game
{
private:
    QString name;
    QString path;

public:
    // Constructors
    Game(QString name = "", QString path = "");

    // Getter Setter
    QString getName() const;
    void setName(const QString &value);
    QString getPath() const;
    void setPath(const QString &value);

    // methods

};

#endif // GAME_H
