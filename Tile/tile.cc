#include "tile.h"

using namespace std;

Tile:: Tile(string tileType_, string name_): tileType(tileType_),name(name_){}

string Tile:: getType(){
    return tileType;
}
string Tile:: getName(){
    return name;
}

Tile::~Tile(){
}
