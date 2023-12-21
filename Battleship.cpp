//
//  Battleship.cpp
//  Lab 7

#include "Battleship.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


void Battleship::setupUserShips()
{
    std::cout << "Setting up user ships." << std::endl;
    displayGrids(false); // show grid only

    for (int i = 0; i < 5; ++i)
    {
        int shipSize = 0;
        std::string shipName;

        // get ship information based on ship type
        switch (i)
        {
        case 0:
            shipSize = 5;
            shipName = "Carrier";
            break;
        case 1:
            shipSize = 4;
            shipName = "Battleship";
            break;
        case 2:
        case 3:
            shipSize = 3;
            shipName = (i == 2) ? "Cruiser" : "Submarine";
            break;
        case 4:
            shipSize = 2;
            shipName = "Destroyer";
            break;
        }

        // get user input for ship placement
        int x, y;
        char direction;
        std::cout << "Enter coordinates (x y) for your " << shipName << " (size " << shipSize << "): ";
        std::cin >> x >> y;
        std::cout << "Enter direction (H for horizontal, V for vertical): ";
        std::cin >> direction;

        // Display updated user grid
        displayGrids(false);
    }
}

void Battleship::setupComputerShips()
{
    std::cout << "Setting up computer ships." << std::endl;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 5; ++i)
    {
        int shipSize = 0;
        std::string shipName;

        // Get ship information based on ship type
        switch (i)
        {
        case 0:
            shipSize = 5;
            shipName = "Carrier";
            break;
        case 1:
            shipSize = 4;
            shipName = "Battleship";
            break;
        case 2:
        case 3:
            shipSize = 3;
            shipName = (i == 2) ? "Cruiser" : "Submarine";
            break;
        case 4:
            shipSize = 2;
            shipName = "Destroyer";
            break;
        }

        // Display message indicating computer ship placement
        std::cout << "Computer placed " << shipName << " (size " << shipSize << ")." << std::endl;
    }
}

void Battleship::userTurn()
{
    int x, y;
    std::cout << "Enter coordinates (x y) to fire: ";
    std::cin >> x >> y;

    // Display the updated grids
    displayGrids(true);
}

void Battleship::computerTurn()
{
    int x = rand() % 10;
    int y = rand() % 10;

    //  computer doesn't fire at the same location twice
    while (computerGrid.isCoordinateChecked(x, y))
    {
        x = rand() % 10;
        y = rand() % 10;
    }


    // Display the updated grids
    displayGrids(false);
}

bool Battleship::isGameOver()
{
    // Check if all computer ships are destroyed
    bool computerFleetDestroyed = true;
    for (const auto &ship : computerShips)
    {
        if (ship.getHp() > 0)
        {
            computerFleetDestroyed = false;
            break;
        }
    }

    // Check if all user ships are destroyed
    bool userFleetDestroyed = true;
    for (const auto &ship : userShips)
    {
        if (ship.getHp() > 0)
        {
            userFleetDestroyed = false;
            break;
        }
    }
    
    // The game is over if either the computer or user fleet is destroyed
    return computerFleetDestroyed || userFleetDestroyed;

    }

    return computerFleetDestroyed || userFleetDestroyed;
}

void Battleship::displayResults()
{
    std::cout << "Game Over!" << std::endl;

    if (userWins > computerWins)
    {
        std::cout << "Congratulations! You win!" << std::endl;
    }
    else if (userWins < computerWins)
    {
        std::cout << "Oh no! The NPC wins!" << std::endl;
    }
    else
    {
        std::cout << "It's a tie! Both sides have won the same number of games." << std::endl;
    }

    std::cout << "Wins - User: " << userWins << " | Computer: " << computerWins << std::endl;
}

void Battleship::resetGame()
{
    userShips.clear();
    computerShips.clear();
    userGrid.initializeGrid();
    computerGrid.initializeGrid();
}


