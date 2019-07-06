#include "GOJFCard.h"
#include "./../Player/player.h"

using namespace std;

GOJFCard::GOJFCard() {}

void GOJFCard::use(shared_ptr<Player> p) {
    cout << "You recevied a Go To Jail Free Card!" << endl;
    p->setHasGOJFCard();
}

GOJFCard::~GOJFCard() {}

