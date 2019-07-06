#ifndef TRANSPORTATION_H_
#define TRANSPORTATION_H_
#include <string>
#include <memory>
#include "tile.h"
#include "./../Player/player.h"

class Transportation: public Tile{
    private:
        int cost; //constant, initialized by constructor
        std::vector<int> rent; //constnat, initialized by constructor
        std::shared_ptr<Player> owner; 
        bool isOwned; 

    public:
        Transportation(int, std::vector<int> , std::string, std::string);
        int getPrice();
        int getRent() override;
        bool getIsOwned() override;
        void buy(std::shared_ptr<Player>);
        void changeOwner(std::shared_ptr<Player>);
        void reset();
        ~Transportation(){}
        

};

#endif
