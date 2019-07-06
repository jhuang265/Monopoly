#include "board.h"
#include "./../Player/player.h"
#include "./../Tile/utility.h"
#include "./../Tile/transportation.h"
#include "./../Tile/property.h"
#include "./../Tile/tile.h"
#include "./../Color/color.h"
#include "./../Card/card.h"
#include "./../Card/GetMoneyCard.h"
#include "./../Card/GOJFCard.h"
#include "./../Card/GTJCard.h"
#include "./../Card/MoveCard.h"
#include "./../Card/LoseMoneyCard.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <memory>

Board::Board(int type, int numPlayers): type{type}, numPlayers{numPlayers}, currentPlayer{0}{
    std::string name;

    for(int i = 0; i < numPlayers; ++i){
        std::cout << "Enter the name for Player " << i << ": ";
        std::cin >> name;

        players.emplace_back(std::make_shared<Player>(name, i));
    }

    int initialBuild = (type == 1)? 0: -1;

    std::shared_ptr<Color> brown = std::make_shared<Color>();
    std::shared_ptr<Color> lblue = std::make_shared<Color>();
    std::shared_ptr<Color> pink = std::make_shared<Color>();
    std::shared_ptr<Color> orange = std::make_shared<Color>();
    std::shared_ptr<Color> red = std::make_shared<Color>();
    std::shared_ptr<Color> yellow = std::make_shared<Color>();
    std::shared_ptr<Color> green = std::make_shared<Color>();
    std::shared_ptr<Color> blue = std::make_shared<Color>();

    std::shared_ptr<Tile> d1 = std::make_shared<Tile>("Go", "Go");
    std::shared_ptr<Property> d2 = std::shared_ptr<Property>(new Property(60, {2, 10, 30, 90, 160, 250}, brown, initialBuild, "Property", "P1"));
    std::shared_ptr<Tile> d3 = std::make_shared<Tile>("Income Tax", "Income Tax");
    std::shared_ptr<Property> d4 = std::shared_ptr<Property >(new Property(60, {4, 20, 60, 180, 320, 450}, brown, initialBuild, "Property", "P2"));
    std::shared_ptr<Tile> d5 = std::make_shared<Tile>("Community Chest", "Community Chest");
    std::shared_ptr<Transportation> d6 = std::shared_ptr<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T1"));
    std::shared_ptr<Property> d7 = std::shared_ptr<Property >(new Property(100, {6, 30, 90, 270, 400, 550}, lblue, initialBuild, "Property", "P3"));
    std::shared_ptr<Tile> d8 = std::make_shared<Tile>("Chance", "Chance");
    std::shared_ptr<Property> d9 = std::shared_ptr<Property >(new Property(100, {6, 30, 90, 270, 400, 550}, lblue, initialBuild, "Property", "P4"));
    std::shared_ptr<Property> teen = std::shared_ptr<Property >(new Property(120, {8, 40, 100, 300, 450, 600}, lblue, initialBuild, "Property", "P5"));
    std::shared_ptr<Tile> teen1 = std::make_shared<Tile>("Jail/Visiting", "Jail/Visiting");
    std::shared_ptr<Property> teen2 = std::shared_ptr<Property >(new Property(140, {10, 50, 150, 450, 625, 750}, pink, initialBuild, "Property", "P6"));
    std::shared_ptr<Utility> teen3 = std::shared_ptr<Utility>(new Utility(150, {4, 10}, "Utility", "U1"));
    std::shared_ptr<Property> teen4 = std::shared_ptr<Property >(new Property(140, {10, 50, 150, 450, 625, 750}, pink, initialBuild, "Property", "P7"));
    std::shared_ptr<Property> teen5 = std::shared_ptr<Property >(new Property(160, {12, 60, 180, 500, 700, 900}, pink, initialBuild, "Property", "P8"));
    std::shared_ptr<Transportation> teen6 = std::shared_ptr<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T2"));
    std::shared_ptr<Property> teen7 = std::shared_ptr<Property >(new Property(180, {14, 70, 200, 550, 750, 950}, orange, initialBuild, "Property", "P9"));
    std::shared_ptr<Tile> teen8 = std::make_shared<Tile>("Community Chest", "Community Chest");
    std::shared_ptr<Property> teen9 = std::shared_ptr<Property >(new Property(180, {14, 70, 200, 550, 750, 950}, orange, initialBuild, "Property", "P10"));
    std::shared_ptr<Property> twenty = std::shared_ptr<Property >(new Property(200, {16, 80, 220, 600, 800, 1000}, orange, initialBuild, "Property", "P11"));
    std::shared_ptr<Tile> twenty1 = std::make_shared<Tile>("Free Parking", "Free Parking");
    std::shared_ptr<Property> twenty2 = std::shared_ptr<Property >(new Property(220, {18, 90, 250, 700, 875, 1050}, red, initialBuild, "Property", "P12"));
    std::shared_ptr<Tile> twenty3 = std::make_shared<Tile>("Chance", "Chance");
    std::shared_ptr<Property> twenty4 = std::shared_ptr<Property >(new Property(220, {18, 90, 250, 700, 875, 1050}, red, initialBuild, "Property", "P13"));
    std::shared_ptr<Property> twenty5 = std::shared_ptr<Property >(new Property(240, {20, 100, 300, 750, 925, 1100}, red, initialBuild, "Property", "P14"));
    std::shared_ptr<Transportation> twenty6 = std::shared_ptr<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T3"));
    std::shared_ptr<Property> twenty7 = std::shared_ptr<Property >(new Property(260, {22, 110, 330, 800, 975, 1150}, yellow, initialBuild, "Property", "P15"));
    std::shared_ptr<Property> twenty8 = std::shared_ptr<Property >(new Property(260, {22, 110, 330, 800, 975, 1150}, yellow, initialBuild, "Property", "P16"));
    std::shared_ptr<Utility> twenty9 = std::shared_ptr<Utility>(new Utility(150, {4, 10}, "Utility", "U2"));
    std::shared_ptr<Property> thirty = std::shared_ptr<Property >(new Property(280, {22, 120, 360, 850, 1025, 1200}, yellow, initialBuild, "Property", "P17"));
    std::shared_ptr<Tile> thirty1 = std::make_shared<Tile>("Go To Jail", "Go To Jail");
    std::shared_ptr<Property> thirty2 = std::shared_ptr<Property >(new Property(300, {26, 130, 390, 900, 1100, 1275}, green, initialBuild, "Property", "P18"));
    std::shared_ptr<Property> thirty3 = std::shared_ptr<Property >(new Property(300, {26, 130, 390, 900, 1100, 1275}, green, initialBuild, "Property", "P19"));
    std::shared_ptr<Tile> thirty4 = std::make_shared<Tile>("Community Chest", "Community Chest");
    std::shared_ptr<Property> thirty5 = std::shared_ptr<Property >(new Property(320, {28, 150, 450, 1000, 1200, 1400}, green, initialBuild, "Property", "P20"));
    std::shared_ptr<Transportation> thirty6 = std::shared_ptr<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T4"));
    std::shared_ptr<Tile> thirty7 = std::make_shared<Tile>("Chance", "Chance");
    std::shared_ptr<Property> thirty8 = std::shared_ptr<Property >(new Property(350, {35, 175, 500, 1100, 1300, 1500}, blue, initialBuild, "Property", "P21"));
    std::shared_ptr<Tile> thirty9 = std::make_shared<Tile>("Luxury Tax", "Luxury Tax");
    std::shared_ptr<Property> forty = std::shared_ptr<Property >(new Property(400, {50, 200, 600, 1400, 1700, 2000}, blue, initialBuild, "Property", "P22"));

    utilities.emplace_back(teen3);
    utilities.emplace_back(twenty9);

    transportations.emplace_back(d6);
    transportations.emplace_back(teen6);
    transportations.emplace_back(twenty6);
    transportations.emplace_back(thirty6);

    properties.emplace_back(d2);
    properties.emplace_back(d4);
    properties.emplace_back(d7);
    properties.emplace_back(d9);
    properties.emplace_back(teen);
    properties.emplace_back(teen2);
    properties.emplace_back(teen4);
    properties.emplace_back(teen5);
    properties.emplace_back(teen7);
    properties.emplace_back(teen9);
    properties.emplace_back(twenty);
    properties.emplace_back(twenty2);
    properties.emplace_back(twenty4);
    properties.emplace_back(twenty5);
    properties.emplace_back(twenty7);
    properties.emplace_back(twenty8);
    properties.emplace_back(thirty);
    properties.emplace_back(thirty2);
    properties.emplace_back(thirty3);
    properties.emplace_back(thirty5);
    properties.emplace_back(thirty8);
    properties.emplace_back(forty);

    brown->attach(d2);
    brown->attach(d4);
    lblue->attach(d7);
    lblue->attach(d9);
    lblue->attach(teen);
    pink->attach(teen2);
    pink->attach(teen4);
    pink->attach(teen5);
    orange->attach(teen7);
    orange->attach(teen9);
    orange->attach(twenty);
    red->attach(twenty2);
    red->attach(twenty4);
    red->attach(twenty5);
    yellow->attach(twenty7);
    yellow->attach(twenty8);
    yellow->attach(thirty);
    green->attach(thirty2);
    green->attach(thirty3);
    green->attach(thirty5);
    blue->attach(thirty8);
    blue->attach(forty);

    colors.emplace_back(lblue);
    colors.emplace_back(brown);
    colors.emplace_back(pink);
    colors.emplace_back(orange);
    colors.emplace_back(yellow);
    colors.emplace_back(red);
    colors.emplace_back(green);
    colors.emplace_back(blue);
/*
    tiles.emplace_back(d1);
    tiles.emplace_back(d2);
    tiles.emplace_back(d3);
    tiles.emplace_back(d4);
    tiles.emplace_back(d5);
    tiles.emplace_back(d6);
    tiles.emplace_back(d7);
    tiles.emplace_back(d8);
    tiles.emplace_back(d9);
    tiles.emplace_back(teen);
    tiles.emplace_back(teen1);
    tiles.emplace_back(teen2);
    tiles.emplace_back(teen3);
    tiles.emplace_back(teen4);
    tiles.emplace_back(teen5);
    tiles.emplace_back(teen6);
    tiles.emplace_back(teen7);
    tiles.emplace_back(teen8);
    tiles.emplace_back(teen9);
    tiles.emplace_back(twenty);
    tiles.emplace_back(twenty1);
    tiles.emplace_back(twenty2);
    tiles.emplace_back(twenty3);
    tiles.emplace_back(twenty4);
    tiles.emplace_back(twenty5);
    tiles.emplace_back(twenty6);
    tiles.emplace_back(twenty7);
    tiles.emplace_back(twenty8);
    tiles.emplace_back(twenty9);
    tiles.emplace_back(thirty);
    tiles.emplace_back(thirty1);
    tiles.emplace_back(thirty2);
    tiles.emplace_back(thirty3);
    tiles.emplace_back(thirty4);
    tiles.emplace_back(thirty5);
    tiles.emplace_back(thirty6);
    tiles.emplace_back(thirty7);
    tiles.emplace_back(thirty8);
    tiles.emplace_back(thirty9);
    tiles.emplace_back(forty);
*/
}

