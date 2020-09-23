#include "shape.h"

shape::shape(cell& first_cell, board& bd)
    : m_bd(bd)
{
    color = NO_COLOR;
    for(int i = 0; i < 4; i++)
    {
        cells[i] = cell();
    }//临时构造一个cell数组大小为4，因为一个形状就是4个方块组成的

    cells[0] = first_cell;
    which_position = 0;
}

void shape::rotate()
{
    ComputeRotatePositions();//每一个的旋转判断都不一样

    which_position++;
    which_position = which_position % 4;

    if(VaildPosition(which_position))
    {
        for(int i = 0; i < 4; i++)
        {
            int r = RotatePositions[which_position][i].x();
            int c = RotatePositions[which_position][i].y();

            cells[i] = m_bd.getcell(r, c);
        }
    }
    else
    {
        which_position--;
    }
}

bool shape::VaildPosition(int which)
{
    bool is_vaild = false;

    for(int i = 0; i < 4; i++)
    {
        QPoint tmp = RotatePositions[which][i];

        int x = tmp.x();
        int y = tmp.y();

        if(x >= 0 && y >= 0 && x < MAIN_BOARD_HEIGHT && y < MAIN_BOARD_WIDTH && m_bd.getcell(x, y).GetColor() == NO_COLOR)
            is_vaild = true;
        else
        {
            is_vaild = false;
            break;
        }
    }

    return is_vaild;
}


void shape::ComputeRotatePositions()
{
    for(int i = 0; i < 4; i++)
    {
        RotatePositions[i][1] = cells[1].get_location();
    }
}

shape::~shape()
{

}
