//
//  Grid.hpp
//  Lab 7

#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

class Grid
{
private:
    static const int SIZE = 10;
    char grid[SIZE][SIZE];
    std::vector<std::pair<int, int>> checkedCoordinates;

public:
    Grid();
    void initializeGrid();
    void displayGrid();
    char getGridValue(int x, int y);
    void setGridValue(int x, int y, char value);
    bool isCoordinateChecked(int x, int y);
    void markCoordinateChecked(int x, int y);
    bool isValidCoordinate(int x, int y);
};

#endif 


