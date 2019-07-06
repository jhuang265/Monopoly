#ifndef COLOR_H_
#define COLOR_H_
#include <string>
#include <vector>
#include <memory>
//#include "./../Player/player.h"
//#include "./../Tile/property.h"
class Player;
class Property;

class Color{
    private:
        std::string color;
        std::vector<std::shared_ptr<Property>> properties;
    public:
        Color();
        void getColor();
        void updateCanBuild();
        void attach(std::shared_ptr<Property>);
        ~Color(){}
};
#endif
