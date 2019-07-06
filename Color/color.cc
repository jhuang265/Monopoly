#include "color.h"
#include "./../Player/player.h"
#include "./../Tile/property.h"
using namespace std;

Color::Color(){}

void Color::updateCanBuild(){
    int index = -1;

    if(properties[0]->getIsOwned()) {
        index = properties[0]->getOwnerIndex();
    }

    int setBuild = properties[0]->getCanBuild();

    if(setBuild){
        for(int i = 0; i < properties.size(); ++i){
            //cout << properties[i]->getName() << endl;
            //cout << properties[i]->getOwner()->getName() << endl;
            properties[i]->setCanBuild();
        }
    }

    for (int i = 1; i < properties.size(); ++i){
        if(!(properties[i]->getIsOwned()) || properties[i]->getOwnerIndex() != index){
            setBuild = false;
        }
    }

    if(setBuild){
        for(int i = 0; i < properties.size(); ++i){
            properties[i]->setCanBuild();
        }
    }
}

void Color:: attach(shared_ptr<Property> property){
    properties.emplace_back(property);
}
