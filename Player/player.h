#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <iostream>
#include "../Tile/tile.h"
#include "../Tile/property.h"
#include "../Tile/utility.h"
#include "../Tile/transportation.h"

using namespace std;
class Player {
  string name;
  const int index;
  vector<shared_ptr<Property> > properties;
  vector<shared_ptr<Utility> > utilities;
  vector<shared_ptr<Transportation> > transportations;
  int money;
  int pos;
  int numDoubles;
  int turnsInJail;
  bool inJail;
  bool hasGOJFC;
 
public:
  Player(std::string, int);
  string getName();
  int getIndex();
  std::string propertyNameAtIndex(int);
  std::string utilityNameAtIndex(int);
  std::string transportationNameAtIndex(int);

  int getMoney();
  void receiveMoney(int);
  void payMoney(int);

  void addAsset(shared_ptr<Tile> tile);
  void removeAsset(shared_ptr<Tile> tile);
  int getNumUtilities();
  int getNumTransportations();

  int getPos();
  void move(int);

  int getDoubles();
  void resetDoubles();
  void rolledDoubles();
  
  void goToJail();
  bool isInJail();
  void release();
  void addTurnInJail();
  int getTurnsInJail();
  void setHasGOTJFCard();
  void clearHasGOTJFCard();

  void print();
  void printAsset();//needs to be written for giving trade options
  ~Player();
};

#endif
