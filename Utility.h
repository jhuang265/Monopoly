#ifndef UTILITY_H_
#define UTILITY_H_
#include <string>
#include <memory>
#include "Tile.h"

class Utility{
    private:
        int cost;
        vector<int> rent; // contains 2 elements; either 4 or 10
        std:: shared_ptr<Player> owner;
        bool isOwned;
        int getRent() override{} //this class does not use this method
    public:
        int getUtilityRent(int);
        int getPrice();
        bool getIsOwned();
        void buy(std::shared_ptr<Player>);
        void changeOwner(std::shared_ptr<Player>);
        void reset();
        ~Utility(){}
};