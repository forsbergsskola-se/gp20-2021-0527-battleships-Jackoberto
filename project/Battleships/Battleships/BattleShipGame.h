#pragma once
#include <map>

#include "Cell.h"

enum Player
{
    One,
    Two
};

class BattleShipGame
{
    std::map<char, int> to_coordinate
    {
        {'A', 0},
        {'B', 1},
        {'C', 2},
        {'D', 3},
        {'E', 4},
        {'F', 5},
        {'G', 6},
        {'H', 7},
        {'I', 8},
        {'J', 9}
    };
    int ships_P1;
    int ships_P2;
    Cell board_P1[10][10];
    Cell board_P2[10][10];
    Cell empty_cell;
    void displayBoard(Player player, bool see_occupied);
    int getCoordinate(char key);
    void clearConsole();
    void setOutShips(Player player);
    void turn(Player player);
public:
    BattleShipGame();
    void run();
};