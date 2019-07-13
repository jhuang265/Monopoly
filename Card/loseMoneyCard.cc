#include "loseMoneyCard.h"
#include "./../Player/player.h"
#include <random>

using namespace std;

LoseMoneyCard::LoseMoneyCard() {
    desc.emplace_back("You got involved with a loan shark: ");
    desc.emplace_back("Spent too much money buying chicken wraps: ");
    desc.emplace_back("Mr. Goose got mad! ");
    desc.emplace_back("Pay tuition: ");
    desc.emplace_back("You lost your wallet: ");
    desc.emplace_back("You got catfished: ");
    desc.emplace_back("You think Aquaman is cool: ");
    desc.emplace_back("Sometimes you want to go through a binary tree, and then you have to touch all the children.: ");
}

void LoseMoneyCard::use(shared_ptr<Player> p) {
    //int debt = (rand()%1000) + 100;
    //int i = rand()%2; //2 for now since only 3 cards
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 1000);
    int debt = dis(gen);
    std::uniform_int_distribution<> dis2(0, desc.size()-1);
    int i = dis2(gen);
    cout << desc.at(i) << "$"<<to_string(debt) << " will be taken from your account :("<<endl;
    p->payMoney(debt);
}

LoseMoneyCard::~LoseMoneyCard() {}

