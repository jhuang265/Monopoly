#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <memory>
#include "board.h"
#include "./../Player/player.h"
#include "./../Tile/tile.h"
#include "./../Tile/property.h"
#include "./../Tile/utility.h"
#include "./../Tile/transportation.h"
#include "./../Color/color.h"
#include "./../Card/card.h"

class Board{
    private:
        std::vector<std::shared_ptr<Tile>> tiles;
        std::vector<std::shared_ptr<Color>> colors;
        std::vector<std::shared_ptr<Property>> properties;
        std::vector<std::shared_ptr<Utility>> utilities;
        std::vector<std::shared_ptr<Transportation>> transportations;
        int type;
        int numPlayers;
        int currentPlayer;
        std::vector<shared_ptr<Player>> players;
        //std::vector<shared_ptr<Card>> cards;
    public:
        Board(int type, int players);
        void printCurPlayerStatus();
        void trade(shared_ptr<Player>);
        int rollDice();
        void rollDiceAndAction();
        void playTurn();
        void auction(std::shared_ptr<Tile>);

        void print();

        ~Board();
};

#endif
