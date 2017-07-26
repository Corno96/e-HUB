#include "game.h"

Game::Game(QString name, QString game_path) {
    this->name = name;
    this->game_path = game_path;
}

QString Game::getName() const
{
    return name;
}

void Game::setName(const QString &value)
{
    name = value;
}

QString Game::getGame_path() const
{
    return game_path;
}

void Game::setGame_path(const QString &value)
{
    game_path = value;
}


QJsonObject Game::toJsonObject() const {
    QJsonValue n = QJsonValue(name);
    QJsonValue p = QJsonValue(game_path);

    QJsonObject obj;
    obj.insert(QString("name"), n);
    obj.insert(QString("game_path"), p);

    return obj;
}

void Game::print() const {
    qDebug() << "\tname: " << name << "; game path: " << game_path;
}
