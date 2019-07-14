#ifndef PROPERTY_H_
#define PROPERTY_H_
#include <string>
#include <memory>
#include "tile.h"
#include "./../Color/color.h"
#include "./../Player/player.h"

class Property: public Tile, public std::enable_shared_from_this<Property>{
    private:
        int cost;//the cost to buy property
        int gameType; //stores the game type of the: either play with color or not
        int houses; //current num of houses
        std::vector<int> rent; // stores all the rent prices. rent[0] stores the rent when no house built, rent[1] stores the rent of 1 house built and so on...
        Player* owner;//points to the Player who owns it
        std::weak_ptr<Color> color; //constant, initilaized by contructor
        int canBuild; // if one can build house, only happens if owner has all colored sets
        bool isOwned;//stores if this property is currently owned by somebody

    public:
        std::shared_ptr<Property> getptr() {
                return shared_from_this();
        }
        Property(int, std::vector<int>, std::shared_ptr<Color>, int, std::string, std::string);
        void buyHouse() override;
        int getCanBuild() override;
        int getHouses() override;
        int getPrice() override;
        int getRent() override;
        bool getIsOwned() override;
        int getOwnerIndex() override;
        void buy(std::shared_ptr<Player> ) override;
        //std::shared_ptr<Player> getOwner() override;
        void reset();
        void changeOwner(std::shared_ptr<Player>) override;
        void setCanBuild();
        std::string getColor() override;
        ~Property(){}

};

#endif
