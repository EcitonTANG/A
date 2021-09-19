#include "Game.h"

int main() {
    Game game;

    while (game.isPlaying()) {
        game.mainMenu();
    }

    return 0;
}
