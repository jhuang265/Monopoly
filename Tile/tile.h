#ifndef TILE_H_
#define TILE_H_
#include <string>
#include <vector>
#include <memory>
class Player;

class Tile{
    private:
        std::string tileType;
        std::string name;
    public:
        virtual bool getIsOwned(){
            return false;
        };
        virtual int getCanBuild(){
            return 0;
        };
        virtual int getRent(){
            return 0;
        };
        virtual int getUtilityRent(int){
            return 0;
        };
        virtual int getPrice(){
            return 0;
        };
        virtual int getOwnerIndex(){
            return 0;
        };
        virtual int getHouses(){
            return 0;
        };
        virtual void buyHouse(){
            return;
        };
        Tile(std::string, std::string);
        std::string getType();
        std::string getName();
        virtual std::string getColor();

        //This function is callled when player wants to buy an asset
        //hence an amount of money is deducted from the player and owner is changed to player pointer
        virtual void buy(std::shared_ptr<Player> p){
            return;
        };

        //Changes the owner of an asset, the new owner will be passed in as an argument
        virtual void changeOwner(std::shared_ptr<Player> p){
            return;
        };
        virtual ~Tile();
};
#endif
