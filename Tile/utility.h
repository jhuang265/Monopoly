#ifndef UTILITY_H_
#define UTILITY_H_
#include <string>
#include <memory>
#include "tile.h"
#include "./../Player/player.h"
class Utility : public Tile{
    private:
        int cost;
        std::vector<int> rent; // contains 2 elements; either 4 or 10
        std::shared_ptr<Player> owner;
        bool isOwned;
        //int getRent(){} //this class does not use this method
    public:
        Utility(int , std::vector<int> , std::string , std::string );
        int getUtilityRent(int) override;
        int getPrice() override;
        bool getIsOwned() override;                                           
        void buy(std::shared_ptr<Player>) override;
        void changeOwner(std::shared_ptr<Player>);
        void reset();
        ~Utility();
};

#endif
