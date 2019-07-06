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

int Player::getIndex() { return index; }

int Player::getMoney() { return money; }

void Player::receiveMoney(int moneyReceived) {
    money += moneyReceived;
    return;
}

void Player::payMoney(int payment) {
    money -= payment;
    return;
}

void Player::addAsset(shared_ptr<tile> tile) {
    string type = Tile->getTileType();
    if(type == "Property") {
        properties.emplace_back(tile);
    } else if(type == "Utility") {
        utilities.emplace_back(tile);
    } else if(type == "Transportation") {
        transportations.emplace_back(tile);
    } //else error
    return;
}

void Player::removeAsset(shared_ptr<tile> tile) {
    string type = Tile->getTileType();
    string name = Tile->getName();
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

bool Player::isInJail() {
    return isInJail;
}

void Player::release() {
    isInJail = false;
    turnsInJail = 0;
    return;
}

void Player::getTurnsInJail() { return turnsInJail; }

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