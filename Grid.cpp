//
//  Grid.cpp
//  Lab 7
// Grid.cpp

#include <iostream>
#include "Grid.hpp"

Grid::Grid()
{
    initializeGrid();
}

void Grid::initializeGrid()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            grid[i][j] = '~'; // Water
        }
    }
}

void Grid::displayGrid()
{
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

char Grid::getGridValue(int x, int y)
{
    return grid[y][x];
}

void Grid::setGridValue(int x, int y, char value)
{
    grid[y][x] = value;
}

bool Grid::isCoordinateChecked(int x, int y)
{
    for (const auto &coord : checkedCoordinates)
    {
        if (coord.first == x && coord.second == y)
        {
            return true;
        }
    }
    return false;
}

void Grid::markCoordinateChecked(int x, int y)
{
    checkedCoordinates.push_back(std::make_pair(x, y));
}

bool Grid::isValidCoordinate(int x, int y)
{
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}



