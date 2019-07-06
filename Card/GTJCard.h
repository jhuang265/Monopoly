#ifndef __GTJCARD_H__
#define __GTJCARD_H__
#include "card.h"

class GTJCard {
 public:
  GTJCard();
  void use(shared_ptr<Player>);
  ~GTJCard();
};

#endif
