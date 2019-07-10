#ifndef __moveCard_H__
#define __moveCard_H__
#include "card.h"

class moveCard: public Card {
    public:
        moveCard();
        void use(shared_ptr<Player>);
        ~moveCard();
};

#endif
