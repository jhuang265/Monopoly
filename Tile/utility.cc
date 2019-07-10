#include "utility.h"
#include "tile.h"
using namespace std;
Utility:: Utility(int cost_, vector<int> rent_, string tileType_, string name_):
                    cost(cost_), rent(rent_), isOwned(false), owner(nullptr), Tile(tileType_,name_){}

int Utility:: getPrice() {
    return cost;
}

int Utility:: getUtilityRent(int dice) {
    return rent[(*owner).getNumUtilities()-1]* dice ;
}

bool Utility:: getIsOwned() {
    return isOwned;
}

void Utility:: buy(shared_ptr<Player> player) {
    owner = player.get();
    (*owner).payMoney(cost);
    //(*owner).addUtility(getptr());
    isOwned=true;
}

int Utility:: getOwnerIndex() {
    return (*owner).getIndex();
}

void Utility:: changeOwner (shared_ptr<Player> player){
    (*owner).removeAsset(getptr());
    owner = player.get();
    (*owner).addUtility(getptr());
}

void Utility:: reset(){
    cout << endl;
    isOwned = false;
    cout << endl;
}

Utility::~Utility(){}
