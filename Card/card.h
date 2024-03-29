#ifndef __CARD_H__
#define __CARD_H__
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Player/player.h"
#include "../Board/board.h"

//Card Abstract Base Class organizes all different Cards in the game
class Card {
    public:
        Card();
        virtual void use(std::shared_ptr<Player>) = 0;
        virtual ~Card() = 0;
};

#endif
