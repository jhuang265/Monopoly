#include "Utility.h"
using namespace std;
Utility:: Utility(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_),rent(rent_),Tile(tileType_,name_){}

int Utility:: getPrice(){
    return cost;
}

int Utility:: getUtilityRent(int dice){
    return rent[owner.getNumUtility()-1]* dice ;
}

bool Utility:: getIsOwned(){
    return isOwned;
}

void Utility:: buy(shared_ptr<Player> player){
    owner = player;
    isOwned=true;
    owner.payMoney(cost);
    owner.addAsset(shared_from_this());
}

void Utility:: changeOwner (shared_ptr<Player>){
    owner.removeAsset(shared_from_this());
    owner = player;
    owner.addAsset(shared_from_this());
}

void Utility:: reset(){
    isOwned = false;
}
    
