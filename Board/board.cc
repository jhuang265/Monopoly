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
    std::shared_ptr<Property> d2 = std::make_shared<Property>(new Property(60, {2, 10, 30, 90, 160, 250}, brown, initialBuild, "Property", "P1"));
    std::shared_ptr<Tile> d3 = std::make_shared<Tile>("Income Tax", "Income Tax");
    std::shared_ptr<Property> d4 = std::make_shared<Property>(new Property(60, {4, 20, 60, 180, 320, 450}, brown, initialBuild, "Property", "P2"));
    std::shared_ptr<Tile> d5 = std::make_shared<Tile>("Community Chest", "Community Chest");
    std::shared_ptr<Tile> d6 = std::make_shared<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T1"));
    std::shared_ptr<Property> d7 = std::make_shared<Property>(new Property(100, {6, 30, 90, 270, 400, 550}, lblue, initialBuild, "Property", "P3"));
    std::shared_ptr<Tile> d8 = std::make_shared<Tile>("Chance", "Chance");
    std::shared_ptr<Property> d9 = std::make_shared<Property>(new Property(100, {6, 30, 90, 270, 400, 550}, lblue, initialBuild, "Property", "P4"));
    std::shared_ptr<Property> teen = std::make_shared<Property>(new Property(120, {8, 40, 100, 300, 450, 600}, lblue, initialBuild, "Property", "P5"));
    std::shared_ptr<Tile> teen1 = std::make_shared<Tile>("Jail/Visiting", "Jail/Visiting");
    std::shared_ptr<Property> teen2 = std::make_shared<Property>(new Property(140, {10, 50, 150, 450, 625, 750}, pink, initialBuild, "Property", "P6"));
    std::shared_ptr<Tile> teen3 = std::make_shared<Utility>(new Utility(150, {4, 10}, "Utility", "U1"));
    std::shared_ptr<Property> teen4 = std::make_shared<Property>(new Property(140, {10, 50, 150, 450, 625, 750}, pink, initialBuild, "Property", "P7"));
    std::shared_ptr<Property> teen5 = std::make_shared<Property>(new Property(160, {12, 60, 180, 500, 700, 900}, pink, initialBuild, "Property", "P8"));
    std::shared_ptr<Tile> teen6 = std::make_shared<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T2"));
    std::shared_ptr<Property> teen7 = std::make_shared<Property>(new Property(180, {14, 70, 200, 550, 750, 950}, orange, initialBuild, "Property", "P9"));
    std::shared_ptr<Tile> teen8 = std::make_shared<Tile>("Community Chest", "Community Chest");
    std::shared_ptr<Property> teen9 = std::make_shared<Property>(new Property(180, {14, 70, 200, 550, 750, 950}, orange, initialBuild, "Property", "P10"));
    std::shared_ptr<Property> twenty = std::make_shared<Property>(new Property(200, {16, 80, 220, 600, 800, 1000}, orange, initialBuild, "Property", "P11"));
    std::shared_ptr<Tile> twenty1 = std::make_shared<Tile>("Free Parking", "Free Parking");
    std::shared_ptr<Property> twenty2 = std::make_shared<Property>(new Property(220, {18, 90, 250, 700, 875, 1050}, red, initialBuild, "Property", "P12"));
    std::shared_ptr<Tile> twenty3 = std::make_shared<Tile>("Chance", "Chance");
    std::shared_ptr<Property> twenty4 = std::make_shared<Property>(new Property(220, {18, 90, 250, 700, 875, 1050}, red, initialBuild, "Property", "P13"));
    std::shared_ptr<Property> twenty5 = std::make_shared<Property>(new Property(240, {20, 100, 300, 750, 925, 1100}, red, initialBuild, "Property", "P14"));
    std::shared_ptr<Tile> twenty6 = std::make_shared<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T3"));
    std::shared_ptr<Property> twenty7 = std::make_shared<Property>(new Property(260, {22, 110, 330, 800, 975, 1150}, yellow, initialBuild, "Property", "P15"));
    std::shared_ptr<Property> twenty8 = std::make_shared<Property>(new Property(260, {22, 110, 330, 800, 975, 1150}, yellow, initialBuild, "Property", "P16"));
    std::shared_ptr<Tile> twenty9 = std::make_shared<Utility>(new Utility(150, {4, 10}, "Utility", "U2"));
    std::shared_ptr<Property> thirty = std::make_shared<Property>(new Property(280, {22, 120, 360, 850, 1025, 1200}, yellow, initialBuild, "Property", "P17"));
    std::shared_ptr<Tile> thirty1 = std::make_shared<Tile>("Go To Jail", "Go To Jail");
    std::shared_ptr<Property> thirty2 = std::make_shared<Property>(new Property(300, {26, 130, 390, 900, 1100, 1275}, green, initialBuild, "Property", "P18"));
    std::shared_ptr<Property> thirty3 = std::make_shared<Property>(new Property(300, {26, 130, 390, 900, 1100, 1275}, green, initialBuild, "Property", "P19"));
    std::shared_ptr<Tile> thirty4 = std::make_shared<Tile>("Community Chest", "Community Chest");
    std::shared_ptr<Property> thirty5 = std::make_shared<Property>(new Property(320, {28, 150, 450, 1000, 1200, 1400}, green, initialBuild, "Property", "P20"));
    std::shared_ptr<Tile> thirty6 = std::make_shared<Transportation>(new Transportation(200, {25, 50, 100, 200}, "Transportation", "T4"));
    std::shared_ptr<Tile> thirty7 = std::make_shared<Tile>("Chance", "Chance");
    std::shared_ptr<Property> thirty8 = std::make_shared<Property>(new Property(350, {35, 175, 500, 1100, 1300, 1500}, blue, initialBuild, "Property", "P21"));
    std::shared_ptr<Tile> thirty9 = std::make_shared<Tile>("Luxury Tax", "Luxury Tax");
    std::shared_ptr<Property> forty = std::make_shared<Property>(new Property(400, {50, 200, 600, 1400, 1700, 2000}, blue, initialBuild, "Property", "P22"));

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

    cards.emplace_back(std::make_shared<getMoneyCard>());
    cards.emplace_back(std::make_shared<loseMoneyCard>());
    cards.emplace_back(std::make_shared<GOJFCard>());
    cards.emplace_back(std::make_shared<GTJCARD>());
    cards.emplace_back(std::make_shared<moveCard>());

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

    for(int i = 0; i < 6; ++i){
        if(pos == cardLocations[i]){
            srand(time(0));
            cards[(rand()%4+1)]->use(players[currentPlayer]);
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
        if(tiles[pos]->getIsOwned()){
            players[currentPlayer]->payMoney(tiles[pos]->getRent());
            players[tiles[pos]->getOwnerIndex()]->recieveMoney(tiles[pos]->getRent());
            return;
        }
        else{
            char yn;
            std::cout << "You have landed on an unowned transportation. Would you like to buy it? (Y/N): ";
            std::cin >> yn;
            if(yn == 'Y' && players[currentPlayer]->getMoney >= tiles[pos]->getPrice()){
                tiles[pos]->buy(players[currentPlayer]);
            }
            else{
                auction(tiles[pos]);
            }
            return;
        }
    }

    for(int i = 0; i < 2; ++i){
        if(tiles[pos]->getIsOwned()){
            players[currentPlayer]->payMoney(tiles[pos]->getUtilityRent(firstRoll+secondRoll));
            players[tiles[pos]->getOwnerIndex()]->recieveMoney(tiles[pos]->getUtilityRent(firstRoll+secondRoll));
            return;
        }
        else{
            char yn;
            std::cout << "You have landed on an unowned utility. Would you like to buy it? (Y/N): ";
            std::cin >> yn;
            if(yn == 'Y' && players[currentPlayer].getMoney >= tiles[pos]->getPrice()){
                tiles[pos]->buy(players[currentPlayer]);
            }
            else{
                auction(tiles[pos]);
            }
            return;
       }
    }

    if(tiles[pos]->getIsOwned()){
        players[currentPlayer]->payMoney(tiles[pos]->getRent());
        players[tiles[pos]->getOwnerIndex()]->recieveMoney(tiles[pos]->getRent());

        if(players[currentPlayer]->getNum() == tiles[pos].getOwnerIndex()->getNum()){
            if(tiles[pos]->getCanBuild()){
                if((tiles[pos]->getHouses()+1) * 50 > players[currentPlayer]->getMoney()){
                    char yn;
                    std::cout << "You have enough money to buy a new house. Would you like to buy it? (Y/N): ";
                    std::cin >> yn;
                    if(yn == 'Y'){
                        tiles[pos]->buyHouse();
                    }
                }
            }
        }
    }
    else{
        char yn;
        std::cout << "You have landed on an unowned property. Would you like to buy it? (Y/N): ";
        std::cin >> yn;
        if(yn == 'Y' && players[currentPlayer].getMoney >= tiles[pos]->getPrice()){
            tiles[pos]->buy(players[currentPlayer]);
        }
        else{
            auction(tiles[pos]);
        }
        return;
    }

}