int Board::rollDice(){
    srand(time(0));
    return (rand()%6) + 1;
}

void Board::rollDiceAndAction(){
    if(players[currentPlayer]->getTurnsInJail() == 3){
        players[currentPlayer]->release();
    }

    if(players[currentPlayer]->isInJail()){
        char yn;
        std::cout << "You are in jail. Would you like to pay your way out? (Y/N): ";
        std::cin >> yn;
        if(yn == 'Y' && players[currentPlayer]->getMoney() >= 50){
            players[currentPlayer]->payMoney(50);
            players[currentPlayer]->release();
            std::cout << "You are now out of jail." << std::endl;
        }
    }

    int firstRoll = rollDice();
    int secondRoll = rollDice();

    if(firstRoll != secondRoll && players[currentPlayer]->isInJail()){
        players[currentPlayer]->addTurnInJail();
        return;
    }
    else if(firstRoll == secondRoll && players[currentPlayer]->isInJail()){
        players[currentPlayer]->release();
    }
    else if(firstRoll == secondRoll){
        players[currentPlayer]->rolledDoubles();
    }
    else{
        players[currentPlayer]->resetDoubles();
    }

    if(players[currentPlayer]->getDoubles() == 3){
        players[currentPlayer]->goToJail();
        players[currentPlayer]->resetDoubles();
        return;
    }

    players[currentPlayer]->move(firstRoll+secondRoll);

    int pos = players[currentPlayer]->getPos();

    int cardLocations[] = {2, 8, 17, 22, 33, 36};
    int transLocations[] = {5, 15, 25, 35};
    int utilLocations[] = {12, 28};
    int propertyLocations[] = {1, 3, 6, 8, 9, 11, 13, 14, 16, 18, 19, 21, 23, 24, 26, 27, 29, 31, 32, 34, 37, 39};

/*d2);
    properties.emplace_back(d4);
    properties.emplace_back(d7);
    properties.emplace_back(d9);
    properties.emplace_back(teen);
    properties.emplace_back(teen2);
    properties.emplace_back(teen4);
    properties.emplace_back(teen5);
    properties.emplace_back(teen7);
    properties.emplace_back(teen9);
    properties.emplace_back(twenty);
    properties.emplace_back(twenty2);
    properties.emplace_back(twenty4);
    properties.emplace_back(twenty5);
    properties.emplace_back(twenty7);
    properties.emplace_back(twenty8);
    properties.emplace_back(thirty);
    properties.emplace_back(thirty2);
    properties.emplace_back(thirty3);
    properties.emplace_back(thirty5);
    properties.emplace_back(thirty8);
    properties.emplace_back(forty);*/

    loseMoneyCard c1{};
    getMoneyCard c2{};
    GOJFCard c3{};
    GTJCARD c4{};
    moveCard c5{};

    for(int i = 0; i < 6; ++i){
        if(pos == cardLocations[i]){
            srand(time(0));
            int rNum = (rand()%5+1);

            if(rNum == 1) c1.use(players[currentPlayer]);
            else if(rNum == 2) c2.use(players[currentPlayer]);
            else if(rNum == 3) c3.use(players[currentPlayer]);
            else if(rNum == 4) c4.use(players[currentPlayer]);
            else if(rNum == 5) c5.use(players[currentPlayer]);

            /*
            cards[]->use(players[currentPlayer]);
            */
            return;
        }
    }

    pos = players[currentPlayer]->getPos();

    switch(pos){
        case 0:
            //players[currentPlayer].getMoney(200);
            break;
        case 4:
            players[currentPlayer]->payMoney(200);
            break;
        case 10:
            break;
        case 20:
            break;
        case 30:
            players[currentPlayer]->goToJail();
            break;
        case 38:
            players[currentPlayer]->payMoney(150);
            break;
    }


    for(int i = 0; i < 4; ++i){
        if(pos == transLocations[i]){
            if(transportations[i]->getIsOwned()){
                players[currentPlayer]->payMoney(transportations[i]->getRent());

                for(auto j = players.begin(); j != players.end(); ++j){
                    if((*j)->getIndex() == transportations[i]->getOwnerIndex()){
                        (*j)->receiveMoney(transportations[i]->getRent());
                    }
                }
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getRent());
                return;
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned transportation. Would you like to buy it? (Y/N): ";
                std::cin >> yn;
                if(yn == 'Y' && players[currentPlayer]->getMoney() >= transportations[i]->getPrice()){
                    transportations[i]->buy(players[currentPlayer]);
                }
                else{
                    auction(transportations[i]);
                }
                return;
            }
        }
    }

    for(int i = 0; i < 2; ++i){
        if(pos == utilLocations[i]){
            if(utilities[i]->getIsOwned()){
                players[currentPlayer]->payMoney(utilities[i]->getUtilityRent(firstRoll+secondRoll));
                for(auto j = players.begin(); j != players.end(); ++j){
                    if((*j)->getIndex() == utilities[i]->getOwnerIndex()){
                        (*j)->receiveMoney(utilities[i]->getUtilityRent(firstRoll+secondRoll));
                    }
                }
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getRent());
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getUtilityRent(firstRoll+secondRoll));
                return;
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned utility. Would you like to buy it? (Y/N): ";
                std::cin >> yn;
                if(yn == 'Y' && players[currentPlayer]->getMoney() >= utilities[i]->getPrice()){
                    utilities[i]->buy(players[currentPlayer]);
                }
                else{
                    auction(utilities[i]);
                }
                return;
            }
        }
    }

    for(int i = 0; i < 22; ++i){
        if(pos == propertyLocations[i]){
            if(properties[i]->getIsOwned()){
                players[currentPlayer]->payMoney(properties[i]->getRent());
                for(auto j = players.begin(); j != players.end(); ++j){
                    if((*j)->getIndex() == properties[i]->getOwnerIndex()){
                        (*j)->receiveMoney(properties[i]->getRent());
                    }
                }
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getRent());

                if(players[currentPlayer]->getIndex() == properties[i]->getOwner()->getIndex()){
                    if(properties[i]->getCanBuild()){
                        if((properties[i]->getHouses()+1) * 50 > players[currentPlayer]->getMoney()){
                            char yn;
                            std::cout << "You have enough money to buy a new house. Would you like to buy it? (Y/N): ";
                            std::cin >> yn;
                            if(yn == 'Y'){
                                properties[i]->buyHouse();
                            }
                        }
                    }
                }
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned property. Would you like to buy it? (Y/N): ";
                std::cin >> yn;
                if(yn == 'Y' && players[currentPlayer]->getMoney() >= properties[i]->getPrice()){
                    properties[i]->buy(players[currentPlayer]);
                }
                else{
                    auction(tiles[pos]);
                }
                return;
            }
        }
    }
}

