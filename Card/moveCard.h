#ifndef __moveCard_H__
#define __moveCard_H__
#include "card.h"

class MoveCard: public Card {
    public:
        MoveCard();
        void use(shared_ptr<Player>);
        ~MoveCard();
};

#endif
