#ifndef __loseMoneyCard_H__
#define __loseMoneyCard_H__
#include "card.h"

class LoseMoneyCard {
        vector<string> desc;
    public:
        LoseMoneyCard();
        void use(shared_ptr<Player>);
        ~LoseMoneyCard();
};

#endif
