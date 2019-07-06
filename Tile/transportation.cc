#include "transportation.h"
#include "tile.h"

using namespace std;

Transportation:: Transportation(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_),rent(rent_),Tile(tileType_,name_){}

int Transportation:: getPrice() {
    return cost;
}

int Transportation:: getRent() {
    return owner->getNumTransportations()*25;
}

bool Transportation:: getIsOwned() {
    return isOwned;
}

void Transportation:: buy(shared_ptr<Player> player) {
    owner = player;
    isOwned=true;
    owner->payMoney(cost);
    owner->addTransportation((shared_ptr<Transportation>(this)));
}

void Transportation:: changeOwner (shared_ptr<Player> player){
    owner->removeAsset((shared_ptr<Transportation>(this)));
    owner = player;
    owner->addTransportation(shared_ptr<Transportation>(this));
    
}

void Transportation:: reset(){
    isOwned = false;
}
    
Transportation::~Transportation(){};