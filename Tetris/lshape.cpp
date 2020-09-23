#include "lshape.h"

lshape::lshape(cell& first_cell, board& bd)
    : shape(first_cell, bd)
{
    color = PURPLE;
    int r = first_cell.get_location().x();
    int c = first_cell.get_location().y();

    cells[1] = bd.getcell(r, c + LEFT);
    cells[2] = bd.getcell(r + UP, c + LEFT);
    cells[3] = bd.getcell(r + UP + UP, c + LEFT);

    for(int i = 0; i < 4; i++)
    {
        bd.setcolor(cells[i], color);
    }
}

void lshape::ComputeRotatePositions()
{
    shape::ComputeRotatePositions();

    int r = RotatePositions[0][1].x();
    int c = RotatePositions[0][1].y();

    RotatePositions[0][0] = QPoint(r, c + RIGHT);
    RotatePositions[0][2] = QPoint(r + UP, c);
    RotatePositions[0][3] = QPoint(r + UP + UP, c);

    RotatePositions[1][0] = QPoint(r + DOWN, c);
    RotatePositions[1][2] = QPoint(r, c + RIGHT);
    RotatePositions[1][3] = QPoint(r, c + RIGHT + RIGHT);

    RotatePositions[2][0] = QPoint(r, c + LEFT);
    RotatePositions[2][2] = QPoint(r + DOWN, c);
    RotatePositions[2][3] = QPoint(r + DOWN + DOWN, c);

    RotatePositions[3][0] = QPoint(r + UP, c);
    RotatePositions[3][2] = QPoint(r, c + LEFT);
    RotatePositions[3][3] = QPoint(r, c + LEFT + LEFT);
}

lshape::~lshape()
{

}
