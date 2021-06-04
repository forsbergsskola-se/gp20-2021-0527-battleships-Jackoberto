#include "BattleShipGame.h"

#include <cstring>
#include <iostream>

using namespace std;

void BattleShipGame::displayBoard(Player player, bool see_occupied)
{
    GridElementState (*board)[10];
    if (player)
        board = board_P1;
    else
        board = board_P2;
    char c;

    cout << "[ ][A][B][C][D][E][F][G][H][I][J]" << endl;
    for (int i = 0; i < 10; i++)
    {
       cout << "[" << i << "]";
       for (int j = 0; j < 10; j++)
       {
           switch (board[i][j])
           {
           case Empty:
               c = 254;
               break;
           case Occupied:
               c = see_occupied ? 219 : 254;
               break;
           case Hit:
               c = 'H';
               break;
           case Miss:
               c = 'X';
               break;
           default:
               c = 254;
           }
           cout << "[" << c << "]";
       }
       cout << endl;
    }
}

int BattleShipGame::getCoordinate(char key)
{
    auto iterator = to_coordinate.find(key);
    if (iterator != to_coordinate.end())
    {
        return iterator->second;
    }
    return -1;
}

BattleShipGame::BattleShipGame()
{
    memset(board_P1, Empty, sizeof(board_P1));
    memset(board_P2, Empty, sizeof(board_P2));
}

void BattleShipGame::run()
{
    cout << "Time For Player 1 To Set Ships" << endl;
    system("pause");
    setOutShips(One);
    cout << "Time For Player 2 To Set Ships" << endl;
    system("pause");
    setOutShips(Two);
}

void BattleShipGame::clearConsole()
{
    system("CLS");
}

void BattleShipGame::setOutShips(Player player)
{
    GridElementState (*board)[10];
    if (player)
        board = board_P1;
    else
        board = board_P2;

    int x = -1, y = -1;
    char first;
    for (int i = 5; i > 0; i--)
    {
        while (true)
        {
            clearConsole();
            cout << "Player " << player + 1 << endl;
            cout << "Place A Ship" << endl << "You Have " << i << " Number Of Ships Left" << endl;
            displayBoard(player, true);
            cin >> first >> x;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            y = getCoordinate(first);
            if (x == -1 || y < 0 || y > 9)
                continue;
            if (board[x][y] != Occupied)
            {
                board[x][y] = Occupied;
                break;
            } 
        }
    }
    clearConsole();
}
