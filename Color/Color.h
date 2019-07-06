#ifndef COLOR_H_
#define COLOR_H_
#include <string>
#include <vector>
#include <memory>
#include "Player.h"
class Color{
    private:
        std::string color;
        std::vector<std:: shared_ptr<Property> > properties;
    public:
        Color();
        void updateCanBuild();
        void attach(std::shared_ptr<Property>);
        ~Color(){}
};
#endif