#include "game_button.h"

GButton::GButton(QWidget *parent, Platform* platform, Game* game) : QPushButton(parent) {
    this->platform = platform;
    this->game = game;
}

void GButton::launchGame() {
    platform->launchGame(*game);
}

