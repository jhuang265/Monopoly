#ifndef __getMoneyCard_H__
#define __getMoneyCard_H__
#include "card.h"

class getMoneyCard {
 vector<string> desc;

 public:
  getMoneyCard();
  void use(share_ptr<Player>) override;
  ~getMoneyCard();
};

#endif
