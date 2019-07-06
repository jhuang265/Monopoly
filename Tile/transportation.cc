#include "transportation.h"
#include "tile.h"

using namespace std;

Transportation:: Transportation(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_),rent(rent_),Tile(tileType_,name_){}

int Transportation:: getPrice(){
    return cost;
}

int Transportation:: getRent() override{
    return owner.getNumTransportation()*25;
}

bool Transportation:: getIsOwned() override{
    return isOwned;
}

void Transportation:: buy(shared_ptr<Player> player){
    owner = player;
    isOwned=true;
    owner.payMoney(cost);
    owner.addAsset(shared_from_this());
}

void Transportation:: changeOwner (shared_ptr<Player> player){
    owner.removeAsset(shared_from_this());
    owner = player;
    owner.addAsset(shared_from_this());
    
}

void Transportation:: reset(){
    isOwned = false;
}
    
