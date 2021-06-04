#pragma once
#include "Ship.h"
#include "CellState.h"

struct Cell
{
    Ship* ship;
    CellState cell_state;
    Cell();
    Cell(CellState cell_state);
    Cell(Ship* ship, CellState cell_state);
};