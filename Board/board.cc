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
#include <limits>
#include <memory>
#include <map>
using namespace std;

Board::Board(int type, int numPlayers): numPlayers{numPlayers}, currentPlayer{0}{
    map<int,string> playerEmojiInit;
    std::string name;
    playerEmojiInit.insert(pair<int,string>(0,"\U0001F914"));
    playerEmojiInit.insert(pair<int,string>(1,"\U0001F60E"));
    playerEmojiInit.insert(pair<int,string>(2,"\U0001F608"));
    playerEmojiInit.insert(pair<int,string>(3,"\U0001F951"));
    playerEmojiInit.insert(pair<int,string>(4,"\U0001F47B"));
    playerEmojiInit.insert(pair<int,string>(5,"\U0001F984"));
    // Get all the user's names
    for(int i = 0; i < numPlayers; i++){
        std::cout << playerEmojiInit[i] <<" Enter the name for Player "<< (i+1) << ": ";
        std::cin >> name;
        auto player = std::make_shared<Player>(name, i);
        players.emplace_back(player);
        /*
        if(find(players.begin(), players.end(), player) != players.end()) {
            std::cout << "~ Please enter a different name ~"<<endl;
            i--;
        } else {
            players.emplace_back(player);
        }
        */
    }

    // Set up the board and all the tiles
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

    // Use a uniform distribution to get two random dice roll numbers
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

void Board::checkOwnership(){
    for(size_t i = 0; i < utilities.size(); i++){
        if(utilities[i]->getIsOwned()){
            cout << utilities[i]->getName() << ": " << utilities[i]->getOwnerIndex() << endl;
        }
    }
    for(size_t i = 0; i < transportations.size(); i++){
        if(transportations[i]->getIsOwned()){
            cout << transportations[i]->getName() << ": " << transportations[i]->getOwnerIndex() << endl;
        }
    }
    for(size_t i = 0; i < properties.size(); i++){
        if(properties[i]->getIsOwned()){
            cout << properties[i]->getName() << ": " << properties[i]->getOwnerIndex() << endl;
        }
    }
    return;
}

void Board::rollDiceAndAction(){
    // If the player has been in jail for 3 turns, free them and let them play their turn
    if(players[currentPlayer]->getTurnsInJail() == 3){
        players[currentPlayer]->release();
    }

    // If they still are in jail, ask if they want to pay their way out.
    if(players[currentPlayer]->isInJail()){
        char yn;
        std::cout << "You are in jail. Would you like to pay your way out? (Y/N): ";
        std::cin >> yn;
        if((yn == 'Y' || yn == 'y') && players[currentPlayer]->getMoney() >= 50){
            players[currentPlayer]->payMoney(50);
            players[currentPlayer]->release();
            std::cout << "You are now out of jail." << std::endl;
        }
        else{
            std::cout << "You have to say in jail." << std::endl;
        }
    }

    // Roll the dice twice and show the user
    int firstRoll = rollDice();
    int secondRoll = rollDice();

    // If it wasn't a double and the user is still in jail, they have to stay in jail for a turn
    if(firstRoll != secondRoll && players[currentPlayer]->isInJail()){
        std::cout << "You did not roll a double, so you're stuck in jail." << std::endl;
        players[currentPlayer]->addTurnInJail();
        std::cout << "Turns you have been in jail: "<< players[currentPlayer]->getTurnsInJail() << std::endl;
        return;
    }
    // If they rolled a double, then free the player if they are in jail and increase the number of doubles they have rolled
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

    // If the player has rolled 3 doubles in a row, send them to jail.
    if(players[currentPlayer]->getDoubles() == 3){
        players[currentPlayer]->goToJail();
        players[currentPlayer]->resetDoubles();
        return;
    }

    // Move the player and get their new position
    players[currentPlayer]->move(firstRoll+secondRoll);
    int pos = players[currentPlayer]->getPos();

    //printBoard();

    cout << "You rolled: " << firstRoll << " and " << secondRoll << endl;
    cout << '\n' << "New Position: " << pos << '\n' << endl;
    cout<<endl;

    // Set the location of cards, transportations, utilities and properties
    int cardLocations[] = {4, 7, 17, 22, 33, 36};
    int transLocations[] = {5, 15, 25, 35};
    int utilLocations[] = {12, 28};
    int propertyLocations[] = {1, 3, 6, 8, 9, 11, 13, 14, 16, 18, 19, 21, 23, 24, 26, 27, 29, 31, 32, 34, 37, 39};

    LoseMoneyCard c1{};
    GetMoneyCard c2{};
    GTJCard c3{};
    GOJFCard c4{};
    MoveCard c5{};

    // If the player landed on a card, use it and return
    for(size_t i = 0; i < 6; i++){
        if(pos == cardLocations[i]){
            srand(time(0));
            int rNum = (rand()%5+1);

            //cards[rNum]->use(players[currentPlayer]);

            if(rNum == 1) c1.use(players[currentPlayer]);
            else if(rNum == 2) c2.use(players[currentPlayer]);
            else if(rNum == 3) c3.use(players[currentPlayer]);
            else if(rNum == 4) c4.use(players[currentPlayer]);
            else if(rNum == 5) {
                c5.use(players[currentPlayer]);
                printBoard();
            }

            return;
        }
    }

    pos = players[currentPlayer]->getPos();

    // For some predefined tiles, these are the actions that they should perform.
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
            printBoard();
            break;
        case 38:
            cout << "You had to pay 150$ in luxury tax." << endl;
            players[currentPlayer]->payMoney(150);
            break;
    }

    // Check if the player landed on a transportation
    for(size_t i = 0; i < 4; i++){
        if(pos == transLocations[i]){
            // If owned, pay rent
            if(transportations[i]->getIsOwned() && players[currentPlayer]->getIndex() != transportations[i]->getOwnerIndex()){
                cout << "You have to pay rent for landing on owned transportation." << endl;

                cout << "Money before paying rent: " << players[currentPlayer]->getMoney() << endl;
                players[currentPlayer]->payMoney(transportations[i]->getRent());
                cout << "Rent: " << transportations[i]->getRent() << endl;
                cout << "Money after paying rent: " << players[currentPlayer]->getMoney() << endl;


                for(auto j = players.begin(); j != players.end(); j++){
                    if((*j)->getIndex() == transportations[i]->getOwnerIndex()){
                        (*j)->receiveMoney(transportations[i]->getRent());
                    }
                }

                return;
            }
            else if (transportations[i]->getIsOwned()){
                return;
            }
            // Otherwise ask if the player wants to buy it
            else{
                char yn;
                std::cout << "You have landed on an unowned transportation " << transportations[i]->getName() <<" that costs $"<<
                                transportations[i]->getPrice()<<    ". Would you like to buy it? (Y/N): ";
                std::cin >> yn;

                // See if the user can buy it without needing to go through an auction
                if( (yn == 'Y' || yn == 'y') && players[currentPlayer]->getMoney() >= transportations[i]->getPrice()){
                    cout << "Money before purchase: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Cost: " << transportations[i]->getPrice() << endl;
                    transportations[i]->buy(players[currentPlayer]);
                    players[currentPlayer]->addTransportation(transportations[i]->getptr());
                    cout << "Money after purchase: " << players[currentPlayer]->getMoney() << endl;
                }
                else{
                    auction(transportations[i]);
                }
                return;
            }
        }
    }

    // Do the same for utilities
    for(size_t i = 0; i < 2; i++){
        if(pos == utilLocations[i]){
            if(utilities[i]->getIsOwned() && players[currentPlayer]->getIndex() != utilities[i]->getOwnerIndex()){
                cout << "You have to pay rent for landing on an owned utility." << endl;

                cout << "Money before rent: " << players[currentPlayer]->getMoney() << endl;
                cout << "Rent you had to pay: " << utilities[i]->getUtilityRent(firstRoll+secondRoll) << endl;
                players[currentPlayer]->payMoney(utilities[i]->getUtilityRent(firstRoll+secondRoll));
                cout << "Money after rent: " << players[currentPlayer]->getMoney() << endl;


                for(auto j = players.begin(); j != players.end(); j++){
                    if((*j)->getIndex() == utilities[i]->getOwnerIndex()){
                        (*j)->receiveMoney(utilities[i]->getUtilityRent(firstRoll+secondRoll));
                    }
                }

                return;
            }
            else if (utilities[i]->getIsOwned()){
                return;
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned utility " << utilities[i]->getName() <<" that costs $"<<
                                            utilities[i]->getPrice()<<". Would you like to buy it? (Y/N): ";
                std::cin >> yn;

                if((yn == 'Y' || yn == 'y')  && players[currentPlayer]->getMoney() >= utilities[i]->getPrice()){
                    cout << "Money before purchase: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Cost: " << utilities[i]->getPrice() << endl;
                    utilities[i]->buy(players[currentPlayer]);
                    players[currentPlayer]->addUtility(utilities[i]->getptr());
                    cout << "Money after purchase: " << players[currentPlayer]->getMoney() << endl;
                }
                else{
                    auction(utilities[i]);
                }
                return;
            }
        }
    }

    // Same for properties
    for(size_t i = 0; i < 22; i++){
        if(pos == propertyLocations[i]){
            if(properties[i]->getIsOwned()){
                if(players[currentPlayer]->getIndex() != properties[i]->getOwnerIndex()){
                    cout << "You have to pay rent for landing on owned property." << endl;

                    cout << "Money before paying rent: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Rent to pay: " << properties[i]->getRent() << endl;
                    players[currentPlayer]->payMoney(properties[i]->getRent());
                    cout << "Money after paying rent: " << players[currentPlayer]->getMoney() << endl;

                    for(auto j = players.begin(); j != players.end(); j++){
                        if((*j)->getIndex() == properties[i]->getOwnerIndex()){
                            (*j)->receiveMoney(properties[i]->getRent());
                        }
                    }
                }
                // If you are the property owner and you can build houses, then you are allowed to buy
                else{
                    if(properties[i]->getCanBuild() != 0){
                        if((properties[i]->getHouses()+1) * 50 <= players[currentPlayer]->getMoney()){
                            char yn;
                            std::cout << "You have enough money to buy a new house. Would you like to buy it? (Y/N): ";
                            std::cin >> yn;
                            if((yn == 'Y' || yn == 'y')){
                                players[currentPlayer]->payMoney((properties[i]->getHouses()+1) * 50);
                                properties[i]->buyHouse();
                            }
                        }
                    }
                }
            }
            else{
                char yn;
                std::cout << "You have landed on an unowned property " << properties[i]->getName() <<" that costs $"<<
                                                            properties[i]->getPrice()    <<". Would you like to buy it? (Y/N): ";
                std::cin >> yn;

                if((yn == 'Y' || yn == 'y') && players[currentPlayer]->getMoney() >= properties[i]->getPrice()){
                    cout << "Money before purchase: " << players[currentPlayer]->getMoney() << endl;
                    cout << "Cost: " << properties[i]->getPrice() << endl;
                    properties[i]->buy(players[currentPlayer]);
                    players[currentPlayer]->addProperty(properties[i]->getptr());
                    cout << "Money after purchase: " << players[currentPlayer]->getMoney() << endl;
                }
                else{
                    auction(properties[i]);
                }
                return;
            }
        }
    }
}

