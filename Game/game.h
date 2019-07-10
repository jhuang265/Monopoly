#ifndef GAME_H_
#define GAME_H_

#include "./../Board/board.h"
#include <memory>

class Game{
    private:
        // Hold the board object
        std::unique_ptr<Board> b;
    public:

        // Construct the game
        Game(int type, int players);

        // Start playing the game
        void playGame();

        // The game has ended
        ~Game();
};
#endif
