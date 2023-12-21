// Emma Bilhimer
//  Battleship.hpp
//  Busch Lab 7
// FA23
//Due 12/20/23
//Lab Name: Lab 7 Battleship
/* Description: For this lab you will make a simple battleship game. If you’re not familiar
with the game, some quick internet searches should help. For this lab, you will need four
10 x 10 grids (two for the user and two for the computer). The program will begin with
setup. The program will need to randomly place the computers 5 ships, making sure the
ships do not overlap or go off the board. Here are the ships for your reference. You should give the user the option during each turn to fire, view user’s ship grid, or
 surrender. When the fire function is called, display the user’s guess grid for reference.
 The program must ensure the computer and user only fire at valid locations that have
 not been checked. When one of the fleets is destroyed, the program should recognized
 it, communicate the results to the users, given an update on wins and losses, and give
 them the option to play again or quit. Make sure to use good programing practices for
 this lab. I expect that you use functions for each action the program takes, your code is
 well documented with pre/post conditions, and your code is reasonably efficient. When
 you have completed this lab, upload a copy to GitHub and submit the link in Canvas.
*/
#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include <iostream>
#include <vector>
#include "Grid.hpp"
#include "Ship.hpp"

class Battleship
{
private:
    Grid userGrid;
    Grid computerGrid;
    std::vector<Ship> userShips;
    std::vector<Ship> computerShips;
    int userWins;
    int computerWins;

public:
    Battleship();
    void playGame();
    void setupUserShips();
    void setupComputerShips();
    void displayGrids(bool showComputerGrid);
    void displayUserShips();
    void userTurn();
    void computerTurn();
    bool isGameOver();
    void displayResults();
    void resetGame();
    void printUserGuessGrid();
    void printComputerGuessGrid();
    void printUserShipGrid();
    int promptUserChoice();
};

#endif 
;



