#include "board.h"
#include "./../Player/player.h"
#include "./../Tile/utility.h"
#include "./../Tile/transportation.h"
#include "./../Tile/property.h"
#include "./../Tile/tile.h"
#include "./../Color/color.h"
#include "./../Card/card.h"
#include "./../Card/getMoneyCard.h"
#include "./../Card/gOJFCard.h"
#include "./../Card/gTJCard.h"
#include "./../Card/moveCard.h"
#include "./../Card/letMoneyCard.h"
#include <vector>
#include <iostream>
#include <cstlib>
#include <ctime>

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

    std::shared_ptr<Tile> d1 = std::make_shared<Tile>("Go");
    std::shared_ptr<Tile> d2 = std::make_shared<Property>(60, {2, 10, 30, 90, 160, 250}, brown, initialBuild, "Property", "P1");
    std::shared_ptr<Tile> d3 = std::make_shared<Tile>("Income Tax");
    std::shared_ptr<Tile> d4 = std::make_shared<Property>(60, {4, 20, 60, 180, 320, 450}, brown, initialBuild, "Property", "P2");
    std::shared_ptr<Tile> d5 = std::make_shared<Tile>("Community Chest");
    std::shared_ptr<Tile> d6 = std::make_shared<Tranportation>(200, {25, 50, 100, 200}, "Transportation", "T1");
    std::shared_ptr<Tile> d7 = std::make_shared<Property>(100, {6, 30, 90, 270, 400, 550}, lblue, initialBuild, "Property", "P3");
    std::shared_ptr<Tile> d8 = std::make_shared<Tile>("Chance");
    std::shared_ptr<Tile> d9 = std::make_shared<Property>(100, {6, 30, 90, 270, 400, 550}, lblue, initialBuild, "Property", "P4");
    std::shared_ptr<Tile> teen = std::make_shared<Property>(120, {8, 40, 100, 300, 450, 600}, lblue, initialBuild, "Property", "P5");
    std::shared_ptr<Tile> teen1 = std::make_shared<Tile>("Jail/Visiting");
    std::shared_ptr<Tile> teen2 = std::make_shared<Property>(140, {10, 50, 150, 450, 625, 750}, pink, initialBuild, "Property", "P6");
    std::shared_ptr<Tile> teen3 = std::make_shared<Utility>(150, {4, 10}, "Utility", "U1");
    std::shared_ptr<Tile> teen4 = std::make_shared<Property>(140, {10, 50, 150, 450, 625, 750}, pink, initialBuild, "Property", "P7");
    std::shared_ptr<Tile> teen5 = std::make_shared<Property>(160, {12, 60, 180, 500, 700, 900}, pink, initialBuild, "Property", "P8");
    std::shared_ptr<Tile> teen6 = std::make_shared<Transportation>(200, {25, 50, 100, 200}, "Transportation", "T2");
    std::shared_ptr<Tile> teen7 = std::make_shared<Property>(180, {14, 70, 200, 550, 750, 950}, orange, initialBuild, "Property", "P9");
    std::shared_ptr<Tile> teen8 = std::make_shared<Tile>("Community Chest");
    std::shared_ptr<Tile> teen9 = std::make_shared<Property>(180, {14, 70, 200, 550, 750, 950}, orange, initialBuild, "Property", "P10");
    std::shared_ptr<Tile> twenty = std::make_shared<Property>(200, {16, 80, 220, 600, 800, 1000}, orange, initialBuild, "Property", "P11");
    std::shared_ptr<Tile> twenty1 = std::make_shared<Tile>("Free Parking");
    std::shared_ptr<Tile> twenty2 = std::make_shared<Property>(220, {18, 90, 250, 700, 875, 1050}, red, initialBuild, "Property", "P12");
    std::shared_ptr<Tile> twenty3 = std::make_shared<Tile>("Chance");
    std::shared_ptr<Tile> twenty4 = std::make_shared<Property>(220, {18, 90, 250, 700, 875, 1050}, red, initialBuild, "Property", "P13");
    std::shared_ptr<Tile> twenty5 = std::make_shared<Property>(240, {20, 100, 300, 750, 925, 1100}, red, initialBuild, "Property", "P14");
    std::shared_ptr<Tile> twenty6 = std::make_shared<Transportation>(200, {25, 50, 100, 200}, "Transportation", "T3");
    std::shared_ptr<Tile> twenty7 = std::make_shared<Property>(260, {22, 110, 330, 800, 975, 1150}, yellow, initialBuild, "Property", "P15");
    std::shared_ptr<Tile> twenty8 = std::make_shared<Property>(260, {22, 110, 330, 800, 975, 1150}, yellow, initialBuild, "Property", "P16");
    std::shared_ptr<Tile> twenty9 = std::make_shared<Utility>(150, {4, 10}, "Utility", "U2");
    std::shared_ptr<Tile> thirty = std::make_shared<Property>(280, {22, 120, 360, 850, 1025, 1200}, yellow, initialBuild, "Property", "P17");
    std::shared_ptr<Tile> thirty1 = std::make_shared<Tile>("Go To Jail");
    std::shared_ptr<Tile> thirty2 = std::make_shared<Property>(300, {26, 130, 390, 900, 1100, 1275}, green, initialBuild, "Property", "P18");
    std::shared_ptr<Tile> thirty3 = std::make_shared<Property>(300, {26, 130, 390, 900, 1100, 1275}, green, initialBuild, "Property", "P19");
    std::shared_ptr<Tile> thirty4 = std::make_shared<Tile>("Community Chest");
    std::shared_ptr<Tile> thirty5 = std::make_shared<Property>(320, {28, 150, 450, 1000, 1200, 1400}, green, initialBuild, "Property", "P20");
    std::shared_ptr<Tile> thirty6 = std::make_shared<Transportation>(200, {25, 50, 100, 200}, "Transportation", "T4");
    std::shared_ptr<Tile> thirty7 = std::make_shared<Tile>("Chance");
    std::shared_ptr<Tile> thirty8 = std::make_shared<Property>(350, {35, 175, 500, 1100, 1300, 1500}, blue, initialBuild, "Property", "P21");
    std::shared_ptr<Tile> thirty9 = std::make_shared<Tile>("Luxury Tax");
    std::shared_ptr<Tile> forty = std::make_shared<Property>(400, {50, 200, 600, 1400, 1700, 2000}, blue, initialBuild, "Property", "P21");

    brown.attach(d1);
    brown.attach(d4);
    lblue.attach(d7);
    lblue.attach(d9);
    lblue.attach(teen);
    pink.attach(teen2);
    pink.attach(teen4);
    pink.attach(teen5);
    orange.attach(teen7);
    orange.attach(teen9);
    orange.attach(twenty);
    red.attach(twenty2);
    red.attach(twenty4);
    red.attach(twenty5);
    yellow.attach(twenty7);
    yellow.attach(twenty8);
    yellow.attach(thirty);
    green.attach(thirty2);
    green.attach(thirty3);
    green.attach(thirty5);
    blue.attach(thirty8);
    blue.attach(forty);

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

    cards.emplace_back(std::make_shared<GetMoneyCard>());
    cards.emplace_back(std::make_shared<LoseMoneyCard>());
    cards.emplace_back(std::make_shared<GOJFCard>());
    cards.emplace_back(std::make_shared<GTJCard>());
    cards.emplace_back(std::make_shared<MoveCard>());

}

