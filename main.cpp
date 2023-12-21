//
//  main.cpp
//  Lab 7

#include <iostream>
#include "Battleship.hpp"


int main() {
    Battleship game;

    // Set up the game
    game.setupComputerShips();


    do {
        // Display user's guess grid for reference
        game.printUserGuessGrid();

        // User's turn
        game.userTurn();

        // Check if the user has won
        if (game.isGameOver()) {
            std::cout << "Congrats! You've destroyed NPC's fleet!" << std::endl;
            break;
        }

        // Display computer's guess grid for reference
        game.printComputerGuessGrid();

        // Computer's turn
        game.computerTurn();

        // Check if the computer has won
        if (game.isGameOver()) {
            std::cout << "Oh no! NPC has destroyed your fleet. Better luck next time!" << std::endl;
            break;
        }

        // Ask user if they want to view their ship grid, surrender, or continue playing
        int userChoice = game.promptUserChoice();
        if (userChoice == 1) {
            game.printUserShipGrid();
        } else if (userChoice == 2) {
            std::cout << "You've surrendered. The NPC wins." << std::endl;
            break;
        }

    } while (true);

    return 0;
}





