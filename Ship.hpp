//
//  Ship.hpp
//  Lab 7

#ifndef SHIP_HPP
#define SHIP_HPP

#include <string>

class Ship
{
private:
    int hp;
    int length;
    int xLoc;
    int yLoc;
    bool isHorizontal;
    std::string name;

public:
    Ship();
    Ship(int hp, int length, int xLoc, int yLoc, bool isHorizontal, std::string name);
    int getHp();
    int getLength();
    int getXLoc();
    int getYLoc();
    bool getIsHorizontal();
    std::string getName();
    void setHp(int hp_);
    void setLength(int length_);
    void setXLoc(int xLoc_);
    void setYLoc(int yLoc_);
    void setIsHorizontal(bool isHorizontal_);
    void setName(std::string name_);
    bool isHit(int x, int y);
};

#endif 



