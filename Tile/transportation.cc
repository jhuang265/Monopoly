#include "transportation.h"
#include "tile.h"

using namespace std;

Transportation:: Transportation(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_), rent(rent_), isOwned(false), Tile(tileType_,name_){}

int Transportation:: getPrice() {
    return cost;
}

int Transportation:: getRent() {
    auto own = owner.lock();
    return (*own).getNumTransportations()*25;
}

bool Transportation:: getIsOwned() {
    return isOwned;
}

void Transportation:: buy(shared_ptr<Player> player) {
    owner = player;
    auto own = owner.lock();
    (*own).payMoney(cost);
    (*own).addTransportation(shared_ptr<Transportation>(this));
    isOwned=true;
    cout << "Index: "  << this->getOwnerIndex() << endl;
}

int Transportation:: getOwnerIndex() {
    auto own = owner.lock();
    return (*own).getIndex();
}

void Transportation:: changeOwner (shared_ptr<Player> player){
    auto own = owner.lock();
    (*own).removeAsset(shared_ptr<Transportation>(this));

    owner = player;

    auto ownAfter = owner.lock();
    (*ownAfter).addTransportation(shared_ptr<Transportation>(this));
}

void Transportation:: reset(){
    isOwned = false;
}

Transportation::~Transportation(){};
