#include "player.h"
using namespace std;

Player::Player(string name, const int index): name{name}, index{index} {
     money = 1500;
     pos = 0;
     numDoubles = 0;
     turnsInJail = 0;
     inJail = false;
     hasGOJFC = false;
}

string Player::getName() {
    return name;
}

int Player::getIndex() {
    return index;
}

// Print out the names of assets at a specific index
string Player::propertyNameAtIndex(int i) {
    if(i < properties.size()) {
        return properties.at(i)->getName();
    }
    return "";
}

string Player::utilityNameAtIndex(int i) {
    if(i < utilities.size()) {
        return utilities.at(i)->getName();
    }
    return "";
}

string Player::transportationNameAtIndex(int i) {
    if(i < transportations.size()) {
        return transportations.at(i)->getName();
    }
    return "";
}

int Player::getMoney() { return money; }

// Pay and recieve money
void Player::receiveMoney(int moneyReceived) {
    money += moneyReceived;
    return;
}

void Player::payMoney(int payment) {
    money -= payment;
    return;
}

// Add an asset to the things a player owns
void Player::addProperty(shared_ptr<Property> p) {
    properties.emplace_back(p);
    return;
}

void Player::addUtility(shared_ptr<Utility> u) {
    utilities.emplace_back(u);
    return;
}

void Player::addTransportation(shared_ptr<Transportation> t) {
    transportations.emplace_back(t);
    return;
}

// Get rid of an asset
void Player::removeAsset(shared_ptr<Tile> tile) {
    string type = tile->getType();
    string name = tile->getName();
    vector<shared_ptr<Tile> > asset;
    if(type == "Property") {
        for(size_t i = 0; i < properties.size(); ++i) {
            if(properties[i]->getName() == name) {
                properties.erase(properties.begin()+i);
                break;
            }
        }
    } else if(type == "Utility") {
        for(size_t i = 0; i < utilities.size(); ++i) {
            if(utilities[i]->getName() == name) {
                utilities.erase(utilities.begin()+i);
                break;
            }
        }
    } else if(type == "Transportation") {
        for(size_t i = 0; i < transportations.size(); ++i) {
            if(transportations[i]->getName() == name) {
                transportations.erase(transportations.begin()+i);
                break;
            }
        }
    } //else error
    return;
}

// Get the specific asset at an index
shared_ptr<Tile> Player:: returnAsset(string name) {
    for(auto &p : properties) {
         if(p->getName() == name) return p;
     }
    for(auto &u : utilities) {
         if(u->getName() == name) return u;
     }
    for(auto &t : transportations) {
         if(t->getName() == name) return t;
     }
     return nullptr;
}

// Get how many of each asset type is owned
int Player::getNumUtilities() { return utilities.size(); }

int Player::getNumTransportations() { return transportations.size(); }

int Player::getNumProperties() { return properties.size(); }

int Player::getPos() { return pos; }

// Move a player's position
void Player::move(int n) {
    // Calculate the new position
    int result = pos + n;

    // Move the player to their new position
    pos = (result <= 39 && result >= 0) ? result : result % 40;

    // Give them 200$ if they passed 'GO'
    if(result > 39){
        receiveMoney(200);
    }
    return;
}

// Handle the number of consecutive doubles a player has rolled
int Player::getDoubles() {
    return numDoubles;
}

void Player::resetDoubles() {
    numDoubles = 0;
    return;
}

void Player::rolledDoubles() {
    ++numDoubles;
    return;
}

// Send a player to jail
void Player::goToJail() {
    if(hasGOJFC == false) {
        inJail = true;
        turnsInJail = 0;
        numDoubles = 0;
        pos = 10;
    } else {
        hasGOJFC = false;
        cout << "You've used your Go To Jail Free Card and you are free to go!"<<endl;
    }
    return;
}

// Handle a player when they're in jail
void Player::addTurnInJail(){
    turnsInJail++;
    return;
}

bool Player::isInJail() {
    return inJail;
}

void Player::release() {
    inJail = false;
    turnsInJail = 0;
    return;
}

int Player::getTurnsInJail() {
    return turnsInJail;
}

void Player::setHasGOJFCard() {
    hasGOJFC = true;
    return;
}

void Player::clearHasGOJFCard() {
    hasGOJFC = false;
    return;
}

// Show all asset a player owns as well as their money
void Player::print() {
    cout << "Name: "<<name<<endl;
    cout << "Account Balance: $"<<money<<endl;
    if(hasGOJFC) { cout << "*You have 1 Get Out Of Jail Free Card*" << endl;}
    cout << "Properties Owned: ";
    int cnt=1;
    if(!properties.empty()) {
        for(auto & p : properties) {
            if (p == properties.back()) {
                cout << "("<< cnt<< ")"<<p->getName();
                cnt++;
                break;
            }
            cout << "("<< cnt<< ")"<< p->getName()<<", ";
            cnt++;
        }
    }
    cout<<"\n";
    cout << "Utilities Owned: ";
    if(!utilities.empty()) {
        for(auto & u : utilities) {
            if (u == utilities.back()) {
                cout <<"("<< cnt<< ")"<< u->getName();
                cnt++;
                break;
            }
            cout <<"("<< cnt<< ")"<< u->getName()<<", ";
            cnt++;
        }
    }
    cout<<"\n";
    cout << "Transportations Owned: ";
    if(!transportations.empty()) {
        for(auto & t : transportations) {
            if (t == transportations.back()) {
                cout << "("<< cnt<< ")"<<t->getName();
                cnt++;
                break;
            }
            cout << "("<< cnt<< ")"<<t->getName()<<", ";
            cnt++;
        }
    }
    cout<<"\n";
}

// Player has lost, clear all their assets
Player::~Player() {
    for(auto& p : properties) {
        p->reset();
    }
    for(auto& u : utilities) {
        u->reset();
    }
    for(auto& t : transportations) {
        t->reset();
    }
}

