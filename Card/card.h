#ifndef __CARD_H__
#define __CARD_H__
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../Player/player.h"
#include "../Board/board.h"

class Card {
 public:
  virtual use(*Player) = 0;
  ~Card() = 0;
};

#endif
