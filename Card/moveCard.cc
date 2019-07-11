#include "moveCard.h"
#include "./../Player/player.h"
#include <random>

using namespace std;

//check in Board what the play's position has been changed to

moveCard::moveCard() {}
void moveCard::use(shared_ptr<Player> p) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 39);
    int newpos = dis(gen);
    p->move(newpos);
    cout << "You were teleported by a fairy to position " << newpos << " on the board." << endl;
    cout << "PSA: Don't do drugs." << endl;
    cout << endl;
}

moveCard::~moveCard() {}