//every tile has width  12 and height 4
void Board::printBoard() {
    map<int,int> boardPos; //pos, rowNum
    map<char,pair<int,int> >playerPos; // playerNum : < rowNum, colNum(tileNum) >
    map<pair<int,int>,int> targetPos; // rowNum:ColNum, playerNum
    map<int,int> replacePos; //rowNum, colNum
    map<int,int> tilesPos; //rowNum, left tileNum
    map<int, string> playerEmoji;
    map<int, pair<pair<int,int>,string> > playerLocations; //playerNum, <rowNum, colNum>, playerIndex

    int countRow = 5;

    //Insert tile names
    int tileRow = 36;
    for(int i = 11; i < 20; ++i) {
        tilesPos.insert(pair<int,int>(tileRow, i));
        tileRow -= 4;
    }

    //Insert player emojis
    playerEmoji.insert(pair<int,string>(65,"\U0001F914"));
    playerEmoji.insert(pair<int,string>(66,"\U0001F60E"));
    playerEmoji.insert(pair<int,string>(67,"\U0001F608"));
    playerEmoji.insert(pair<int,string>(68,"\U0001F951"));
    playerEmoji.insert(pair<int,string>(69,"\U0001F47B"));
    playerEmoji.insert(pair<int,string>(70,"\U0001F984"));

    //boardPos Insertion: tileNumber and rowNum
    for(int i = 0; i < 21; i++) {
        if(i <= 10) {
            boardPos.insert(pair<int,int>(i, 41));
            boardPos.insert(pair<int,int>(30-i, 1));
        }
        else if(i > 10 && i < 21) {
            boardPos.insert(pair<int,int>(i, 42-countRow));
            boardPos.insert(pair<int,int>(50-i, 42-countRow));
            countRow += 4;
        }
    }
    //playerPos Insertion
    int c = 65;
    // playerPos   playerLetter : < rowNum, colNum(tileNum) >
    for(auto& p : players) {
        int rowNum = boardPos[p->getPos()];
        playerPos.insert(pair<int,pair<int,int> >(c, pair<int,int>(rowNum, p->getPos())));
        ++c;
    }

    //targetPos: Set resulting replace index on a row in the string
    c = 65;
    for(int i=0; i < numPlayers; ++i) {
        int colNum = (playerPos[c].second)%10 + 1;;
        int targetColNum = colNum*12; //-8 if L -> R
        if(playerPos.count(c)) {
            while (targetPos.count(pair<int,int>(playerPos[c].first, targetColNum))) {
                ++targetColNum;
            }
            int rowNum = playerPos[c].first;
            targetPos.insert(pair<pair<int,int>,int> (pair<int,int>(rowNum, targetColNum), c));
            replacePos.insert(pair<int,int>(c, targetColNum));
            ++c;
        }
    }

    string boarder = " |++++++++++++|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    string line1 =   " |            |                                                                                                                    |            |\n";
    string line2 =   " |            |            |            |            |            |            |            |            |            |            |            |\n";
    string divider = " |++++++++++++|                                                                                                                    |++++++++++++|\n";
    //output board, x: rowNum; y: colNum (horizontal)
    //yPos also refers to position in x direction
    cout << boarder;
    for(int x = 0; x <= 42; ++x) {
        if(x % 4 == 0) {
            string tileNameLine = " |";
            if(x == 0) {
                for(int i = 20; i <= 30; ++i) {
                    string tileName = "";
                    tileName = tiles.at(i)->getName();
                    if(tileName == "Community Chest") {tileName = "Chest"; }
                    while(tileName.length() < 12) {
                        tileName += " ";
                    }
                    tileNameLine += tileName;
                    tileNameLine += "|";
                }
            } else if(x == 40) {
                for(int i = 10; i >= 0; --i) {
                    string tileName = "";
                    tileName = tiles.at(i)->getName();
                    if(tileName == "Community Chest") {tileName = "Chest";}
                    else if(tileName == "Jail/Visiting") {tileName = "Jail"; }
                    while(tileName.length() < 12) {
                        tileName += " ";
                    }
                    tileNameLine += tileName;
                    tileNameLine += "|";
                }
            } else {
                int tileNum = tilesPos[x];
                string leftTile = tiles.at(tileNum)->getName();
                if(leftTile == "Community Chest") {leftTile = "Chest";}
                string rightTile = tiles.at(50-tileNum)->getName();
                if(rightTile == "Community Chest") {rightTile = "Chest";}

                while(leftTile.length() < 12) {
                    leftTile += " ";
                }
                leftTile += "|";

                while(rightTile.length() < 12) {
                    rightTile += " ";
                }
                rightTile += "|";

                tileNameLine += leftTile;
                while(tileNameLine.length() <= 130) {
                    tileNameLine += " ";
                }
                tileNameLine += "|";
                tileNameLine += rightTile;
            }
            cout << tileNameLine<<endl;
        }
        else if(x % 4 == 1) {
            string playerIndex = "";
            string line = "";
            bool hasPlayerAtLine = false;
            c = 65;
                while ((c-65) < numPlayers) {
                    playerIndex = "";
                    string playerSymbol = playerEmoji[c];
                    playerIndex += playerSymbol;
                    playerIndex += char(c);
                    int rowNum = playerPos[c].first;
                    int colNum = players[c-65]->getPos();
                    playerLocations.insert(pair<int,pair< pair<int,int>, string> >(c,pair< pair<int,int>,string > (pair<int,int>(rowNum,colNum), playerIndex)));
                    if(playerPos[c].first == x) hasPlayerAtLine = true;
                    c++;
                }
//            for(auto & p : playerLocations) {
//                cerr<<p.first<<" "<<p.second.first.first<<" "<<p.second.first.second<<" "<<p.second.second<<endl;
//            }
            if(x > 39 || x < 3) { line = line2; } else { line = line1; }

            if(hasPlayerAtLine){
                for(auto & loc : playerLocations) {
                    if (x == loc.second.first.first) {
                        int yPos = -1;
                        int posIndex = loc.second.first.second;
                        int y = replacePos[loc.first];
                        string playerName = loc.second.second;
                        string replacedLine = line;
                        if (x == 41 && posIndex != 10 && posIndex != 0) {
                            yPos = line.length() - 12 * (++posIndex) - 4;
//                            cerr << "posIndex, yPos: " << posIndex << " " << yPos << endl;
//                            cerr << "currentPlayer = " << currentPlayer + 65 << " int x = " << x << " int y = " << y
//                                 << endl;
                            if (replacedLine.at(yPos) == '|') { yPos++; }
                        } else if (x == 1) {
                            yPos = y - 4;
                            if (replacedLine.at(yPos) == '|') { yPos++; }
                        } else {
                            if (posIndex >= 10 && posIndex <= 20) { yPos = 6; }
                            else if ((posIndex > 30 && posIndex < 41) || posIndex == 0) { yPos = 136; }
                        }
                        replacedLine.replace(yPos, 3, playerName); //+(numPlayers-1) for displaying multiple players
                        cout << replacedLine;
                    }
                }
            }else {cout << line; }
        }
        else if(x == 3 || x == 39) { cout << boarder;}
        else if(x % 4 == 3){
            cout << divider;
        }
        else if(x > 39 || x < 3) { cout << line2; }
        else { cout << line1; }
    }
    cout << boarder;
   }

