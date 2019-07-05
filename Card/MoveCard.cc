#include "MoveCard.h"

using namespace std;

//check in Board what the play's position has been changed to

MoveCard::MoveCard() {}
MoveCard::use(share_ptr<Player> p) {
    int newpos = rand()%39;
    p.move(newpos);
}

GOJFCard::~GOJFCard() {}

