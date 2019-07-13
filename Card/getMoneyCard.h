#ifndef __getMoneyCard_H__
#define __getMoneyCard_H__
#include "card.h"

class GetMoneyCard: public Card {
    vector<string> desc;

    public:
        GetMoneyCard();
        void use(std::shared_ptr<Player>);
        ~GetMoneyCard();
};

#endif
