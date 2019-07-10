#ifndef TILE_H_
#define TILE_H_
#include <string>
#include <vector>
#include <memory>
class Player;
/*
template<class T> class enable_shared_from_this
{
public:

    shared_ptr<T> shared_from_this();
    shared_ptr<T const> shared_from_this() const;
}
*/
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
        virtual void buy(std::shared_ptr<Player> p){
            return;
        };
        virtual void changeOwner(std::shared_ptr<Player> p){
            return;
        };
        virtual ~Tile();
};
#endif
