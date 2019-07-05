#ifndef GAME_H
#define GAME_H

#include <./../Board/board.h>
#include <memory>

class Game{
    private:
        std::unique_ptr<Board> b;
        int type;
        int players;

    public:

        // Construct the game
        Game(int type, int players);

        // Start playing the game
        void playGame();

        // The game has ended
        ~Game();
};
#endif
