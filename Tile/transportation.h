#ifndef TRANSPORTATION_H_
#define TRANSPORTATION_H_
#include <string>
#include <memory>
#include "tile.h"
#include "./../Player/player.h"

class Transportation: public Tile, public std::enable_shared_from_this<Transportation>{
    private:
        int cost; //constant, initialized by constructor
        std::vector<int> rent; //contains varied rent prices depending on the number of transportations owned by same person
        Player* owner;//owner
        bool isOwned;//stores if transportation land is owned

    public:
        std::shared_ptr<Transportation> getptr() {
                return shared_from_this();
        }
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
