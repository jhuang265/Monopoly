#ifndef TRANSPORTATION_H_
#define TRANSPORTATION_H_
#include <string>
#include <memory>
#include "Tile.h"

class Transportation:: public Tile{
    private:
        int cost; //constant, initialized by constructor
        vector<int> rent; //constnat, initialized by constructor
        std::shared_ptr<Player> owner; 
        bool isOwned; 

    public:
        Transportation(int, vector<int>, string, string);
        int getPrice();
        int getRent() override;
        bool getIsOwned();
        void buy(std::shared_ptr<Player>);
        void changeOwner(std::shared_ptr<Player>);
        void reset();
        ~Transportation(){}
        

};

#endif
