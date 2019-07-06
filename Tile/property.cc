#include "tile.h"
#include "property.h"

using namespace std;
Property:: Property(int cost_,vector<int> rent_, shared_ptr<Color> color_, int gameType_,  string tileType_, string name_):
            Tile(tileType_,name_), cost(cost_), gameType(gameType_),houses(0),rent(rent_), color(color_),canBuild(gameType_),isOwned(false){
}

void Property:: buyHouse() override{
    houses++;
}
int Property:: getCanBuild() override{
    return canBuild;
}

int Property:: getHouses() override{
    return houses;
}
int Property:: getPrice() override{
    return cost;
}

int Property:: getRent() override{
    return rent[houses];
}


bool Property:: getIsOwned() override{
    return isOwned;
}

shared_ptr<Player> Property:: getOwner() override{
    return owner;
}

void Property::buy(shared_ptr<Player> player) override{
    owner = player;
    owner.payMoney(cost);
    owner.addAsset(shared_from_this());
    isOwned=true;
    color.updateCanBuild();

}
void Property:: changeOwner(shared_ptr<Player> player) override{
    owner.removeAsset(shared_from_this());
    owner = player;
    owner.addAsset(shared_from_this());
    color.updateCanBuild();
}

void Property:: reset(){
    houses=0;
    canBuild = gameType;
    isOwned = false;
}

int Property:: getOwnerIndex() override{
    return owner.getIndex();
}

void Property:: setCanBuild(){
    canBuild = 1- canBuild;
}
