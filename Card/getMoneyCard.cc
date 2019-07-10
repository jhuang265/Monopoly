#include "getMoneyCard.h"
#include "./../Player/player.h"
#include <random>

using namespace std;

getMoneyCard::getMoneyCard() {
    desc.emplace_back("It's My Birthday! ");
    desc.emplace_back("Yon won a lottery! ");
    desc.emplace_back("Here's a gift from Mr. Goose. ");
}

void getMoneyCard::use(shared_ptr<Player> p) {
    //int bonus = (rand()%1000) + 100;
    int i = rand()%2; //2 for now since only 3 cards
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 2000);
    int bonus = dis(gen);
    cout << desc.at(i) << "$"<<to_string(bonus) << " will go into your account :)"<<endl;
    p->receiveMoney(bonus);
}

getMoneyCard::~getMoneyCard() {}

