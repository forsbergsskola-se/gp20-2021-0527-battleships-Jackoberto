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
    int ships_P1;
    GridElementState board_P2[10][10];
    int ships_P2;
    void displayBoard(Player player, bool see_occupied);
    int getCoordinate(char key);
    void clearConsole();
    void setOutShips(Player player);
    void turn(Player player);
    void turn();
public:
    BattleShipGame();
    void run();
};