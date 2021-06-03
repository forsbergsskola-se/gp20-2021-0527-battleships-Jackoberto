#pragma once
#include <map>

enum Player
{
    One,
    Two
};

enum GridElementState
{
    Empty,
    Occupied,
    Hit,
    Miss
};

class BattleShipGame
{
    void displayBoard(Player player, bool see_occupied);
    int getCoordinate(char key);
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
    GridElementState board_P1[10][10];
    GridElementState board_P2[10][10];
    void clearConsole();
    void setOutShips(Player player);
public:
    BattleShipGame();
    void run();
};