#include "tile.h"
#include "property.h"

using namespace std;
Property:: Property(int cost_,vector<int> rent_, shared_ptr<Color> color_, int gameType_,  string tileType_, string name_):
            Tile(tileType_,name_), cost(cost_), gameType(gameType_),houses(0),rent(rent_), owner(nullptr), color(color_),  canBuild(gameType_),isOwned(false){
}

void Property:: buyHouse() {
    if(houses <= 4){
        houses++;
    }
    else{
        cout << "You have already purchased as many houses on this property as your can." << endl;
    }
}
int Property:: getCanBuild() {
    return canBuild;
}

int Property:: getHouses() {
    return houses;
}
int Property:: getPrice() {
    return cost;
}

int Property:: getRent() {
    return rent[houses];
}

bool Property:: getIsOwned() {
    return isOwned;
}

void Property::buy(shared_ptr<Player> player) {
    owner = player.get();

    (*owner).payMoney(cost);
    isOwned=true;

    auto col = color.lock();
    //Since the property now has a new owner, we need to check if this owner owns all the properties of the same color
    if(canBuild == 0 || canBuild == 1) (*col).updateCanBuild();
}
void Property:: changeOwner(shared_ptr<Player> player) {
    (*owner).removeAsset(getptr());
    owner = player.get();

    (*owner).addProperty(getptr());

    auto col = color.lock();
    //Since the property now has a new owner, we need to check if this owner owns all the properties of the same color
    if(canBuild == 0 || canBuild == 1) (*col).updateCanBuild();
}

void Property:: reset(){
    houses=0;
    canBuild = gameType;
    isOwned = false;
}

int Property:: getOwnerIndex() {
    return (*owner).getIndex();
}

void Property:: setCanBuild(){
    canBuild = 1 - canBuild;
}

string Property:: getColor(){
    auto col = color.lock();
    return (*col).getColor();
}
