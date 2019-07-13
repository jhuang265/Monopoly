#include "getMoneyCard.h"
#include "./../Player/player.h"
#include <random>

using namespace std;

GetMoneyCard::GetMoneyCard() {
    desc.emplace_back("It's My Birthday! ");
    desc.emplace_back("Yon won a lottery! ");
    desc.emplace_back("Here's a gift from Mr. Goose. ");
    desc.emplace_back("You sold your kidney on the black market. ");
    desc.emplace_back("You successfully blackmailed your dad for having an affair. ");
}

void GetMoneyCard::use(shared_ptr<Player> p) {
    //int bonus = (rand()%1000) + 100;
    //int i = rand()%2; //2 for now since only 3 cards
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 2000);
    int bonus = dis(gen);
    std::uniform_int_distribution<> dis2(0, desc.size()-1);
    int i = dis2(gen);
    cout << desc.at(i) << "$"<<to_string(bonus) << " will go into your account :)"<<endl;
    p->receiveMoney(bonus);
}

GetMoneyCard::~GetMoneyCard() {}

