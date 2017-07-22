#include "game.h"

Game::Game(QString name, QString path) {
    this->name = name;
    this->path = path;
}

QString Game::getName() const
{
    return name;
}

void Game::setName(const QString &value)
{
    name = value;
}

QString Game::getPath() const
{
    return path;
}

void Game::setPath(const QString &value)
{
    path = value;
}
