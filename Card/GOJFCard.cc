#include "GOJFCard.h"

using namespace std;

GOJFCard::GOJFCard() {}

GOJFCard::use(share_ptr<Player> p) {
    cout << "You recevied a Go To Jail Free Card!" << endl;
    p.setHasGOJFCard();
}

GOJFCard::~GOJFCard() {}

