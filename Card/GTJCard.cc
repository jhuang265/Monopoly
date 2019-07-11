#include "GTJCard.h"
#include "./../Player/player.h"

using namespace std;

GTJCard::GTJCard() {}
//HasGOTFCard is checked before calling use
void GTJCard::use(shared_ptr<Player> p) {
    cout << "You did something stupid. You have been sent to jail. " << endl;
    p->goToJail();
}

GTJCard::~GTJCard() {}

