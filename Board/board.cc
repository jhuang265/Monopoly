#include "board.h"
#include "./../Player/player.h"
#include "./../Tile/utility.h"
#include "./../Tile/transportation.h"
#include "./../Tile/property.h"
#include "./../Tile/tile.h"
#include "./../Color/color.h"
#include "./../Card/card.h"
#include "./../Card/getMoneyCard.h"
#include "./../Card/GOJFCard.h"
#include "./../Card/GTJCard.h"
#include "./../Card/moveCard.h"
#include "./../Card/loseMoneyCard.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <random>
#include <memory>
#include <map>
<<<<<<< Updated upstream
using namespace std;
map<int,int> boardPos; //pos, rowNum
map<char,pair<int,int> >playerPos; // playerNum : < rowNum, colNum(tileNum) >
map<pair<int,int>,int> targetPos; // rowNum:ColNum, playerNum
map<int,int> replacePos; //rowNum, colNum
=======

//map<int,int> boardPos; //pos, rowNum
//map<char,pair<int,int> >playerPos; // playerNum : < rowNum, colNum(tileNum) >
//map<pair<int,int>,int> targetPos; // rowNum:ColNum, playerNum
//map<int,int> replacePos; //rowNum, colNum
>>>>>>> Stashed changes

Board::Board(int type, int numPlayers): type{type}, numPlayers{numPlayers}, currentPlayer{0}{
    std::string name;

    for(int i = 0; i < numPlayers; i++){
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

    std::vector<int> rents{2, 10, 30, 90, 160, 250};

    std::shared_ptr<Property> d2 = std::make_shared<Property>(60, rents, brown, initialBuild, "Property", "P1");
    std::shared_ptr<Tile> d3 = std::make_shared<Tile>("Income Tax", "Income Tax");

    rents = {4, 20, 60, 180, 320, 450};
    std::shared_ptr<Property> d4 = std::make_shared<Property >(60, rents, brown, initialBuild, "Property", "P2");
    std::shared_ptr<Tile> d5 = std::make_shared<Tile>("Community Chest", "Community Chest");

    std::vector<int> rentsTrans{25, 50, 100, 200};
    std::shared_ptr<Transportation> d6 = std::make_shared<Transportation>(200, rents, "Transportation", "T1");

    rents = {6, 30, 90, 270, 400, 550};
    std::shared_ptr<Property> d7 = std::make_shared<Property >(100, rents, lblue, initialBuild, "Property", "P3");

    std::shared_ptr<Tile> d8 = std::make_shared<Tile>("Chance", "Chance");

    rents = {6, 30, 90, 270, 400, 550};
    std::shared_ptr<Property> d9 = std::make_shared<Property >(100, rents, lblue, initialBuild, "Property", "P4");

    rents = {8, 40, 100, 300, 450, 600};
    std::shared_ptr<Property> teen = std::make_shared<Property >(120, rents, lblue, initialBuild, "Property", "P5");

    std::shared_ptr<Tile> teen1 = std::make_shared<Tile>("Jail/Visiting", "Jail/Visiting");

    rents = {10, 50, 150, 450, 625, 750};
    std::shared_ptr<Property> teen2 = std::make_shared<Property >(140, rents, pink, initialBuild, "Property", "P6");

    vector<int> rentsUtils {4, 10};
    std::shared_ptr<Utility> teen3 = std::make_shared<Utility>(150, rentsUtils, "Utility", "U1");

    std::shared_ptr<Property> teen4 = std::make_shared<Property >(140, rents, pink, initialBuild, "Property", "P7");

    rents = {12, 60, 180, 500, 700, 900};
    std::shared_ptr<Property> teen5 = std::make_shared<Property >(160, rents, pink, initialBuild, "Property", "P8");

    std::shared_ptr<Transportation> teen6 = std::make_shared<Transportation>(200, rentsTrans, "Transportation", "T2");

    rents = {14, 70, 200, 550, 750, 950};
    std::shared_ptr<Property> teen7 = std::make_shared<Property >(180, rents, orange, initialBuild, "Property", "P9");

    std::shared_ptr<Tile> teen8 = std::make_shared<Tile>("Community Chest", "Community Chest");

    std::shared_ptr<Property> teen9 = std::make_shared<Property >(180, rents, orange, initialBuild, "Property", "P10");

    rents = {16, 80, 220, 600, 800, 1000};
    std::shared_ptr<Property> twenty = std::make_shared<Property >(200, rents, orange, initialBuild, "Property", "P11");

    std::shared_ptr<Tile> twenty1 = std::make_shared<Tile>("Free Parking", "Free Parking");

    rents = {18, 90, 250, 700, 875, 1050};
    std::shared_ptr<Property> twenty2 = std::make_shared<Property >(220, rents, red, initialBuild, "Property", "P12");

    std::shared_ptr<Tile> twenty3 = std::make_shared<Tile>("Chance", "Chance");

    std::shared_ptr<Property> twenty4 = std::make_shared<Property >(220, rents, red, initialBuild, "Property", "P13");

    rents = {20, 100, 300, 750, 925, 1100};
    std::shared_ptr<Property> twenty5 = std::make_shared<Property >(240, rents, red, initialBuild, "Property", "P14");

    std::shared_ptr<Transportation> twenty6 = std::make_shared<Transportation>(200, rentsTrans, "Transportation", "T3");

    rents = {22, 110, 330, 800, 975, 1150};
    std::shared_ptr<Property> twenty7 = std::make_shared<Property >(260, rents, yellow, initialBuild, "Property", "P15");

    std::shared_ptr<Property> twenty8 = std::make_shared<Property >(260, rents, yellow, initialBuild, "Property", "P16");

    std::shared_ptr<Utility> twenty9 = std::make_shared<Utility>(150, rentsUtils, "Utility", "U2");

    rents = {22, 120, 360, 850, 1025, 1200};
    std::shared_ptr<Property> thirty = std::make_shared<Property >(280, rents, yellow, initialBuild, "Property", "P17");

    std::shared_ptr<Tile> thirty1 = std::make_shared<Tile>("Go To Jail", "Go To Jail");

    rents = {26, 130, 390, 900, 1100, 1275};
    std::shared_ptr<Property> thirty2 = std::make_shared<Property >(300, rents, green, initialBuild, "Property", "P18");

    std::shared_ptr<Property> thirty3 = std::make_shared<Property >(300, rents, green, initialBuild, "Property", "P19");

    std::shared_ptr<Tile> thirty4 = std::make_shared<Tile>("Community Chest", "Community Chest");

    rents = {28, 150, 450, 1000, 1200, 1400};
    std::shared_ptr<Property> thirty5 = std::make_shared<Property >(320, rents, green, initialBuild, "Property", "P20");

    std::shared_ptr<Transportation> thirty6 = std::make_shared<Transportation>(200, rentsTrans, "Transportation", "T4");

    std::shared_ptr<Tile> thirty7 = std::make_shared<Tile>("Chance", "Chance");

    rents = {35, 175, 500, 1100, 1300, 1500};
    std::shared_ptr<Property> thirty8 = std::make_shared<Property >(350, rents, blue, initialBuild, "Property", "P21");

    std::shared_ptr<Tile> thirty9 = std::make_shared<Tile>("Luxury Tax", "Luxury Tax");

    rents = {50, 200, 600, 1400, 1700, 2000};
    std::shared_ptr<Property> forty = std::make_shared<Property >(400, rents, blue, initialBuild, "Property", "P22");

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

}

int Board::rollDice(){
    //srand(time(NULL));
    //return (rand()%6) + 1;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

void Board::checkOwnership(){
    for(int i = 0; i < utilities.size(); i++){
        if(utilities[i]->getIsOwned()){
            cout << utilities[i]->getName() << ": " << utilities[i]->getOwnerIndex() << endl;
        }
    }
    for(int i = 0; i < transportations.size(); i++){
        if(transportations[i]->getIsOwned()){
            cout << transportations[i]->getName() << ": " << transportations[i]->getOwnerIndex() << endl;
        }
    }
    for(int i = 0; i < properties.size(); i++){
        if(properties[i]->getIsOwned()){
            cout << properties[i]->getName() << ": " << properties[i]->getOwnerIndex() << endl;
        }
    }
    return;
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
    cout << "You rolled: " << firstRoll << " and " << secondRoll << endl;

    if(firstRoll != secondRoll && players[currentPlayer]->isInJail()){
        std::cout << "You did not roll a double, so you're stuck in jail." << std::endl;
        players[currentPlayer]->addTurnInJail();
        std::cout << "Turns you have been in jail: "<< players[currentPlayer]->getTurnsInJail() << std::endl;
        return;
    }
    else if(firstRoll == secondRoll && players[currentPlayer]->isInJail()){
        std::cout << "You rolled a double so you're out of jail now." << std::endl;
        players[currentPlayer]->release();
        players[currentPlayer]->rolledDoubles();
    }
    else if(firstRoll == secondRoll){
        players[currentPlayer]->rolledDoubles();
        cout << "You rolled a double!" << endl;
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
    //players[currentPlayer]->move(1);

    int pos = players[currentPlayer]->getPos();

    cout << '\n' << "New Position: " << pos << '\n' << endl;

    int cardLocations[] = {2, 7, 17, 22, 33, 36};
    int transLocations[] = {5, 15, 25, 35};
    int utilLocations[] = {12, 28};
    int propertyLocations[] = {1, 3, 6, 8, 9, 11, 13, 14, 16, 18, 19, 21, 23, 24, 26, 27, 29, 31, 32, 34, 37, 39};

    loseMoneyCard c1{};
    getMoneyCard c2{};
    GOJFCard c3{};
    GTJCard c4{};
    moveCard c5{};

    for(int i = 0; i < 6; i++){
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
            break;
        case 4:
            cout << "You had to pay 200$ in income tax." << endl;
            players[currentPlayer]->payMoney(200);
            break;
        case 10:
            cout << "Visiting jail." << endl;
            break;
        case 20:
            cout << "Free Parking" << endl;
            break;
        case 30:
            cout << "You are sent to jail." << endl;
            players[currentPlayer]->goToJail();
            break;
        case 38:
            cout << "You had to pay 150$ in luxury tax." << endl;
            players[currentPlayer]->payMoney(150);
            break;
    }


    for(int i = 0; i < 4; i++){
        if(pos == transLocations[i]){
            if(transportations[i]->getIsOwned()){
                cout << "You have to pay rent for landing on owned transportation." << endl;

                cout << "Money Before: " << players[currentPlayer]->getMoney() << endl;
                players[currentPlayer]->payMoney(transportations[i]->getRent());
                cout << "Rent: " << transportations[i]->getRent() << endl;
                cout << "Money Left: " << players[currentPlayer]->getMoney() << endl;

                for(auto j = players.begin(); j != players.end(); j++){
                    if((*j)->getIndex() == transportations[i]->getOwnerIndex()){
                        cout << "Owner Money Before: " << (*j)->getMoney() << endl;
                        (*j)->receiveMoney(transportations[i]->getRent());
                        cout << "Owner Money After: " << (*j)->getMoney() << endl;
                    }
                }
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getRent());
                return;
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned transportation " << transportations[i]->getName() <<". Would you like to buy it? (Y/N): ";
                std::cin >> yn;
                if(yn == 'Y' && players[currentPlayer]->getMoney() >= transportations[i]->getPrice()){
                    cout << "Money Before: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Cost: " << transportations[i]->getPrice() << endl;
                    transportations[i]->buy(players[currentPlayer]);
                    cout << "Money Left: " << players[currentPlayer]->getMoney() << endl;
                }
                else{
                    auction(transportations[i]);
                }
                return;
            }
        }
    }

    for(int i = 0; i < 2; i++){
        if(pos == utilLocations[i]){
            if(utilities[i]->getIsOwned()){
                cout << "You have to pay rent for landing on owned utility." << endl;

                cout << "Money Before: " << players[currentPlayer]->getMoney() << endl;
                cout << "Rent: " << utilities[i]->getUtilityRent(firstRoll+secondRoll) << endl;
                players[currentPlayer]->payMoney(utilities[i]->getUtilityRent(firstRoll+secondRoll));
                cout << "Money Left: " << players[currentPlayer]->getMoney() << endl;

                for(auto j = players.begin(); j != players.end(); j++){
                    if((*j)->getIndex() == utilities[i]->getOwnerIndex()){
                        cout << "Owner Money Before: " << (*j)->getMoney() << endl;
                        (*j)->receiveMoney(utilities[i]->getUtilityRent(firstRoll+secondRoll));
                        cout << "Owner Money After: " << (*j)->getMoney() << endl;
                    }
                }
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getRent());
                //players[tiles[pos]->getOwnerIndex()]->receiveMoney(tiles[pos]->getUtilityRent(firstRoll+secondRoll));
                return;
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned utility " << utilities[i]->getName() <<". Would you like to buy it? (Y/N): ";
                std::cin >> yn;
                if(yn == 'Y' && players[currentPlayer]->getMoney() >= utilities[i]->getPrice()){
                    cout << "Money Before: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Cost: " << utilities[i]->getPrice() << endl;
                    utilities[i]->buy(players[currentPlayer]);
                    cout << "Money Left: " << players[currentPlayer]->getMoney() << endl;
                }
                else{
                    auction(utilities[i]);
                }
                return;
            }
        }
    }

    for(int i = 0; i < 22; i++){
        if(pos == propertyLocations[i]){
            if(properties[i]->getIsOwned()){
                cout << "You have to pay rent for landing on owned property." << endl;

                cout << "Money Before: " << players[currentPlayer]->getMoney() << endl;
                cout << "Cost: " << properties[i]->getRent() << endl;
                players[currentPlayer]->payMoney(properties[i]->getRent());
                cout << "Money Left: " << players[currentPlayer]->getMoney() << endl;

                for(auto j = players.begin(); j != players.end(); j++){
                    if((*j)->getIndex() == properties[i]->getOwnerIndex()){
                        cout << "Owner Money Before: " << (*j)->getMoney() << endl;
                        (*j)->receiveMoney(properties[i]->getRent());
                        cout << "Owner Money After: " << (*j)->getMoney() << endl;
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
                std::cout << "You have landed on an unowned property " << properties[i]->getName() <<". Would you like to buy it? (Y/N): ";
                std::cin >> yn;
                if(yn == 'Y' && players[currentPlayer]->getMoney() >= properties[i]->getPrice()){
                    cout << "Money Before: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Cost: " << properties[i]->getPrice() << endl;
                    properties[i]->buy(players[currentPlayer]);
                    cout << "Money Left: " << players[currentPlayer]->getMoney() << endl;
                }
                else{
                    auction(properties[i]);
                }
                return;
            }
        }
    }
}

//bool hasPlayerOnRow(int rowNum) {
//    for(int i=65; i < 69; ++i) {
//        cerr <<"playerPos[i].first: "<<playerPos[i].first<<" rowNum: "<<rowNum<<endl;
//        if(playerPos[i].first == rowNum) return true;
//    }
//    return false;
//}

//every tile has width  12 and height 4
void Board::printBoard() {
    map<int,int> boardPos; //pos, rowNum
    map<char,pair<int,int> >playerPos; // playerNum : < rowNum, colNum(tileNum) >
    map<pair<int,int>,int> targetPos; // rowNum:ColNum, playerNum
    map<int,int> replacePos; //rowNum, colNum

    int countLine = 5;

    //boardPos Insertion
    for(int i=0; i < 20; i++) {
        if(i <= 10) {
            boardPos.insert(pair<int,int>(i, 41));
            boardPos.insert(pair<int,int>(30-i, 1));
        }
        else if(i > 10 && i < 20) {
            boardPos.insert(pair<int,int>(i, countLine));
            boardPos.insert(pair<int,int>(50-i, countLine));
        }
    }

    //playerPos Insertion
    int c = 65;
    // playerPos   playerNum : < rowNum, colNum(tileNum) >
    for(auto& p : players) {
        int rowNum = boardPos[p->getPos()];
        playerPos.insert(pair<int,pair<int,int> >(c, pair<int,int>(rowNum, p->getPos())));
        ++c;
    }

    //targetPos: Set resulting replace index on a row in the string
    c = 65;
    for(c; c<69; ++c) {
//        cerr <<"HEYYYYY: playerPos[i].first: "<<playerPos[c].first<<endl;
        int colNum = (playerPos[c].second)%10 + 1;
        int targetColNum = colNum*12 - 8;
//        cerr<<"colNum: "<<colNum<<endl;
        if(playerPos.count(c)) {
            while (targetPos.count(pair<int,int>(playerPos[c].first, targetColNum))) {
                ++targetColNum;
            }
            int rowNum = playerPos[c].first;
//            cerr<<"targetPos---------"<<"("<<rowNum<<", "<<targetColNum<<")"<<" "<<c<<endl;
            targetPos.insert(pair<pair<int,int>,int> (pair<int,int>(rowNum, targetColNum), c));
            replacePos.insert(pair<int,int>(rowNum, targetColNum));
//            ++c;
        }
    }

    c = 65;
    string boarder = " |++++++++++++|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|++++++++++++|\n";
    string line1 = " |            |                                                                                                       |            |\n";
    string line2 = " |            |            |            |            |            |            |            |            |            |            |\n";
    string divider = " |++++++++++++|                                                                                                       |++++++++++++|\n";

    //output board, x: rowNum; y: colNum (horizontal)
    cout << boarder;
    for(int x = 0; x <= 41; ++x) {
        if(x%4 == 1) {
//            cerr << " Entered mod 4 = 1"<<endl;
            bool hasPlayerOnRow = false;
            for(int i=65; i < 69; ++i) {
//                cerr <<"playerPos[i].first: "<<playerPos[i].first<<" rowNum(x): "<<x<<endl;
                if(playerPos[i].first == x) hasPlayerOnRow = true;
            }
            if(hasPlayerOnRow) {
                string line;
                if(x > 39 || x < 3) { line = line2; }
                else { line = line1; }
                int y = replacePos[x];
                int playerNum = targetPos[pair<int,int>(x,y)];
                char playerIndex = char(playerNum);
                cerr << "Has Player on Row: x,y "<<x<<" "<<y<<" playerIndex: "<<targetPos[pair<int,int>(x,y)] << " |"<<playerIndex<<endl;
                string replacedLine = line;
                replacedLine.at(y) = playerIndex;
                cout << replacedLine;
//                cerr << "Has Player on Row: Replace "<<y<<endl;
            }
        } else if(x == 3 || x == 39) { cout << boarder;}
        else if(x%4 == 3){
            cout << divider;
        } else if(x > 39 || x < 3) { cout << line2; }
        else { cout << line1; }
    }
    cout << boarder;

  /*  cout << " |++++++++++++|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|++++++++++++|\n"
            " |            |            |            |            |            |            |            |            |            |            |\n"
           1 " |            |            |            |            |            |            |            |            |            |            |\n"
            " |            |            |            |            |            |            |            |            |            |            |\n"
          3  " |++++++++++++|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
            5" |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
         7   " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
          9  " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
          11  " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
        13    " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
         17   " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
         21   " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
        25    " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
     29       " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
        33    " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|                                                                                                       |++++++++++++|\n"
            " |            |                                                                                                       |            |\n"
       37     " |            |                                                                                                       |            |\n"
            " |            |                                                                                                       |            |\n"
            " |++++++++++++|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|++++++++++++|\n"
            " |            |            |            |            |            |            |            |            |            |            |\n"
       41     " |            |            |            |            |            |            |            |            |            |            |\n"
            " |            |            |            |            |            |            |            |            |            |            |\n"
            " |++++++++++++|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|++++++++++++|\n";
*/
   }

void Board::playTurn(){
    char playerChoice;
    while(players.size() > 1){
        currentPlayer = 0;
        for(auto i = players.begin(); i != players.end() && players.size() > 1; ){
            printBoard();
            cout<< endl;
            cout<< "-------------------------------------------------" << endl;
            cout<< "Player "<< (*i)->getIndex()+1 << "'s turn." << endl;
            (*i)->print();//prints status of cur player
            cout<<endl;

            cout<<"1) Play without trading (enter A)"<<endl;
            cout<<"2) Do you want to trade? (enter B)"<<endl;
            cout<<"3) Do you want to quit? (enter C)"<<endl;
            cout<<"Enter your choice: ";
            cin>>playerChoice;

            cout << '\n';
            checkOwnership();
            cout << '\n';

            while(playerChoice!= 'A' && playerChoice!= 'B' && playerChoice!= 'C'){
                cout<<"Please enter a valid action: ";
                cin>>playerChoice;
            }
            if (playerChoice=='C'){

                for(auto j = properties.begin(); j != properties.end(); j++){
                    if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                        (*j)->reset();
                    }
                }

                for(auto j = utilities.begin(); j != utilities.end(); j++){
                    if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                        (*j)->reset();
                    }
                }

                for(auto j = transportations.begin(); j != transportations.end(); j++){
                    if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                        (*j)->reset();
                    }
                }

                i = players.erase(i);
                continue;
            }
            else if(playerChoice == 'B'){
                trade(*i);
            }
            rollDiceAndAction();
            cout << "Current Player's Money: "<<(*i)->getMoney()<< endl;
            if((*i)->getMoney() < 0){

                for(auto j = properties.begin(); j != properties.end(); j++){
                    if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                        (*j)->reset();
                    }
                }

                for(auto j = utilities.begin(); j != utilities.end(); j++){
                    if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                        (*j)->reset();
                    }
                }

                for(auto j = transportations.begin(); j != transportations.end(); j++){
                    if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                        (*j)->reset();
                    }
                }

                i = players.erase(i);
                continue;
            }
            while((*i)->getDoubles() > 0 && (*i)->getDoubles() < 3){
                cout << "You get an extra roll for rolling a double." << endl;
                cout << '\n';
                cout << "Doubles rolled: " << (*i)->getDoubles() << endl;
                if((*i)->getMoney() < 0){

                    for(auto j = properties.begin(); j != properties.end(); j++){
                        if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                            (*j)->reset();
                        }
                    }

                    for(auto j = utilities.begin(); j != utilities.end(); j++){
                        if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                            (*j)->reset();
                        }
                    }

                    for(auto j = transportations.begin(); j != transportations.end(); j++){
                        if((*j)->getIsOwned() && (*j)->getOwnerIndex() == (*i)->getIndex()){
                            (*j)->reset();
                        }
                    }

                    i = players.erase(i);
                    break;
                }
                rollDiceAndAction();
            }
            ++i;
            cout<< "-------------------------------------------------" << endl;
            currentPlayer = (currentPlayer+1) % players.size();

        }
    }

    cout << "The winner is Player "<< players[0]->getIndex() << endl;
    return;
}



