#include "Cell.h"

Cell::Cell()
{
    ship = nullptr;
    cell_state = Empty;
}

Cell::Cell(CellState state)
{
    ship = nullptr;
    cell_state = state;
}

Cell::Cell(Ship* ship_ptr, CellState state)
{
    ship = ship_ptr;
    cell_state = state;
}
