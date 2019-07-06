#include "getMoneyCard.h"
#include "./../Player/player.h"

using namespace std;

getMoneyCard::getMoneyCard() {
    desc.emplace_back("It's My Birthday!");
    desc.emplace_back("Yon won a lottery!");
    desc.emplace_back("Here's a gift from Mr. Goose. ");
}

void getMoneyCard::use(share_ptr<Player> p) {
    int bonus = (rand()%1000) + 100;
    int i = rand()%2; //2 for now since only 3 cards
    cout << desc.at(i) << "$"<<to_string(bonus) << " will go into your account :)"<<endl;
    p.receiveMoney(bonus);
}

getMoneyCard::~getMoneyCard() {}

