#include "utility.h"
#include "tile.h"
using namespace std;
Utility:: Utility(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_),rent(rent_),Tile(tileType_,name_){}

int Utility:: getPrice() {
    return cost;
}

int Utility:: getUtilityRent(int dice) {
    auto own = owner.lock();
    return rent[(*own).getNumUtilities()-1]* dice ;
}

bool Utility:: getIsOwned() {
    return isOwned;
}

void Utility:: buy(shared_ptr<Player> player) {
    owner = player;
    auto own = owner.lock();
    (*own).payMoney(cost);
    (*own).addUtility(shared_ptr<Utility>(this));
    isOwned=true;
}

int Utility:: getOwnerIndex() {
    auto own = owner.lock();
    return (*own).getIndex();
}

void Utility:: changeOwner (shared_ptr<Player> player){
    auto own = owner.lock();
    (*own).removeAsset(shared_ptr<Tile>(this));
    owner = player;
     
    auto ownAfter = owner.lock();
    (*ownAfter).addUtility(shared_ptr<Utility>(this));
}

void Utility:: reset(){
    cout << endl;
    isOwned = false;
    cout << endl;
}

Utility::~Utility(){}