void Board::trade(shared_ptr<Player> player){
    char inputChar;
    int desiredMoney;
    int targetPlayerIndex;
    shared_ptr<Player> targetPlayer;
    vector<string> tradeList;
    if(player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations() == 0){
        cout<<"Oops! You have no assets to trade. Your dice is now rolled"<<endl;
        return;
    }
    //cout<<"Here is the list of properties/utilities/transportations you can trade: "<<endl;
    //player->printAsset();
    cout<<"Enter the assets you want to trade by corresponding number and and e to end: "<<endl;
    cin>>inputChar;
    while(inputChar!='e'){
    //   cout<<"firstreads in "<< inputChar<<endl;
     //  cout<< "propert total: "<< player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations()<<endl;
      // cout<<(int)inputChar*4<< endl;
        if((int)inputChar-48 <= (player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations())){
          
            if((int)inputChar-48<= player->getNumProperties()){
                tradeList.emplace_back(player->propertyNameAtIndex((int)inputChar-48-1));
            }
            else if((int)inputChar-48 < player->getNumProperties()+player->getNumUtilities() ){
                tradeList.emplace_back(player->utilityNameAtIndex((int)inputChar-48-player->getNumProperties()-1));
            }
            else{
                tradeList.emplace_back(player->transportationNameAtIndex((int)inputChar-48-(player->getNumProperties() + player->getNumUtilities())-1));
            }
        }
        
        cin>>inputChar;
    }
    if(tradeList.size()==0){
        return;
    }
    cout<<"Select the player you want to trade with (enter their number):"<<endl;
    cout<<"size of players "<< players.size()<<endl;
    for(int p = 0 ; p < players.size() ; p++){
        if(players[p]->getIndex() == player->getIndex()){
            continue;
        }
        cout<<p+1<< ") " << players[p]->getName()<<endl;
    }
    cin>>targetPlayerIndex;
    while (targetPlayerIndex > players.size() ){
        cout<<"Please re-enter player number: ";
        cin>>targetPlayerIndex;

    }
    --targetPlayerIndex;
    targetPlayer = players[targetPlayerIndex];
    cout<<"Enter the money you want to get from " << targetPlayer->getName()<<": "<<endl;
    while(cin>>desiredMoney){
        if(desiredMoney > targetPlayer->getMoney()){
            cout<<targetPlayer->getName() <<" does not have this amount to trade. Please re-enter a valid value: ";
            continue;
        }
        break;

    }

    cout<<"Player "<< targetPlayer->getName()<< ", do you agree to change "<< desiredMoney << "with "<< player->getName()<<" (Y/N) "<<endl;
    cin>>inputChar;
    while(inputChar!='Y' && inputChar!= 'N'){
        cout<<"Invalid input, please re-enter: ";  
        cin>>inputChar;
    }
    if(inputChar=='N'){
        return;
    }
    else{

        player->receiveMoney(desiredMoney);
        targetPlayer->payMoney(desiredMoney);
        for(int x = 0; x < tradeList.size(); x++){
            if(getAssetType(tradeList[x]) == "Transportation"){
              //  cout<< "trade"<< tradeList[x]<<endl;
              //  cout<< "property name"<< (player->returnTransportation(tradeList[x]))->getName()<<endl;
                (player->returnTransportation(tradeList[x]))->changeOwner(targetPlayer);
            }
            else if(getAssetType(tradeList[x]) == "Property" ){
            //    cout<< "trade"<< tradeList[x]<<endl;
            //    cout<< "property name"<< (player->returnProperty(tradeList[x]))->getName()<<endl;
                (player->returnProperty(tradeList[x]))->changeOwner(targetPlayer);
            }
            else{
                // cout<< "trade"<< tradeList[x]<<endl;
                // cout<< "property name"<< (player->returnUtility(tradeList[x]))->getName()<<endl;
                (player->returnUtility(tradeList[x]))->changeOwner(targetPlayer);
            }
        }
    } 
    
    cout<< "Trade Successful"<<endl;
}

