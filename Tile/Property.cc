#include "property.h"
#include "tile.h"
#include "color.h"
#include "./Player/player.h"
using namespace std;


Property:: Property(int cost_, int gameType_, vector<int> rent_, shared_ptr<Color> color_, string tileType_, string name_):
            Tile(tileType_,name_), cost(cost_), gameType(gameType_),houses(0),rent(rent_), color(color_),canBuild(gameType_),isOwned(false){
}

void Property:: buyHouse(){
    houses++;
}
int Property:: getCanBuild(){
    return canBuild;
}

int Property:: getHouses(){
    return houses;
}
int Property:: getPrice(){
    return cost;
}

int Property:: getRent(){
    return rent[houses];
}


bool Property:: getIsOwned(){
    return isOwned;
}

shared_ptr<Player> Property:: getOwner(){
    return owner;
}

void Property::buy(shared_ptr<Player> player){
    owner = player;
    owner.payMoney(cost);
    owner.addAsset(shared_from_this());
    isOwned=true;
    color.updateCanBuild();

}
void Property:: changeOwner(shared_ptr<Player> player){
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

int Property:: getOwnerIndex(){
    return owner.getIndex();

}

void Property:: setCanBuild(){
    canBuild = 1- canBuild;
}
