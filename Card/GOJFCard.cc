#include "GOJFCard.h"
#include "./../Player/player.h"

using namespace std;

GOJFCard::GOJFCard() {}

void GOJFCard::use(shared_ptr<Player> p) {
    cout << "You recevied a Get Out Of Jail Free Card!" << endl;
    p->setHasGOJFCard();
}

GOJFCard::~GOJFCard() {}

