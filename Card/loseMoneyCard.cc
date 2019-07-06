#include "loseMoneyCard.h"
#include "./../Player/player.h"

using namespace std;

loseMoneyCard::loseMoneyCard() {
    desc.emplace_back("Debt Collect: ");
    desc.emplace_back("Mr. Goose got mad! ");
    desc.emplace_back("Pay tuition: ");
}

void loseMoneyCard::use(shared_ptr<Player> p) {
    int debt = (rand()%1000) + 100;
    int i = rand()%2; //2 for now since only 3 cards
    cout << desc.at(i) << "$"<<to_string(debt) << " will be taken from your account :("<<endl;
    p->payMoney(debt);
}

loseMoneyCard::~loseMoneyCard() {}

