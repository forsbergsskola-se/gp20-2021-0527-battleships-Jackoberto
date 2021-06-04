#include "BattleShipGame.h"

#include <cstring>
#include <iostream>

using namespace std;

void BattleShipGame::displayBoard(Player player, bool see_occupied)
{
    GridElementState (*board)[10];
    if (player == One)
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
    ships_P1 = 5;
    ships_P2 = 5;
}

void BattleShipGame::run()
{
    cout << "Time For Player 1 To Set Ships" << endl;
    system("pause");
    setOutShips(One);
    cout << "Time For Player 2 To Set Ships" << endl;
    system("pause");
    setOutShips(Two);

    Player player = One;
    while (true)
    {
        switch (player)
        {
        case One:
            player = Two;
            break;
        case Two:
            player = One;
            break;
        }
        system("pause");
        turn(player);
        if (player == One)
        {
            if (ships_P2 <= 0)
            {
                cout << "Player " << player + 1 << " Won!";
                break;
            }  
        }
        else
        {
            if (ships_P1 <= 0)
            {
                cout << "Player " << player + 1 << " Won!";
                break;
            }  
        }
    }
}

void BattleShipGame::clearConsole()
{
    system("CLS");
}

void BattleShipGame::setOutShips(Player player)
{
    GridElementState (*board)[10];
    if (player == One)
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
            cout << "Place A Ship" << endl << "You Have " << i << " Ships Left" << endl;
            displayBoard(player, true);
            cin >> first >> x;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            first = toupper(first);
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

void BattleShipGame::turn(Player player)
{
    GridElementState (*board)[10];
    int* ships;
    if (player == Two)
    {
        board = board_P1;
        ships = &ships_P1;
    }     
    else
    {
        board = board_P2;
        ships = &ships_P2;
    }
    int x = -1, y = -1;
    char first;
    while (true)
    {
        clearConsole();
        cout << "Player " << player + 1 << endl;
        displayBoard(player ? One : Two, false);
        cin >> first >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        first = toupper(first);
        y = getCoordinate(first);
        if (x == -1 || y < 0 || y > 9)
            continue;
        if (board[x][y] != Miss || board[x][y] != Hit)
        {
            if (board[x][y] == Occupied)
            {
                board[x][y] = Hit;
                cout << "You Hit A Ship" << endl;
                *ships -= 1;
            }
            else if (board[x][y] == Empty)
            {
                board[x][y] = Miss;
                cout << "You Missed" << endl;
                *ships -= 1;
            }
            break;
        }
    }
}