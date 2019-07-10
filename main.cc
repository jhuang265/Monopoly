#include <iostream>
#include <string>
#include <limits>
#include "./Game/game.h"

int main(){
    char s;

    // We allow the game logic to loop as long as someone wishes to play
    while(true){
        // Ask user if they want to play a game
        std::cout << "Would you like to play a game? (Enter Y/N): ";
        std::cin >> s;

        // If anything other than a no, let them play
        if(s != 'N'){
            // Set the number of players and the game type
            int type, numPlayers;
            std::cout << std::endl;
            std::cout << "How many players would you like to play with? (Please enter a number between 2 and 4): ";
            std::cin >> numPlayers;

            while (!cin.good() || numPlayers > 4 || numPlayers < 2){
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid number of players: ";
                std::cin >> numPlayers;
            }

            std::cout << std::endl;
            std::cout << "We offer two types of games to play. The first requires collecting all properties" << endl;
            std::cout << "of an individual color before you can build houses on them, while the second type" << endl;
            std::cout << "does not require you to do so. ";
            std::cout << "Which type of game would you like to play? (1 or 2): ";
            std::cin >> type;

            while (!cin.good() || type > 2 || type <= 0){
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid type of game to play: ";
                std::cin >> type;
            }

            // Create the game and let the users play
            Game g{type, numPlayers};
            g.playGame();
            cout << std::endl;
        }
        else{
            break;
        }
    }

    // Exit the program
    cout << "Goodbye!" << endl;
}
