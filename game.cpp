#include "game.h"

Game::Game() {
    this->name = "";
    this->path = "";
}

Game::Game(QString name, QString path) {
    this->name = name;
    this->path = path;
}
