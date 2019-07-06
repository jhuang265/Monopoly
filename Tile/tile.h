#ifndef TILE_H_
#define TILE_H_
#include <string>
#include <vector>
class Tile{
    private: 
        std::string tileType;
        std::string name;
    public:
        Tile(std::string, std::string);
        std::string getName();

};
#endif