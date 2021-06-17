#include "Cell.h"

Cell::Cell()
{
    ship = nullptr;
    cell_state = Empty;
}

Cell::Cell(const CellState state)
{
    ship = nullptr;
    cell_state = state;
}

Cell::Cell(const std::shared_ptr<Ship> ship, const CellState cell_state)
{
    this->ship = ship;
    this->cell_state = cell_state;
}
