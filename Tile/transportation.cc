#include "transportation.h"
#include "tile.h"

using namespace std;

Transportation:: Transportation(int cost_, vector<int> rent_, string tileType_, string name_): Tile(tileType_,name_),
                    cost(cost_), rent(rent_), owner(nullptr),  isOwned(false){}

int Transportation:: getPrice() {
    return cost;
}

int Transportation:: getRent() {
    return (*owner).getNumTransportations()*25;
}

bool Transportation:: getIsOwned() {
    return isOwned;
}

void Transportation:: buy(shared_ptr<Player> player) {
    owner = player.get();
    (*owner).payMoney(cost);
    isOwned=true;
}

int Transportation:: getOwnerIndex() {
    return (*owner).getIndex();
}

void Transportation:: changeOwner (shared_ptr<Player> player){
    (*owner).removeAsset(getptr());

    owner = player.get();

    (*owner).addTransportation(getptr());
}

void Transportation:: reset(){
    isOwned = false;
}

Transportation::~Transportation(){};
