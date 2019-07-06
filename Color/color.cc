#include "color.h"
#include "./../Player/player.h"
#include "./../Tile/property.h"
using namespace std;

Color::Color(){}

void Color::updateCanBuild(){
    int index = properties[0]->getOwnerIndex();
    
    bool setBuild = properties[0]->getCanBuild();

    if(setBuild){
        for(int i = 0; i < properties.size(); ++i){
            properties[i]->setCanBuild();
        }
    }

    for (int i = 1; i < properties.size(); ++i){
        if(properties[i]->getOwnerIndex() != i){
            setBuild = false;
        }
    }

    if(setBuild){
        for(int i = 0; i < properties.size(); ++i){
            properties[i]->setCanBuild();
        }
    }
}

void  Color:: attach(shared_ptr<Property> property){
    properties.emplace_back(property);
}
