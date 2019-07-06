#include "utility.h"
#include "tile.h"
using namespace std;
Utility:: Utility(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_),rent(rent_),Tile(tileType_,name_){}

int Utility:: getPrice() {
    return cost;
}

int Utility:: getUtilityRent(int dice) {
    return rent[owner->getNumUtilities()-1]* dice ;
}

bool Utility:: getIsOwned() {
    return isOwned;
}

void Utility:: buy(shared_ptr<Player> player) {
    //cout << "Name: " << player->getName() << "\t Index: "  << player->getIndex() << endl;
    owner = player;
    owner->payMoney(cost);
    owner->addUtility(shared_ptr<Utility>(this));
    isOwned=true;
    //cout << "Name: " << owner->getName() << "\t Index: "  << owner->getIndex() << endl;
}

int Utility:: getOwnerIndex() {
    return owner->getIndex();
}

void Utility:: changeOwner (shared_ptr<Player> player){
    owner->removeAsset(shared_ptr<Tile>(this));
    owner = player;
    owner->addUtility(shared_ptr<Utility>(this));
}

void Utility:: reset(){
    isOwned = false;
}

Utility::~Utility(){}