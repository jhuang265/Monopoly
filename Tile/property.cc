#include "tile.h"
#include "property.h"

using namespace std;
Property:: Property(int cost_,vector<int> rent_, shared_ptr<Color> color_, int gameType_,  string tileType_, string name_):
            Tile(tileType_,name_), cost(cost_), gameType(gameType_),houses(0),rent(rent_), color(color_),canBuild(gameType_),isOwned(false){
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
    return owner;
}

void Property::buy(shared_ptr<Player> player) {
    owner = player;
    owner->payMoney(cost);
    owner->addProperty(shared_ptr<Property>(this));
    isOwned=true;
    if(canBuild == 0 || canBuild == 1) color->updateCanBuild();
}
void Property:: changeOwner(shared_ptr<Player> player) {
    // cout<<"check 1"<<endl;
    owner->removeAsset(shared_ptr<Property>(this));
    // cout<<"check 2"<<endl;
    owner = player;
    owner->addProperty(shared_ptr<Property>(this));
    // cout<<"check 3"<<endl;
    if(canBuild == 0 || canBuild == 1) color->updateCanBuild();
}

void Property:: reset(){
    houses=0;
    canBuild = gameType;
    isOwned = false;
}

int Property:: getOwnerIndex() {
    return owner->getIndex();
}

void Property:: setCanBuild(){
    canBuild = 1 - canBuild;
}

string Property:: getColor(){
    return color->getColor();
}