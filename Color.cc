#include "Color.h"
using namespace std;

Color:: Color(){}

void Color:: updateCanBuild(){
    if(properties[0].getOwnerIndex() == properties[1].getOwnerIndex() && properties[1].getOwnerIndex() == properties[2].getOwnerIndex()  ){
        for(int x =0; x<properties.size();x++){
            properties[x].owner.setCanBuild();
        }
    }
}