int Board::rollDice(){
    srand(time(0));
    return (rand()%6) + 1;
}

void Board::rollDiceAndAction(int i){
    if(players[currentPlayer].turnsInJail() == 3){
        players[currentPlayer].release();
    }

    if(players[currentPlayer].isInJail()){
        char yn;
        std::cout << "You are in jail. Would you like to pay your way out? (Y/N): ";
        std::cin >> yn;
        if(yn == 'Y' && players[currentPlayer].getMoney() >= 50){
            players[currentPlayer].payMoney(50);
            players[currentPlayer].release();
            std::cout << "You are now out of jail." << std::endl;
        }
    }

    int firstRoll = rollDice();
    int secondRoll = rollDice();

    if(firstRoll != secondRoll && players[currentPlayer].isInJail()){
        players[currentPlayer].addTurnInJail();
        return;
    }
    else if(firstRoll == secondRoll && players[currentPlayer].isInJail()){
        players[currentPlayer].release();
    }
    else if(firstRoll == secondRoll){
        players[currentPlayer].rollDouble();
    }
    else{
        players[currentPlayer].resetDoubles();
    }

    if(players[currentPlayer].getDoubles() == 3){
        players[currentPlayer].sendToJail();
        players[currentPlayer].resetDoubles();
        return;
    }

    players[currentPlayer].move(firstRoll+secondRoll);

    int pos = players[currentPlayer].getPos()

    int cardLocations[] = {2, 8, 17, 22, 33, 36};
    int transLocations[] = {5, 15, 25, 35};
    int utilLocations[] = {12, 28};

    for(int i = 0; i < 6; ++i){
        if(pos = cardLocations[i]){
            srand(time(0));
            cards[(rand()%4+1)].use(players[currentPlayer]);
            return;
        }
    }

    pos = players[currentPlayer].getPos();

    switch(pos){
        case 0:
            //players[currentPlayer].getMoney(200);
            break;
        case 4:
            players[currentPlayer].payMoney(200);
            break;
        case 10:
            break;
        case 20:
            break;
        case 30:
            players[currentPlayer].goToJail();
            break;
        case 38:
            players[currentPlayer].payMoney(150);
            break;
    }


    for(int i = 0; i < 4; ++i){
        if(Tile[pos].isOwned()){
            players[currentPlayer].payMoney(Tile[pos].getRent());
            players[Tile[pos].getOwner()].recieveMoney(Tile[pos].getRent());
            return;
        }
        else{
            char yn;
            std::cout << "You have landed on an unowned transportation. Would you like to buy it? (Y/N): ";
            std::cin >> yn;
            if(yn == 'Y' && players[currentPlayer].getMoney >= Tile[pos].getPrice()){
                Tile[pos].buy(players[currentPlayer]);
            }
            else{
                auction(Tile[pos]);
            }
            return;
        }
    }

    for(int i = 0; i < 2; ++i){
        if(Tile[pos].isOwned()){
            players[currentPlayer].payMoney(Tile[pos].getUtilityRent(firstRoll+secondRoll));
            players[Tile[pos].getOwner()].recieveMoney(Tile[pos].getUtilityRent(firstRoll+secondRoll));
            return;
        }
        else{
            char yn;
            std::cout << "You have landed on an unowned utility. Would you like to buy it? (Y/N): ";
            std::cin >> yn;
            if(yn == 'Y' && players[currentPlayer].getMoney >= Tile[pos].getPrice()){
                Tile[pos].buy(players[currentPlayer]);
            }
            else{
                auction(Tile[pos]);
            }
            return;
       }
    }

    if(Tile[pos].isOwned()){
        players[currentPlayer].payMoney(Tile[pos].getRent());
        players[Tile[pos].getOwner()].recieveMoney(Tile[pos].getRent());

        if(players[currentPlayer].getNum() == Tile[pos].getOwner.getNum()){
            if(Tile[pos].getCanBuild()){
                if((Tile[pos].getHouses()+1) * 50 > players[currentPlayer].getMoney()){
                    char yn;
                    std::cout << "You have enough money to buy a new house. Would you like to buy it? (Y/N): ";
                    std::cin >> yn;
                    if(yn == 'Y'){
                        Tile[pos].buyHouse();
                    }
                }
            }
        }
    }
    else{
        char yn;
        std::cout << "You have landed on an unowned property. Would you like to buy it? (Y/N): ";
        std::cin >> yn;
        if(yn == 'Y' && players[currentPlayer].getMoney >= Tile[pos].getPrice()){
            Tile[pos].buy(players[currentPlayer]);
        }
        else{
            auction(Tile[pos]);
        }
        return;
    }

}

void Board::playTurn(){
    while(players.size() > 1){
        currentPlayer = 0;
        for(auto i = players.begin(); i != players.end() && players.size() > 1){
            rollDiceAndAction();
            if(*i.getMoney() < 0){
                i = players.erase(i);
                continue;
            }
            while(*i.getDoubles() > 0 && *i.getDoubles() < 3){
                if(*i.getMoney() < 0){
                    i = players.erase(i);
                    break;
                }
                rollDiceAndAction();
            }
            currentPlayer = (currentPlayer+1) % players.size();
        }
    }
}

void Board::trade(){
    return;
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
        if(bid > players[currentPlayer].getMoney()){
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

    t.buy(players[remaining[0]]);

    return;
}

~Board::Board(){}
