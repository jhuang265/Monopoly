#include "GTJCard.h"

using namespace std;

GTJCARD::GTJCARD() {}
//HasGOTFCard is checked before calling use
GTJCARD::use(share_ptr<Player> p) {
    cout << "You are setenced to jail. " << endl;
    p.goToJail();
}

GOJFCard::~GOJFCard() {}