void Board::playTurn(){
    // Character to allow user to make a decision
    char playerChoice;
    string temp;

    // Keep playing as long as there exist multiple players
    while(players.size() > 1){
        // Start with the first player
        currentPlayer = 0;

        // Keep playing as long as you haven't reached the end
        for(auto i = players.begin(); i != players.end() && players.size() > 1; ){

            cout << endl;
            printBoard();
            cout << endl;

            // Prompt user to make a choice
            cout << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "Player " << (*i)->getIndex()+1 << "'s turn." << endl;
            (*i)->print();//prints status of cur player
            cout << endl;

            cout << "What would you like to do?" << endl;
            cout << "1) Play without trading (enter A)" << endl;
            cout << "2) Do you want to trade? (enter B)" << endl;
            cout << "3) Do you want to quit? (enter C)" << endl;
            cout << "Enter your choice: ";
            cin >> playerChoice;

            //checkOwnership();
            cout << '\n';

            // Make user enter valid choide
            while(playerChoice != 'A' && playerChoice != 'B' && playerChoice != 'C'){
                cout << "Please enter a valid action: ";
                cin >> playerChoice;
            }

            // If they want to quit, then free all their assets and remove them from the players
            if (playerChoice=='C'){
                i = players.erase(i);
                continue;
            }
            else if(playerChoice == 'B'){
                char choice;
                cout << "-----------TRADE CENTRE-----------" << endl;
                cout << "You have two options for trade: " << endl;
                cout << "1)Trade your current assets for money of another player (Enter 1)" << endl;
                cout << "2)Trade your current assets and money with another player (Enter 2)" << endl;
                cout << "Enter the type of trade you would like to conduct: ";
                cin >> choice;
                while(choice != '1' && choice != '2' ){
                    cout << "Please enter a valid choice: ";
                    cin >> choice;
                }
                if(choice == '1'){
                    tradeAssetForMoney(*i);
                }
                else{
                    tradeAssetForAsset(*i);
                }
            }

            // Once they have made a trade, or chose to roll directly, play their turn

            // Roll dice and move
            rollDiceAndAction();

            // If the current player's money is negative, free their assets and remove player
            //cout << "Money at end of turn: "<<(*i)->getMoney()<< endl;
            if((*i)->getMoney() < 0){
                i = players.erase(i);
                continue;
            }

            // If the user rolled a double, let them roll again
            while((*i)->getDoubles() > 0 && (*i)->getDoubles() < 3){
                //cout << '\n' << endl;
                cout << "-------------------------------------------------" << endl;
                cout << "You get an extra roll for rolling a double. (Press ENTER to Continue)";
                cin.ignore();
                getline(std::cin, temp);
                cout << "-------------------------------------------------" << endl;
                cout << "Doubles rolled: " << (*i)->getDoubles() << endl;

                // We must check again if they have no more money and if so, free their assets
                if((*i)->getMoney() < 0){
                    i = players.erase(i);
                    break;
                }
                rollDiceAndAction();
            }
            // Move to the next player
            ++i;
            cout << "-------------------------------------------------" << endl;
            cout << "Press ENTER to continue to next Player's turn ";
            cin.ignore();
            getline(std::cin, temp);
            currentPlayer = (currentPlayer+1) % players.size();

        }
    }

    // If the game is over, name the winner.
    cout << "The winner is "<< players[0]->getName() << endl;
    return;
}

