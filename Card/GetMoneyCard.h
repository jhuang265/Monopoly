#ifndef __GETMONEYCARD_H__
#define __GETMONEYCARD_H__
#include "card.h"

class GetMoneyCard {
 vector<string> desc;

 public:
  GetMoneyCard();
  void use(share_ptr<Player>) override;
  ~GetMoneyCard();
};

#endif
