#include "GOJFCard.h"
#include "./../Player/player.h"

using namespace std;

GOJFCard::GOJFCard() {}

//The player will setHasGOJFCard field if receives one and will not be sent to jail if encountered such condition once in the future
void GOJFCard::use(shared_ptr<Player> p) {
    cout << "You recevied a Get Out Of Jail Free Card!" << endl;
    p->setHasGOJFCard();
}

GOJFCard::~GOJFCard() {}

