#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <memory>
#include <vector>
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
        // We assign all the tiles to the board
        std::vector<std::shared_ptr<Tile>> tiles;
        std::vector<std::shared_ptr<Color>> colors;
        std::vector<std::shared_ptr<Property>> properties;
        std::vector<std::shared_ptr<Utility>> utilities;
        std::vector<std::shared_ptr<Transportation>> transportations;
        // Game type and number of players
        int numPlayers;
        // Keeping track of whose turn it is
        int currentPlayer;
        // Keep track of active players
        std::vector<std::shared_ptr<Player>> players;
        //std::vector<shared_ptr<Card>> cards;
    public:

        Board(int type, int players);
        //void printCurPlayerStatus();
        // Trading function
        void trade(shared_ptr<Player>);
        // Playing turn
        int rollDice();
        void rollDiceAndAction();
        void playTurn();
        void checkOwnership();

        // Auction function
        void auction(std::shared_ptr<Tile>);
        std::string getAssetType(std::string);

        // Display board to user
        void printBoard();

        ~Board();
};

#endif