void Board::tradeAssetForAsset(shared_ptr<Player> player){
    char inputChar;
    string temp;
    int targetPlayerIndex;
    shared_ptr<Player> targetPlayer;
    vector<string> targetTradeList;
    vector<string> tradeList;
    cout << "************************************************" << endl;
    //if player has no asset to trade, return
    if(player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations() == 0){
        cout<<"Oops! You have no assets to trade. You are returned to your dice roll."<<endl;
        cout<< "Press ENTER to continue to roll your dice ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }
    cout << endl;
    cout << "Here is your status and all your assets:" << endl;
    player->print();
    cout << endl;
    cout<<"Enter the assets you want to trade by corresponding number and enter 'e' to end: "<<endl;
    cin>>inputChar;

    //push back the vector while the player enters the assets he want to trade
    while(inputChar!='e'){
        if((int)inputChar-48 <= (player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations())){

            if((int)inputChar-48<= player->getNumProperties()){
                tradeList.emplace_back(player->propertyNameAtIndex((int)inputChar-48-1));
            }
            else if((int)inputChar-48 <= player->getNumProperties()+player->getNumUtilities() ){
                tradeList.emplace_back(player->utilityNameAtIndex((int)inputChar-48-player->getNumProperties()-1));
            }
            else{
                tradeList.emplace_back(player->transportationNameAtIndex((int)inputChar-48-(player->getNumProperties() + player->getNumUtilities())-1));
            }
        }

        cin>>inputChar;
    }

    //if there is no valid assets to trade in the vector, kick player out
    if(tradeList.size()==0){
        cout<<"None of the property index you entered is valid. You're returned to your dice roll."<<endl;
        cout<< "Press ENTER to continue to roll your dice ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }
    cout << "************************************************" << endl;
    cout<<"Select a player from the following list you want to trade with (enter their number):"<<endl;
    //print out the available players to trade with
    for(size_t p = 0 ; p < players.size() ; p++){
        if(players[p]->getIndex() == player->getIndex()){
            continue;
        }
        cout<< "Player " << players[p]->getName()<<" ("<<"Number "<< p+1<<")"<<endl;
    }
    cin>>targetPlayerIndex;

    //must enter a valid player from the list of players
    while ((targetPlayerIndex < 1 || targetPlayerIndex > players.size())|| targetPlayerIndex == player->getIndex()+1 ){
        cout<<"Please re-enter player number: ";
        cin>>targetPlayerIndex;

    }
    --targetPlayerIndex;//subtract the input index by one to get the actual matching index of the player in the game
    targetPlayer = players[targetPlayerIndex];

    //if the player that the current player wants to trade with does not have any assset, then return
    if(targetPlayer->getNumProperties() + targetPlayer->getNumUtilities() + targetPlayer->getNumTransportations() == 0){
        cout << "************************************************" << endl;
        cout<<"Oops! This player has no asset, you are returned to dice roll"<<endl;
        cout<< "Press ENTER to continue to roll your dice ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }
    cout << "************************************************" << endl;
    cout << "Here is the status and assets of  " << targetPlayer->getName()<<endl;
    targetPlayer->print();
    cout<<endl;
    cout<<"Enter the assets you want from this player and enter 'e' to end: "<<endl;

    //push back the desired assets of the target player according to the input
    cin>>inputChar;
    while(inputChar!='e'){
        if((int)inputChar-48 <= (targetPlayer->getNumProperties() + targetPlayer->getNumUtilities() + targetPlayer->getNumTransportations())){

            if((int)inputChar-48<= targetPlayer->getNumProperties()){
                targetTradeList.emplace_back(targetPlayer->propertyNameAtIndex((int)inputChar-48-1));
            }
            else if((int)inputChar-48 <= targetPlayer->getNumProperties()+targetPlayer->getNumUtilities() ){
                targetTradeList.emplace_back(targetPlayer->utilityNameAtIndex((int)inputChar-48-targetPlayer->getNumProperties()-1));
            }
            else{
                targetTradeList.emplace_back(targetPlayer->transportationNameAtIndex((int)inputChar-48-(targetPlayer->getNumProperties() + targetPlayer->getNumUtilities())-1));
            }
        }
        cin >> inputChar;
    }

    //kick player out when the input assets index are invalid AKA empty
    if(targetTradeList.size()==0){
        cout << "None of the property indices you entered are valid. Return to your dice roll." << endl;
        cout << "Press ENTER to continue to roll your dice ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }

    //asks the player to enter the amount of money he wants to get from the target player, input must be valid
    int desiredMoney;
    cout << "Enter the money you would like to recieve from Player " << targetPlayer->getName() << " (Enter negative amount to pay money to other party): " << endl;
    while(cin >> desiredMoney){
        if(desiredMoney <= 0 && (desiredMoney + targetPlayer->getMoney()) < 0){
            cout << "You do not have this amount to trade. Please re-enter a valid value: ";
            continue;
        }
        else if(desiredMoney > 0 && desiredMoney > targetPlayer->getMoney()){
            cout << targetPlayer->getName() <<" does not have this amount to trade. Please re-enter a valid value: ";
            continue;
        }
        break;
    }

    //asks the target player if he agrees to trade
    cout << "************************************************" << endl;
    cout << "Player " << targetPlayer->getName() << ", do you agree to change the following assets and money with Player " << player->getName()<<"? " << endl;
    cout << endl;

    //prints the assets and money being traded
    cout << "You give up:";
    for(size_t x = 0; x < targetTradeList.size(); x++){
        cout << targetTradeList[x] << endl;
    }
    if(desiredMoney > 0){
        cout << "Money you give: $" << desiredMoney << endl;
    }
    cout << endl;
    cout << "You get:";
    for(size_t x = 0; x < tradeList.size(); x++){
        cout << tradeList[x] << endl;
    }
    if(desiredMoney < 0){
        cout << "Money you get: $" << desiredMoney << endl;
    }

    //ask the target player if he agrees to trade
    cout<<"Enter Y/N: ";
    cin>>inputChar;
    while(inputChar!='Y' && inputChar!= 'N'){
        cout<<"Invalid input, please re-enter: ";
        cin>>inputChar;
    }

    //if the target player doesnt want to trade, the function is returned
    if(inputChar=='N'){
        cout << "Player " << targetPlayer->getName() << " does not want to trade with you. " << endl;
        cout << "Press ENTER to continue to your dice roll ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }

    //trade the properties between the two players by looping the two vectors, and call changeOwner method for each property
    for(size_t x = 0; x < tradeList.size(); x++){
        (player->returnAsset(tradeList[x]))->changeOwner(targetPlayer);
    }

    for(size_t x = 0; x < targetTradeList.size(); x++){
        (targetPlayer->returnAsset(targetTradeList[x]))->changeOwner(player);
    }

    //trade the money that was being agreed upon
    player->receiveMoney(desiredMoney);
    targetPlayer->payMoney(desiredMoney);

    cout<< "Trade Successful"<<endl;
    cout << "************************************************" << endl;
    cout<< "Press ENTER to continue to your dice roll ";
    cin.ignore();
    getline(std::cin, temp);
    cout << "************************************************" << endl;
}

void Board::tradeAssetForMoney(shared_ptr<Player> player){
    char inputChar;
    string temp;
    int desiredMoney;
    int targetPlayerIndex;
    shared_ptr<Player> targetPlayer;
    vector<string> tradeList;

    cout << "************************************************" << endl;
    //if the player has no asset to trade, kick him out
    if(player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations() == 0){
        cout<<"Oops! You have no assets to trade. You are returned to your dice roll."<<endl;
        cout<< "Press ENTER to continue to roll your dice ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }
    cout << endl;
    cout << "Here is your status and all your assets:" << endl;
    player->print();
    cout << endl;

    cout << "Enter the assets you want to trade by corresponding number. Then enter \'e\' when you have entered all the properties you wish to trade: "<<endl;
    cin >> inputChar;

    //accepts the index of the asset and emplace back the name of the asset to the vector tradeList
    while(inputChar!='e'){
        if((int)inputChar-48 <= (player->getNumProperties() + player->getNumUtilities() + player->getNumTransportations())){

            if((int)inputChar-48<= player->getNumProperties()){
                tradeList.emplace_back(player->propertyNameAtIndex((int)inputChar-48-1));
            }
            else if((int)inputChar-48 <= player->getNumProperties()+player->getNumUtilities() ){
                tradeList.emplace_back(player->utilityNameAtIndex((int)inputChar-48-player->getNumProperties()-1));
            }
            else{
                tradeList.emplace_back(player->transportationNameAtIndex((int)inputChar-48-(player->getNumProperties() + player->getNumUtilities())-1));
            }
        }

        cin>>inputChar;
    }

    //if the player didnt enter a valid asset to trade, then he is kicked out
    if(tradeList.size()==0){
        cout<<"None of the property indices you entered is valid. The trade is cancelled and you return to your dice roll."<<endl;
        cout<< "Press ENTER to roll the dice ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }
    cout << "************************************************" << endl;
    cout<<"Select a player from the following list whom you want to trade with (enter their number):"<<endl;

    //prints out the avaliable players to trade
    for(size_t p = 0 ; p < players.size() ; p++){
        if(players[p]->getIndex() == player->getIndex()){
            continue;
        }
        cout<< "Player " << players[p]->getName()<<" ("<<"Number "<< p+1<<")"<<endl;
    }
    cout << '\n' << "Enter player you would like to trade with: " << endl;
    cin>>targetPlayerIndex;

    //checks if the index entered is a valid player
    while ((targetPlayerIndex < 1 || targetPlayerIndex > players.size())|| targetPlayerIndex == player->getIndex()+1 ){
        cout<<"Please re-enter player number: ";
        cin>>targetPlayerIndex;

    }
    --targetPlayerIndex;//subtract the input index by one to get the actual matching index of the player in the game
    targetPlayer = players[targetPlayerIndex];
    cout << "************************************************" << endl;
    cout<<"Enter the money you would like to exchange from Player " << targetPlayer->getName()<<": "<<endl;

    //takes in valid money value limited by the target player's amount
    while(cin>>desiredMoney){
        if(desiredMoney > targetPlayer->getMoney()){
            cout << targetPlayer->getName() <<" does not have this amount to trade. Please re-enter a valid value: ";
            continue;
        }
        break;
    }

    cout << "************************************************" << endl;
    cout << "Player "<< targetPlayer->getName()<< ", do you agree to change $"<< desiredMoney << " with Player "<< player->getName()<<"? (Y/N)"<<endl;
    cout << endl;
    cout << "You get:";
    for(size_t x = 0; x < tradeList.size(); x++){
        cout << tradeList[x] << endl;
    }
    cin >> inputChar;

    //must input valid choice
    while(inputChar!='Y' && inputChar!= 'N'){
        cout << "Invalid input, please re-enter: ";
        cin >> inputChar;
    }

    //if the target player disagree with trading, then exit, otherwise, proceed with trade
    if(inputChar=='N'){
        cout<<"Player "<<targetPlayer->getName()<<"does not want to trade with you. "<<endl;
        cout<< "Press ENTER to continue to your dice roll ";
        cin.ignore();
        getline(std::cin, temp);
        cout << "************************************************" << endl;
        return;
    }
    else{
        player->receiveMoney(desiredMoney);
        targetPlayer->payMoney(desiredMoney);
        for(size_t x = 0; x < tradeList.size(); x++){
            (player->returnAsset(tradeList[x]))->changeOwner(targetPlayer);
        }
    }

    cout<< "Trade Successful"<<endl;
    cout<< "The updated amount of of money Player "<<player->getName()<<" has: " << player->getMoney()<<endl;
    cout<< "The updated amount of of money Player "<<targetPlayer->getName()<<" has: " << targetPlayer->getMoney()<<endl;
    cout << "************************************************" << endl;
    cout<< "Press ENTER to continue to your dice roll ";
    cin.ignore();
    getline(std::cin, temp);
    cout << "************************************************" << endl;
}

void Board::auction(std::shared_ptr<Tile> t){

    std::cout << '\n';
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    std::cout << "Entered an auction phase" << endl;

    // Set the current bid to 0
    int maxBid = 0;
    int maxPlayerIndex = currentPlayer;

    vector <int> remaining;

    // Enable all players to be allowed to bid
    for(size_t i = 0; i < players.size(); i++){
        remaining.push_back(i);
    }

    // Allow current player first chance to make a bid
    for(int i = currentPlayer; remaining.size() != 0; i++){
        int bid;

        // Allow player to enter their bid. If the bid is negative, it means they want to stop bidding.
        std::cout << '\n';
        std::cout << "Player " << players[remaining[i]]->getName() << " please enter your bid. (If you want to stop bidding, enter -1): ";
        std::cin >> bid;
        if (!cin.good()){
            bid = 0;
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //i = i-1;
            //continue;
            std::cout << "Invalid bid. Please wait your turn to bid again." << std::endl;
        }

        // Make sure player has enough money to make bid. If not, skip this turn but allow them to keep bidding
        if(bid > players[i]->getMoney()){
            std::cout << "Invalid bid. You don't have the money to make this." << std::endl;
        }
        // Change the maximum bid if the bid is greater
        else if(bid > maxBid){
            maxBid = bid;
            maxPlayerIndex = remaining[i];
        }

        // Remove player from bidding process if negative bid
        if(bid <= -1){
            for(auto j = remaining.begin(); j != remaining.end();){
                if ((*j) == remaining[i]){
                    j = remaining.erase(j);
                    break;
                }
                else{
                    j++;
                }
            }
            --i;
        }

        // Cycle through the list of remaining players repeatedly until only none are left wanting to bid
        if(i == remaining.size()-1){
            i = -1;
        }
    }

    // If the bid is still 0, it means nobody wanted to buy the asset.
    if(maxBid == 0){
        std::cout << "The asset could not be auctioned off."<< std::endl;
        return;
    }

    // Otherwise state who bought the asset
    std::cout << "Sold to Player " << players[maxPlayerIndex]->getName() << " for " << maxBid << "$."<< std::endl;
    t->buy(players[maxPlayerIndex]);
    players[maxPlayerIndex]->receiveMoney(t->getPrice());
    players[maxPlayerIndex]->payMoney(maxBid);
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << '\n' << std::endl;

    return;
}

string Board::getAssetType( string name){
    for(size_t i = 0; i < properties.size(); i++) {
        if(properties[i]->getName() == name) {
            return properties[i]->getType();
        }
    }

    for(size_t i = 0; i < utilities.size(); i++) {
        if(utilities[i]->getName() == name) {
            return utilities[i]->getType();
        }
    }

    for(size_t i = 0; i < transportations.size(); i++) {
        if(transportations[i]->getName() == name) {
            return transportations[i]->getType();
        }
    }
    return "Invalid Type";
}

Board::~Board(){}
