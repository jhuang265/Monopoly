#include "tile.h"
#include "property.h"

using namespace std;
Property:: Property(int cost_,vector<int> rent_, shared_ptr<Color> color_, int gameType_,  string tileType_, string name_):
            Tile(tileType_,name_), cost(cost_), gameType(gameType_),houses(0),rent(rent_), color(color_), canBuild(gameType_),isOwned(false){
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

shared_ptr<Player> Property:: getOwner() {
    return owner.lock();
}

void Property::buy(shared_ptr<Player> player) {
    owner = player;

    auto own = owner.lock();

    (*own).payMoney(cost);
    (*own).addProperty(shared_ptr<Property>(this));
    isOwned=true;

    auto col = color.lock();
    if(canBuild == 0 || canBuild == 1) (*col).updateCanBuild();
}
void Property:: changeOwner(shared_ptr<Player> player) {
    auto own = owner.lock();
    (*own).removeAsset(shared_ptr<Property>(this));
    owner = player;

    auto ownAfter = owner.lock();
    (*own).addProperty(shared_ptr<Property>(this));

    auto col = color.lock();
    if(canBuild == 0 || canBuild == 1) (*col).updateCanBuild();
}

void Property:: reset(){
    houses=0;
    canBuild = gameType;
    isOwned = false;
}

int Property:: getOwnerIndex() {
    auto own = owner.lock();
    return (*own).getIndex();
}

void Property:: setCanBuild(){
    canBuild = 1 - canBuild;
}

string Property:: getColor(){
    auto col = color.lock();
    return (*col).getColor();
}
