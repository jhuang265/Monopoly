#include "color.h"
#include "./../Player/player.h"
#include "./../Tile/property.h"
using namespace std;

Color::Color(std::string name): color{name}{}

void Color::updateCanBuild(){
    int index = -1;

    // We first need to check that all properties are owned. If not, then we don't need to check any further
    if(properties[0]->getIsOwned()) {
        // Get the owner of the first property
        index = properties[0]->getOwnerIndex();
    }
    else {
        return;
    }

    // Get the status of the first property
    bool originalBuild = properties[0]->getCanBuild();
    bool setBuild = properties[0]->getCanBuild();

    // First switch the status of each property
    for(size_t i = 0; i < properties.size(); ++i){
        properties[i]->setCanBuild();
    }

    // Now, if the owners are different, then we set a flag to false
    setBuild = true;

    for (size_t i = 1; i < properties.size(); ++i){
        if(!(properties[i]->getIsOwned()) || properties[i]->getOwnerIndex() != index){
            setBuild = false;
        }
    }

    // Now compare the flag with the original status.
    // If the owners are different and the buildings originally couldn't be built on, then we revert the state
    // If they are the same but we originally couldn't build, now we can
    // If we could originally build and the owners are still the same, then we revert to the can build state
    // If they are now different but we originally could build, then we toggled once meaning we can no longer build
    if(originalBuild == setBuild){
        for(int i = 0; i < properties.size(); ++i){
            properties[i]->setCanBuild();
        }
    }
}

// Attach properties to each color
void Color:: attach(shared_ptr<Property> property){
    properties.emplace_back(property);
}

// Get the color's name
string Color:: getColor(){
    return color;
}
