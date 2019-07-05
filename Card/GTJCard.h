#ifndef __GTJCARD_H__
#define __GTJCARD_H__
#include "card.h"

class GTJCARD {
 public:
  GTJCARD();
  void use(shared_ptr<Player>) override;
  ~GTJCARD();
};

#endif
