#ifndef __CARD_H__
#define __CARD_H__
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "board.h"

class Card {
 public:
  virtual use(*Player) = 0;
  ~Card() = 0;
};

#endif
