#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "board.h"
#include "./../Player/player.h"
#include "./../Tile/tile.h"
#include "./../Color/color.h"
#include "./../Card/card.h"

class Board{
    private:
        std::vector<shared_ptr<Tile>> tiles;
        std::vector<shared_ptr<Color>> colors;
        int type;
        int numPlayers;
        int currentPlayer;
        std::vector<shared_ptr<Player>> players;
        std::vector<shared_ptr<Card>> cards;
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
