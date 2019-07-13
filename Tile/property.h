#ifndef PROPERTY_H_
#define PROPERTY_H_
#include <string>
#include <memory>
#include "tile.h"
#include "./../Color/color.h"
#include "./../Player/player.h"

class Property: public Tile, public std::enable_shared_from_this<Property>{
    private:
        int cost;
        int gameType;
        int houses; //current num of houses
        std::vector<int> rent;
        Player* owner;
        std::weak_ptr<Color> color; //constant, initilaized by contructor
        int canBuild; // if one can build house, only happens if owner has all colored sets
        bool isOwned;

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
