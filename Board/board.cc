#include "board.h"
#include "./../player.h"
#include "./../tile.h"
#include <vector>
#include <iostream>
#include <cstlib>
#include <ctime>

Board::Board(int type, int players): type{type}, numPlayers{numPlayers}, currentPlayer{0}{
    std::name;

    for(int i = 0; i < numPlayers; ++i){
        std::cout << "Enter the name for Player " << i << ": ";
        std::cin >> name;

        players.emplace_back(std::make_shared<Player>(name, i));
    }

}

int Board::rollDice(){
    srand(time(0));
    return (rand()%6) + 1;
}

void Board::rollDiceAndAction(int i){
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

    int position = players[currentPlayer].getPos()

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
    
    int cardLocations[] = {2, 8, 17, 22, 33, 36};
    int transLocations[] = {5, 15, 25, 35};
    int utilLocations[] = {12, 28};

    for(int i = 0; i < 6; ++i){
        if(pos = cardLocations[i]){
            srand(time(0));
            Cards[(rand()%4+1].use(players[currentPlayer]);
            return;
        }
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
                auction();
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
                auction();
            }
            return;
       }
    }

    if(Tile[pos].isOwned()){
        players[currentPlayer].payMoney(Tile[pos].getRent());
        players[Tile[pos].getOwner()].recieveMoney(Tile[pos].getRent());

        if(*players[currentPlayer].getNum() == *Tile[pos].getOwner.getNum()){
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
            auction();
        }
        return;
    }

}

void Board::playTurn(){

}

void Board::trade(){

}

void Board::auction(){

}
