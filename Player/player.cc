#include "player.h"

using namespace std;

Player::Player(string name, const int index): name{name}, index{index} {
    int money = 1500;
    int pos = 0;
    int numDoubles = 0;
    int turnsInJail = 0;
    bool inJail = false;
    bool hasGOJFC = false;
}

string Player::getName() { return name; }

int Player::getIndex() { return index; }

string Player::propertyNameAtIndex(int i) {
    if(i < properties.size()) { return properties.at(i); }
    return "";
}

string Player::utilityNameAtIndex(int i) {
    if(i < utilities.size()) { return utilities.at(i); }
    return "";
}

string Player::transportationNameAtIndex(int i) {
    if(i < transportations.size()) { return transportations.at(i); }
    return "";
}

int Player::getMoney() { return money; }

void Player::receiveMoney(int moneyReceived) {
    money += moneyReceived;
    return;
}

void Player::payMoney(int payment) {
    money -= payment;
    return;
}

void Player::addAsset(shared_ptr<Tile> tile) {
    string type = tile->getTileType();
    if(type == "Property") {
        properties.emplace_back(tile);
    } else if(type == "Utility") {
        utilities.emplace_back(tile);
    } else if(type == "Transportation") {
        transportations.emplace_back(tile);
    } //else error
    return;
}

void Player::removeAsset(shared_ptr<Tile> tile) {
    string type = tile->getTileType();
    string name = tile->getName();
    vector<shared_ptr<Property> > asset;
    if(type == "Property") {
        asset = properties;
    } else if(type == "Utility") {
        asset = utilities;
    } else if(type == "Transportation") {
        asset = transportations;
    } //else error

    for(int i = 0; i < asset.size(); ++i) {
        if(asset[i]->getName() == name) {
            asset.erase(asset.begin()+i);
            break;
        }
    }
    return;
}

shared_ptr<Tile> Player::returnAsset(string name) {
    for(auto &p : properties) {
        if(p->getName() == name) return p;
    }
    for(auto &u : utilities) {
        if(u->getName() == name) return u;
    }
    for(auto &t : transportations) {
        if(t->getName() == name) return t;
    }
}

int Player::getNumUtilities() { return utilities.size(); }

int Player::getNumTransportations() { return transportations.size(); }

int Player::getPos() { return Pos; }

void Player::move(int n) {
    int result = Pos + n;
    result = (result <= 39 && result >= 0) ? result : result%40;
    return result; 
}

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

void Player::goToJail() {
    if(hasGOJFC == false) {
        inJail = true;
        turnsInJail++;
    } else {
        hasGOJFC = false;
        cout << "You've used your Go To Jail Free Card and you are free to go!"<<endl;
    }
    return;
}

void Player::addTurnInJail(){
    turnsInJail++;
    return;
}

bool Player::isInJail() {
    return isInJail;
}

void Player::release() {
    isInJail = false;
    turnsInJail = 0;
    return;
}

int Player::getTurnsInJail() { return turnsInJail; }

void Player::setHasGOTJFCard() {
    hasGOJFC = true;
    return;
}

void Player::clearHasGOTJFCard() {
    hasGOJFC = false;
    return;
}

void Player::print() {
    cout << "Name: "<<name<<endl;
    cout << "Account Balance: "<<money<<endl;
    cout << "Properties Owned: "<<endl;
    if(!properties.empty()) {
        for(auto & p : properties) {
            if (p == properties.back()) {
                cout << p->getName() <<endl;
                break;
            }
            cout << p->getName()<<", ";
        }
    }

    cout << "Utilities Owned: "<<endl;
    if(!utilities.empty()) {
        for(auto & u : utilities) {
            if (u == utilities.back()) {
                cout << u->getName() <<endl;
                break;
            }
            cout << u->getName()<<", ";
        }
    }

    cout << "Transportations Owned: "<<endl;
    if(!transportations.empty()) {
        for(auto & t : transportations) {
            if (t == transportations.back()) {
                cout << t->getName() <<endl;
                break;
            }
            cout << t->getName()<<", ";
        }
    }
}

~Player::Player() {
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

