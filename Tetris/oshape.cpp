#include "oshape.h"

oshape::oshape(cell& first_cell, board& bd)
    : shape(first_cell, bd)
{
    color = ORANGE;
    int r = first_cell.get_location().x();
    int c = first_cell.get_location().y();

    cells[1] = bd.getcell(r, c + RIGHT);
    cells[2] = bd.getcell(r + UP, c);
    cells[3] = bd.getcell(r + UP, c + RIGHT);

    for(int i = 0; i < 4; i++)
    {
        bd.setcolor(cells[i], color);
    }
}

void oshape::rotate()
{

}

void oshape::ComputeRotatePositions()
{

}

oshape::~oshape()
{

}
