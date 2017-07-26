#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QJsonObject>
#include <QDebug>

class Game
{
private:
    QString name;
    QString game_path;

public:
    // Constructors
    Game(QString name = "", QString game_path = "");

    // Getter Setter
    QString getName() const;
    void setName(const QString &value);
    QString getGame_path() const;
    void setGame_path(const QString &value);

    // methods
    QJsonObject toJsonObject() const;
    void print() const;
};

#endif // GAME_H
