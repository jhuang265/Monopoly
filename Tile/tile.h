#ifndef TILE_H_
#define TILE_H_
#include <string>
#include <vector>
class Player;
class Tile{
    private: 
        std::string tileType;
        std::string name;
    public:
        Tile(std::string, std::string);
        std::string getName();
        virtual bool getIsOwned(){return false;};
        virtual std::shared_ptr<Player> getOwner(){return nullptr;};
        virtual int getCanBuild(){return 0;};
        virtual int getRent(){return 0;};
        virtual int getUtilityRent(int){return 0;};
        virtual int getPrice(){return 0;};
        virtual int getOwnerIndex(){return 0;};
        virtual void buy(std::shared_ptr<Player> p){return;};
        virtual int getHouses(){return 0;};
        virtual void buyHouse(){return;};
        virtual void changeOwner(std::shared_ptr<Player> p){return;};
        virtual ~Tile();
};
#endif