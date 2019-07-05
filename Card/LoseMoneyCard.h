#ifndef __loseMoneyCard_H__
#define __loseMoneyCard_H__
#include "card.h"

class loseMoneyCard {
 vector<string> desc;

 public:
  loseMoneyCard();
  void use(shared_ptr<Player>) override;
  ~loseMoneyCard();
};

#endif
