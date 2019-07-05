#ifndef PROPERTY_H_
#define PROPERTY_H_
#include <string>
#include <memory>

class Property:: public Tile{
    private:
        int cost; //constant, initialized by constructor
        int houses; //current num of houses
        int* rents; //constnat, initialized by constructor
        std::shared_ptr<Player> owner;
        std::shared_ptr<Color> color;
        bool canBuild;
    public:
        Property(int cost_, int );
        bool getCanBuild();
        bool isOwned();
        int getPrice();
        int getRent();
        int getIsOwned();
        void buy(std::shared_ptr<Player> );
        void reset();
        void changeOwner(std::shared_ptr<Player>);

};

#endif