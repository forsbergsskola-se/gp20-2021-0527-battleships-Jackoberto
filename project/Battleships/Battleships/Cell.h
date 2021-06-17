#pragma once
#include <memory>

#include "Ship.h"
#include "CellState.h"

struct Cell
{
    std::shared_ptr<Ship> ship;
    CellState cell_state;
    Cell();
    Cell(CellState state);
    Cell(const std::shared_ptr<Ship> ship, CellState cell_state);
};