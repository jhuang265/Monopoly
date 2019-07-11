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

string Player::getName() { return name; }

int Player::getIndex() { return index; }

string Player::propertyNameAtIndex(int i) {
    if(i < properties.size()) { return properties.at(i)->getName(); }
    return "";
}

string Player::utilityNameAtIndex(int i) {
    if(i < utilities.size()) { return utilities.at(i)->getName(); }
    return "";
}

string Player::transportationNameAtIndex(int i) {
    if(i < transportations.size()) { return transportations.at(i)->getName(); }
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

void Player::removeAsset(shared_ptr<Tile> tile) {
    string type = tile->getType();
    string name = tile->getName();
    vector<shared_ptr<Tile> > asset;
    if(type == "Property") {
        for(int i = 0; i < properties.size(); ++i) {
            if(properties[i]->getName() == name) {
                properties.erase(properties.begin()+i);
                break;
            }
        }
    } else if(type == "Utility") {
        for(int i = 0; i < utilities.size(); ++i) {
            if(utilities[i]->getName() == name) {
                utilities.erase(utilities.begin()+i);
                break;
            }
        }
    } else if(type == "Transportation") {
        for(int i = 0; i < transportations.size(); ++i) {
            if(transportations[i]->getName() == name) {
                transportations.erase(transportations.begin()+i);
                break;
            }
        }
    } //else error
    return;
}

shared_ptr<Property> Player:: returnProperty(string name) {
    for(auto &p : properties) {
         if(p->getName() == name) return p;
     }
     return nullptr;
}

shared_ptr<Utility> Player:: returnUtility(string name) {
    for(auto &u : utilities) {
         if(u->getName() == name) return u;
     }
     return nullptr;
}

shared_ptr<Transportation> Player:: returnTransportation(string name) {
    for(auto &t : transportations) {
         if(t->getName() == name) return t;
     }
     return nullptr;
}


int Player::getNumUtilities() { return utilities.size(); }

int Player::getNumTransportations() { return transportations.size(); }

int Player::getNumProperties() { return properties.size(); }

int Player::getPos() { return pos; }

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
        turnsInJail = 0;
        numDoubles = 0;
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
    return inJail;
}

void Player::release() {
    inJail = false;
    turnsInJail = 0;
    return;
}

int Player::getTurnsInJail() { return turnsInJail; }

void Player::setHasGOJFCard() {
    hasGOJFC = true;
    return;
}

void Player::clearHasGOJFCard() {
    hasGOJFC = false;
    return;
}

void Player::print() {
    cout << "Name: "<<name<<endl;
    cout << "Account Balance: "<<money<<endl;
    cout << "Properties Owned: "<<endl;
    int cnt=1;
    if(!properties.empty()) {
        for(auto & p : properties) {
            if (p == properties.back()) {
                cout << "("<< cnt<< ")"<<p->getName() <<endl;
                cnt++;
                break;
            }
            cout << "("<< cnt<< ")"<< p->getName()<<", ";
            cnt++;
        }
    }

    cout << "Utilities Owned: "<<endl;
    if(!utilities.empty()) {
        for(auto & u : utilities) {
            if (u == utilities.back()) {
                cout <<"("<< cnt<< ")"<< u->getName() <<endl;
                cnt++;
                break;
            }
            cout <<"("<< cnt<< ")"<< u->getName()<<", ";
            cnt++;
        }
    }

    cout << "Transportations Owned: "<<endl;
    if(!transportations.empty()) {
        for(auto & t : transportations) {
            if (t == transportations.back()) {
                cout << "("<< cnt<< ")"<<t->getName() <<endl;
                cnt++;
                break;
            }
            cout << "("<< cnt<< ")"<<t->getName()<<", ";
            cnt++;
        }
    }
}

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

