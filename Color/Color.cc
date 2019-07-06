#include "color.h"
using namespace std;

Color:: Color(){}

void Color::updateCanBuild(){
    /*
    if(properties[0].getOwnerIndex() == properties[1].getOwnerIndex() && properties[1].getOwnerIndex() == properties[2].getOwnerIndex()  ){
        for(int x =0; x<properties.size();x++){
            properties[x].owner.setCanBuild();
        }
    }
    */
    int index = properties[0].getOwnerIndex();
    
    for(int i = 0; i < properties.size(); ++i){
        properties[i].setCanBuild();
    }

    bool setBuild = true;

    for (int i = 1; i < properties.size(); ++i){
        if(properties[i].getOwnerIndex != i){
            setBuild = false;
        }
    }

    if(setBuild){
        for(int i = 0; i < properties.size(); ++i){
            properties[i].setCanBuild()
        }
    }

}
