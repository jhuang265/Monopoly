#ifndef __LOSEMONEYCARD_H__
#define __LOSEMONEYCARD_H__
#include "card.h"

class LoseMoneyCard {
 vector<string> desc;

 public:
  LoseMoneyCard();
  void use(shared_ptr<Player>) override;
  ~LoseMoneyCard();
};

#endif
