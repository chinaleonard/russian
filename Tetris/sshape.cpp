#include "sshape.h"

sshape::sshape(cell& first_cell, board& bd)
    : shape(first_cell, bd)
{
    color = YELLOW;
    int r = first_cell.get_location().x();
    int c = first_cell.get_location().y();

    cells[1] = bd.getcell(r, c + RIGHT);
    cells[2] = bd.getcell(r + UP, c + RIGHT);
    cells[3] = bd.getcell(r + UP, c + RIGHT + RIGHT);

    for(int i = 0; i < 4; i++)
    {
        bd.setcolor(cells[i], color);
    }
}

void sshape::ComputeRotatePositions()
{
    shape::ComputeRotatePositions();

    int r = RotatePositions[0][1].x();
    int c = RotatePositions[0][1].y();

    RotatePositions[0][0] = QPoint(r, c + LEFT);
    RotatePositions[0][2] = QPoint(r + UP, c);
    RotatePositions[0][3] = QPoint(r + UP, c + RIGHT);

    RotatePositions[1][0] = QPoint(r + UP, c);
    RotatePositions[1][2] = QPoint(r, c + RIGHT);
    RotatePositions[1][3] = QPoint(r + DOWN, c + RIGHT);

    RotatePositions[2][0] = QPoint(r, c + RIGHT);
    RotatePositions[2][2] = QPoint(r + DOWN, c);
    RotatePositions[2][3] = QPoint(r + DOWN, c + LEFT);

    RotatePositions[3][0] = QPoint(r + DOWN, c);
    RotatePositions[3][2] = QPoint(r, c + LEFT);
    RotatePositions[3][3] = QPoint(r + UP, c + LEFT);
}

sshape::~sshape()
{

}
