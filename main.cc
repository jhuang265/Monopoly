#include <iostream>
#include <string>
#include "./Game/game.h"

int main(){
    char s;

    while(true){
        std::cout << "Would you like to play a game? (Enter Y/N): ";
        std::cin >> s;

        if(s != 'N'){
            int type, numPlayers;
            std::cout << std::endl;
            std::cout << "How many players would you like to play with? (Please enter a number between 2 and 4): ";
            std::cin >> numPlayers;

            if(numPlayers < 2 || numPlayers > 4){
                std::cout << "Please enter a valid number of players: ";
                std::cin >> numPlayers;
            }

            std::cout << std::endl;
            std::cout << "We offer two types of games to play. The first requires collecting all properties" << endl;
            std::cout << "of an individual color before you can build houses on them, while the second type" << endl;
            std::cout << "does not require you to do so. ";
            std::cout << "Which type of game would you like to play? (1 or 2): ";
            std::cin >> type;

            if(type > 2 || type <= 0){
                std::cout << "Please enter a valid type of game to play: ";
                std::cin >> type;
            }

            Game g{type, numPlayers};
            g.playGame();
            cout << std::endl;
        }
        else{
            break;
        }
    }
    cout << "Goodbye!" << endl;
}