void Board::playTurn(){
    char playerChoice;
    while(players.size() > 1){
        currentPlayer = 0;
        for(auto i = players.begin(); i != players.end() && players.size() > 1){
            print();
            cout<<"1) Play without trading (enter A)"<<endl;
            cout<<"2) Do you want to trade? (enter B)"<<endl;
            cout<<"3) Do you want to quit? (enter C)"<<endl;
            cin>>playerChoice;
            while(playerChoice!= 'A' && playerChoice!= 'B' && playerChoice!= 'C'){
                cin>>playerChoice;
            }
            if (playerChoice=='C'){   
                players.erase(i);
                continue;
            }
            else if(playerChoice == 'B'){
                trade(*i);
            }

            rollDiceAndAction();
            if(*i->getMoney() < 0){
                players.erase(i);
                continue;
            }
            while(*i->getDoubles() > 0 && *i->getDoubles() < 3){
                if(*i->getMoney() < 0){
                    players.erase(i);
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
    cout<<"Here is the list of properties/utilities/transportations you can trade:"<<endl;
    player->printAsset();
    cout<<"Enter the assets you want to trade by corresponding number and and e to end:"<<endl;
    while(cin>>inputChar){
        if(inputChar=='e'){
            if(tradeList.size()==0){
                return;
            }
            else{
                break;
            }
        }
        else if((int)inputChar > (getNumProperties + getNumUtilities + getNumTransportations)){
            continue;
        }
        else{
            if((int)inputChar<= getNumProperties){
                tradeList.emblace_back(player->propertyNameAt((int)inputChar-1));
            }
            else if((int)inputChar < getNumProperties+getNumUtilities ){
                tradeList.emblace_back(player->utilityNameAt((int)inputChar-getNumProperties-1));
            }
            else{
                tradeList.emblace_back(player->transportationNameAt((int)inputChar-(getNumProperties + getNumUtilities)-1));
            }
        }  
    }
    cout<<"Select the player you want to trade with (enter their number):"<<endl;
    for(int p = 0 ; p < players.size() ; p++){
        cout<<p+1<< " " << players[p]->getName()<<endl;
    }
    cin>>targetPlayerIndex;
    --targetPlayerIndex;
    targetPlayer = players[targetPlayerIndex];
    cout<<"Enter the money you want to get from " << targetPlayer->getName()<<endl;
    while(cin>>desiredMoney){
        if(desiredMoney > player->getMoney()){
            cout<<"Not enough money, please re-enter a value"<<endl;
            continue;
        }
        else{
            break;
        }
    }
    cout<<"Player "<< targetPlayer->getName()<< ", do you agree to change "<< desiredMoney << "with "<< player->getName()<<"(Y/N)"<<endl;
    while(cin>>inputChar){
        if(inputChar!='Y' && inputChar!= 'N'){
            cout<<"Invalid input, please re-enter"<<endl;
        }
        else{
            break;
        }
    }
    if(inputChar=='N'){
        return;
    }
    else{
        player->payMoney(desiredMoney);
        targetPlayer->receiveMoney(desiredMoney);
        for(int x = 0; x < tradeList.size(); x++){
            *(player).returnAsset(tradeList[x]).changeOwner(targetPlayer);
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
            remaining.erase(remaining[i]);
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

~Board::Board(){}
