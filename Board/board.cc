#include "board.h"
#include "./../player.h"
#include "./../tile.h"
#include "./../color.h"
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
    
    std::shared_ptr<Color> brown = std::make_shared<Color>();
    std::shared_ptr<Color> lblue = std::make_shared<Color>();
    std::shared_ptr<Color> pink = std::make_shared<Color>();
    std::shared_ptr<Color> orange = std::make_shared<Color>();
    std::shared_ptr<Color> red = std::make_shared<Color>();
    std::shared_ptr<Color> yellow = std::make_shared<Color>();
    std::shared_ptr<Color> green = std::make_shared<Color>();
    std::shared_ptr<Color> blue = std::make_shared<Color>();

    std::shared_ptr<Tile> d1 = std::make_shared<Tile>();
    std::shared_ptr<Tile> d2 = std::make_shared<Property>();
    std::shared_ptr<Tile> d3 = std::make_shared<Tile>();
    std::shared_ptr<Tile> d4 = std::make_shared<Property>();
    std::shared_ptr<Tile> d5 = std::make_shared<Tile>();
    std::shared_ptr<Tile> d6 = std::make_shared<Tranportation>();
    std::shared_ptr<Tile> d7 = std::make_shared<Property>();
    std::shared_ptr<Tile> d8 = std::make_shared<Tile>();
    std::shared_ptr<Tile> d9 = std::make_shared<Property>();
    std::shared_ptr<Tile> teen = std::make_shared<Property>();
    std::shared_ptr<Tile> teen1 = std::make_shared<Tile>();
    std::shared_ptr<Tile> teen2 = std::make_shared<Property>();
    std::shared_ptr<Tile> teen3 = std::make_shared<Utility>();
    std::shared_ptr<Tile> teen4 = std::make_shared<Property>();
    std::shared_ptr<Tile> teen5 = std::make_shared<Property>();
    std::shared_ptr<Tile> teen6 = std::make_shared<Transportation>();
    std::shared_ptr<Tile> teen7 = std::make_shared<Property>();
    std::shared_ptr<Tile> teen8 = std::make_shared<Tile>();
    std::shared_ptr<Tile> teen9 = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty1 = std::make_shared<Tile>();
    std::shared_ptr<Tile> twenty2 = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty3 = std::make_shared<Tile>();
    std::shared_ptr<Tile> twenty4 = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty5 = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty6 = std::make_shared<Transportation>();
    std::shared_ptr<Tile> twenty7 = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty8 = std::make_shared<Property>();
    std::shared_ptr<Tile> twenty9 = std::make_shared<Utility>();
    std::shared_ptr<Tile> thirty = std::make_shared<Property>();
    std::shared_ptr<Tile> thirty1 = std::make_shared<Tile>();
    std::shared_ptr<Tile> thirty2 = std::make_shared<Property>();
    std::shared_ptr<Tile> thirty3 = std::make_shared<Property>();
    std::shared_ptr<Tile> thirty4 = std::make_shared<Tile>();
    std::shared_ptr<Tile> thirty5 = std::make_shared<Property>();
    std::shared_ptr<Tile> thirty6 = std::make_shared<Transportation>();
    std::shared_ptr<Tile> thirty7 = std::make_shared<Tile>();
    std::shared_ptr<Tile> thirty8 = std::make_shared<Property>();
    std::shared_ptr<Tile> thirty9 = std::make_shared<Tile>();
    std::shared_ptr<Tile> forty = std::make_shared<Property>();

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
    if(players[currentPlayer].isInJail()){
        char yn;
        std::cout << "You are in jail. Would you like to pay your way out? (Y/N): ";
        std::cin >> yn;
        if(yn == 'Y' && players[currentPlayer].getMoney() >= 50){
            players[currentPlayer].payMoney(50);
            players[currentPlayer].release();
            std::cout << "You are now out of jail." << std::endl;
        }
        else{
            std::cout << "Sorry, you must remain in jail." << std::end;
            return;
        }
    }

    int firstRoll = rollDice();
    int secondRoll = rollDice();
    
    if(firstRoll == secondRoll && players[currentPlayer].isInJail()){
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
            cards[(rand()%4+1].use(players[currentPlayer]);
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
            players[currentPlayer].payMoney(Tile[pos].getRent());              
            players[Tile[pos].getOwner()].recieveMoney(Tile[pos].getRent());
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
