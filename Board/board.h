#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "board.h"
#include "./../player.h"
#include "./../tile.h"
#include "./../color.h"

class Board{
    private:
        std::vector<shared_ptr<Tile>> tiles;
        std::vector<shared_ptr<Color>> colors;
        int type;
        int numPlayers;
        int currentPlayer;
        std::vector<shared_ptr<Player>> players;

    public:
        Board(int type, int players);

        void trade();
        int rollDice();
        void rollDiceAndAction();
        void playTurn();
        void auction();
        
        void print();

        ~Board(); 
};

#endif
