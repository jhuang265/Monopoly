#include "game.h"
#include "../Board/board.h"
#include <memory>

// Create the board
Game::Game(int type, int players){
    b = std::make_unique<Board>(type, players);
}

// Play the game
void Game::playGame(){
    b->playTurn();
}

Game::~Game(){}
