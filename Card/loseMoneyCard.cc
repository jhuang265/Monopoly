#include "loseMoneyCard.h"
#include "./../Player/player.h"
#include <random>

using namespace std;

loseMoneyCard::loseMoneyCard() {
    desc.emplace_back("Debt Collect: ");
    desc.emplace_back("Mr. Goose got mad! ");
    desc.emplace_back("Pay tuition: ");
}

void loseMoneyCard::use(shared_ptr<Player> p) {
    //int debt = (rand()%1000) + 100;
    int i = rand()%2; //2 for now since only 3 cards
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 2000);
    int debt = dis(gen);
    cout << desc.at(i) << " $"<<to_string(debt) << " will be taken from your account :("<<endl;
    p->payMoney(debt);
}

loseMoneyCard::~loseMoneyCard() {}

