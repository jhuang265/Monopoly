#ifndef __MOVECARD_H__
#define __MOVECARD_H__
#include "card.h"

class MoveCard {
 public:
  MoveCard();
  void use(shared_ptr<Player>) override;
  ~MoveCard();
};

#endif
