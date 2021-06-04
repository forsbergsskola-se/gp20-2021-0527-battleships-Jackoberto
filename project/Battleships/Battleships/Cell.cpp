#include "Cell.h"

Cell::Cell()
{
    this->ship = nullptr;
    this->cell_state = Empty;
}

Cell::Cell(CellState cell_state)
{
    this->ship = nullptr;
    this->cell_state = cell_state;
}

Cell::Cell(Ship* ship, CellState cell_state)
{
    this->ship = ship;
    this->cell_state = cell_state;
}
