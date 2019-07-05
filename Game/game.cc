#include <game.h>
#include <../Board/board.h>
#include <memory>

Game::Game(int type, int players): type{type}, players{players}{
    b = std::make_unique<Board>(type, players);
}

void Game::playGame(){
    b.play();
}

~Game::Game(){}
