#ifndef __GOJFCARD_H__
#define __GOJFCARD_H__
#include "card.h"

class GOJFCard {
 public:
  GOJFCard();
  void use(shared_ptr<Player>);
  ~GOJFCard();
};

#endif
