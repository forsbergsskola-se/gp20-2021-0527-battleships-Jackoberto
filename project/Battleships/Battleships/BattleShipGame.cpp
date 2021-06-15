#include "BattleShipGame.h"

#include <iostream>
#include "CellState.h"

#define CHECK_CONSOLE_ERROR(insertedCode) if (cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); insertedCode}

using namespace std;

void BattleShipGame::displayBoard(const Player player, const bool see_occupied)
{
    Cell (*board)[10];
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
           switch (board[i][j].cell_state)
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

int BattleShipGame::getCoordinate(const char key)
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
    empty_cell = Cell(Empty);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            board_P1[i][j] = empty_cell;
            board_P2[i][j] = empty_cell;
        }
    ships_P1 = 16;
    ships_P2 = 16;
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

void BattleShipGame::setOutShips(const Player player)
{
    Cell (*board)[10];
    if (player == One)
        board = board_P1;
    else
        board = board_P2;
    Ship* ships[]
    {
        new Ship(5),
        new Ship(4),
        new Ship(3),
        new Ship(2),
        new Ship(2)
    };
    int x = -1, y = -1;
    char first;
    for (int i = 0; i < 5; i++)
    {
        while (true)
        {
            clearConsole();
            cout << "Player " << player + 1 << endl;
            cout << "Place A Ship " << "(" << ships[i]->size << ")" << endl << "You Have " << 5 - i << " Ships Left" << endl;
            displayBoard(player, true);
            cin >> first >> x;
            CHECK_CONSOLE_ERROR(continue;)
            first = toupper(first);
            y = getCoordinate(first);
            if (x == -1 || y < 0 || y > 9)
                continue;
            cout << "Do You Wanna Place It Vertically (0) no, (1) yes" << endl;
            int horizontal;
            cin >> horizontal;
            CHECK_CONSOLE_ERROR(continue;)
            if (i + ships[i]->size > 9)
            {
                cout << "Ship doesn't fit here";
                continue;
            }

            bool space_is_available = true;
            for (int j = 0; j < ships[i]->size; j++)
            {
                if (y + j > 9)
                {
                    space_is_available = false;
                    break;
                }
                if (!horizontal)
                {
                    if (board[x][y + j].cell_state != Empty)
                    {
                        space_is_available = false;
                        break;
                    }
                    if (x + 1 <= 9 && board[x + 1][y + j].cell_state != Empty)
                    {
                        space_is_available = false;
                        break;
                    }
                    if (x - 1 >= 0 && board[x - 1][y + j].cell_state != Empty)
                    {
                        space_is_available = false;
                        break;
                    }
                }
                else
                {
                    if (board[x + j][y].cell_state != Empty)
                    {
                        space_is_available = false;
                        break;
                    }
                    if (y + 1 <= 9 && board[x + j][y + 1].cell_state != Empty)
                    {
                        space_is_available = false;
                        break;
                    }
                    if (y - 1 >= 0 && board[x + j][y - 1].cell_state != Empty)
                    {
                        space_is_available = false;
                        break;
                    }
                }
            }
            if (!horizontal)
            {
                if (y + 1 <= 9 && board[x][y+1].cell_state != Empty)
                {
                    space_is_available = false;
                }
                if (y - 1 >= 0 && board[x][y-1].cell_state != Empty)
                {
                    space_is_available = false;
                } 
            }
            else
            {
                if (x + 1 <= 9 && board[x+1][y].cell_state != Empty)
                {
                    space_is_available = false;
                }
                if (x - 1 >= 0 && board[x][y+1].cell_state != Empty)
                {
                    space_is_available = false;
                } 
            }
            if (!space_is_available)
            {
                continue;
            }
            for (int j = 0; j < ships[i]->size; j++)
            {
                if (!horizontal)
                    board[x][y + j] = Cell(ships[i], Occupied);
                else
                    board[x + j][y] = Cell(ships[i], Occupied);
            }
            break;
        }
    }
    clearConsole();
}

void BattleShipGame::turn(const Player player)
{
    Cell (*board)[10];
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
        CHECK_CONSOLE_ERROR(continue;)
        first = toupper(first);
        y = getCoordinate(first);
        if (x == -1 || y < 0 || y > 9)
            continue;
        if (board[x][y].cell_state != Miss && board[x][y].cell_state != Hit)
        {
            if (board[x][y].cell_state == Occupied)
            {
                board[x][y].cell_state = Hit;
                cout << "You Hit A Ship" << endl;
                *ships -= 1;
                board[x][y].ship->cells_left -= 1;
                if (board[x][y].ship->cells_left == 0)
                {
                    cout << "You Sunk A Ship" << endl;
                    delete board[x][y].ship;
                }
                else
                {
                    board[x][y].ship = nullptr;
                }
            }
            else if (board[x][y].cell_state == Empty)
            {
                board[x][y].cell_state = Miss;
                cout << "You Missed" << endl;
            }
            break;
        }
    }
}