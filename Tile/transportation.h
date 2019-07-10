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
        std::weak_ptr<Player> owner; 
        bool isOwned; 

    public:
        Transportation(int, std::vector<int> , std::string, std::string);
        int getPrice() override;
        int getRent() override;
        bool getIsOwned() override;
        int getOwnerIndex() override;
        void buy(std::shared_ptr<Player>) override;
        void changeOwner(std::shared_ptr<Player>) override;
        void reset();
        ~Transportation();
        

};

#endif
