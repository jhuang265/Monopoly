#ifndef UTILITY_H_
#define UTILITY_H_
#include <string>
#include <memory>
#include "tile.h"
#include "./../Player/player.h"
class Utility : public Tile, public std::enable_shared_from_this<Utility>{
    private:
        int cost;
        std::vector<int> rent; // contains 2 elements; either 4 or 10
        Player* owner;
        bool isOwned;

    public:
        std::shared_ptr<Utility> getptr() {
                return shared_from_this();
        }
        Utility(int , std::vector<int> , std::string , std::string );
        int getUtilityRent(int) override;
        int getPrice() override;
        bool getIsOwned() override;
        int getOwnerIndex() override;
        void buy(std::shared_ptr<Player>) override;
        void changeOwner(std::shared_ptr<Player>) override;
        void reset();
        ~Utility();
};

#endif