void Board::auction(std::shared_ptr<Tile> t){

    cout << "Entered an auction phase" << endl;

    int maxBid = 0;
    int maxPlayerIndex = currentPlayer;
    vector <int> remaining;
    for(int i = 0; i < players.size(); i++){
        remaining.push_back(i);
    }

    for(int i = currentPlayer; remaining.size() != 0; i++){
        //cout << "Remaining bidders: " << remaining.size() << endl;
        //cout << "Current Bidder Index: " << i << endl;

        //cout<< "Current Max Bid: " << maxBid <<endl;
        //cout<< "Current Max Bidder: " << maxPlayerIndex <<endl;
        int bid;

        std::cout << "Player " << remaining[i] << " please enter your bid. (If you want to stop bidding, enter -1): ";
        std::cin >> bid;
        if (!cin.good()){
            bid = 0;
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //i = i-1;
            //continue;
            cout << "Invalid bid. Please wait your turn to bid again." << endl;
        }

        if(bid > players[i]->getMoney()){
            cout << "Invalid bid. You don't have the money to make this." << endl;
        }
        else if(bid > maxBid){
            maxBid = bid;
            maxPlayerIndex = remaining[i];
        }

        //cout << remaining.size() << endl;
        if(bid <= -1){
            //cout << "Erasing User" << endl;
            for(auto j = remaining.begin(); j != remaining.end();){
                //cout << (*j) << endl;
                if ((*j) == remaining[i]){
                    //cout << "Found user to delete" << endl;
                    j = remaining.erase(j);
                    break;
                }
                else{
                    j++;
                }
            }
            //remaining.erase(i);
            //cout << "Decreasing Index" << endl;
            --i;
            //cout << "Decreased Index" << endl;

        }

        if(i == remaining.size()-1){
            i = -1;
        }
        //cout << remaining.size() << endl;
    }

    if(maxBid == 0){
        cout << "The asset could not be auctioned off."<<endl;
        return;
    }
    cout << "Sold to Player "<< maxPlayerIndex << " for " << maxBid <<"$."<<endl;
    t->buy(players[maxPlayerIndex]);

    return;
}

<<<<<<< Updated upstream
string Board::getAssetType( string name){
    for(int i = 0; i < properties.size(); i++) {
        if(properties[i]->getName() == name) {
            return properties[i]->getType();
        }
    }

    for(int i = 0; i < utilities.size(); i++) {
        if(utilities[i]->getName() == name) {
            return utilities[i]->getType();
        }
    }

    for(int i = 0; i < transportations.size(); i++) {
        if(transportations[i]->getName() == name) {
            return transportations[i]->getType();
        }
    }
}

Board::~Board(){}
