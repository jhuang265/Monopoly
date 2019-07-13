#ifndef COLOR_H_
#define COLOR_H_
#include <string>
#include <vector>
#include <memory>

// Forward declare player and property
class Player;
class Property;

class Color{
    private:
        // Name property for the color and properties that belong to the color group
        std::string color;
        std::vector<std::shared_ptr<Property>> properties;
    public:
        // Functions to update building houses, get color name and assign property to a color
        Color(std::string);
        std::string getColor();
        void updateCanBuild();
        void attach(std::shared_ptr<Property>);
        ~Color(){}
};
#endif
