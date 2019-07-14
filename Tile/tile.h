#ifndef TILE_H_
#define TILE_H_
#include <string>
#include <vector>
#include <memory>
class Player;

class Tile{
    private:
        //stores the type of type of the tile (Ex. Property, Transportation, Utility, Jail, Free Parking)
        std::string tileType;

        //stores the actual name of the asset
        std::string name;
    public:
        //return if the asset is bought
        virtual bool getIsOwned(){
            return false;
        };
        //returns an integer indicating if the property can build house on
        virtual int getCanBuild(){
            return 0;
        };
        //returns the rent of the asset
        virtual int getRent(){
            return 0;
        };
        //returns the rent of the utility given the the dice roll
        virtual int getUtilityRent(int){
            return 0;
        };
        //returns the price to buy the asset
        virtual int getPrice(){
            return 0;
        };
        //returns the owner of the asset as an index on the board
        virtual int getOwnerIndex(){
            return 0;
        };
        //returns the number of houses built already
        virtual int getHouses(){
            return 0;
        };
        //buys the house on a Property tile
        virtual void buyHouse(){
            return;
        };
        Tile(std::string, std::string);

        //returns the type of the tile
        std::string getType();

        //returns the name of tile
        std::string getName();

        //gets the color of the Property
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
