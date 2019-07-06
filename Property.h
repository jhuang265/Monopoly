#ifndef PROPERTY_H_
#define PROPERTY_H_
#include <string>
#include <memory>
#include "tile.h"
#include "color.h"
#include "./Player/player.h"

class Property:: public Tile{
    private:
        int cost;
        int gameType;
        int houses; //current num of houses
        std::vector<int> rent;
        std::shared_ptr<Player> owner;
        std::shared_ptr<Color> color; //constant, initilaized by contructor 
        int canBuild; // if one can build house, only happens if owner has all colored sets
        bool isOwned;
    public:
        Property(int, std::vector<int>, std::shared_ptr<Color>, int, std::string, std::string);
        void buyHouse();
        int getCanBuild();
        int getHouses();
        int getPrice();
        int getRent() override;
        bool getIsOwned();
        int getOwnerIndex();
        void buy(std::shared_ptr<Player> );
        std::shared_ptr<Player> getOwner();
        void reset();
        void changeOwner(std::shared_ptr<Player>);
        void setCanBuild();
        ~Property(){}

};

#endif
