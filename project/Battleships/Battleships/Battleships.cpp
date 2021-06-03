#include "BattleShipGame.h"
#include "Fibonacci.h"
#include "RandomTesting.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Fibonacci::test(20);
    // RandomTesting::testVariableNum();
    auto battle_ships = BattleShipGame();
    battle_ships.run();
    return 0;
}