void Board::playTurn(){
    char playerChoice;
    while(players.size() > 1){
        currentPlayer = 0;
        for(auto i = players.begin(); i != players.end() && players.size() > 1; ){
            printCurPlayerStatus();
            cout<<"1) Play without trading (enter A)"<<endl;
            cout<<"2) Do you want to trade?(enter B)"<<endl;
            cout<<"3) Do you want to quit? (enter C)"<<endl;
            cin>>playerChoice;
            while(playerChoice!= 'A' && playerChoice!= 'B' && playerChoice!= 'C'){
                cin>>playerChoice;
            }
            if (playerChoice=='C'){
                i = players.erase(i);
                continue;
            }
            else if(playerChoice == 'B'){
                trade(*i);
            }
            rollDiceAndAction();
            if((*i)->getMoney() < 0){
                i = players.erase(i);
                continue;
            }
            while((*i)->getDoubles() > 0 && (*i)->getDoubles() < 3){
                if((*i)->getMoney() < 0){
                    i = players.erase(i);
                    break;
                }
                rollDiceAndAction();
            }
            currentPlayer = (currentPlayer+1) % players.size();

        }
    }
}

void Board::trade(shared_ptr<Player> player){
    char inputChar;
    int desiredMoney;
    int targetPlayerIndex;
    shared_ptr<Player> targetPlayer;
    vector<int> tradeList;
    cout<<"Here is the list of properties/utilities/transportations you can trade: "<<endl;
    player->printAsset();
    cout<<"Enter the assets you want to trade by corresponding number and and e to end: "<<endl;
    while(cin>>inputChar){
        if(inputChar=='e'){
            if(tradeList.size()==0){
                return;
            }
            break;
        }
        else if((int)inputChar > (player.getNumProperties() + player.getNumUtilities() + player.getNumTransportations())){
            continue;
        }
        else{
            if((int)inputChar<= getNumProperties){
                tradeList.emplace_back(player->propertyNameAtIndex((int)inputChar-1));
            }
            else if((int)inputChar < getNumProperties+getNumUtilities ){
                tradeList.emplace_back(player->utilityNameAtIndex((int)inputChar-player.getNumProperties()-1));
            }
            else{
                tradeList.emplace_back(player->transportationNameAtIndex((int)inputChar-(player.getNumProperties() + player.getNumUtilities())-1));
            }
        }
    }
    cout<<"Select the player you want to trade with (enter their number):"<<endl;
    for(int p = 0 ; p < players.size() ; p++){
        cout<<p+1<< " " << players[p]->getName()<<endl;
    }
    while (cin>>targetPlayerIndex){
        if(targetPlayerIndex>player.size()){
            cout<<"Please re-enter player index: ";
            continue;
        }
        break;
    }
    --targetPlayerIndex;
    targetPlayer = players[targetPlayerIndex];
    cout<<"Enter the money you want to get from " << targetPlayer->getName()<<endl;
    while(cin>>desiredMoney){
        if(desiredMoney > player->getMoney()){
            cout<<"Not enough money, please re-enter a value: ";
            continue;
        }
        break;

    }
    cout<<"Player "<< targetPlayer->getName()<< ", do you agree to change "<< desiredMoney << "with "<< player->getName()<<"(Y/N)"<<endl;
    while(cin>>inputChar){
        if(inputChar!='Y' && inputChar!= 'N'){
            cout<<"Invalid input, please re-enter: ";
        }
        break;
    }
    if(inputChar=='N'){
        return;
    }
    else{
        player->payMoney(desiredMoney);
        targetPlayer->receiveMoney(desiredMoney);
        for(int x = 0; x < tradeList.size(); x++){
            (player->returnAsset(tradeList[x]))->changeOwner(targetPlayer);
        }
        cout<< "Trade Successful"<<endl;
    }
}

void Board::auction(std::shared_ptr<Tile> t){
    int maxBid = 0;
    int maxPlayerIndex = currentPlayer;
    vector <int> remaining;
    for(int i = 0; i < players.size(); ++i){
        remaining.push_back(i);
    }

    for(int i = currentPlayer; remaining.size() != 1; ++i){
        int bid;

        std::cout << "Player " << remaining[i] << " please enter your bid. (If you don't want to participate, enter -1): ";
        std::cin >> bid;
        if(bid <= -1){
            for(auto j = remaining.begin(); j != remaining.end(); ++i){
                if ((*j) == remaining[i]){
                    remaining.erase(j);
                }
            }
            //remaining.erase(i);
            --i;
        }
        if(bid > players[currentPlayer]->getMoney()){
            cout << "Invalid bid" << endl;
        }
        if(bid > maxBid){
            maxBid = bid;
            maxPlayerIndex = remaining[i];
        }

        if(i == remaining.size()-1){
            i = -1;
        }
    }

    t->buy(players[remaining[0]]);

    return;
}

Board::~Board(){}
