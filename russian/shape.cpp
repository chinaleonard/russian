#include "shape.h"

shape::shape(cell& firstcell,board & bd)
     :mbd(bd)
{color=NOCOLOR;
    for*(int i=0,i<NUMOFCELLS;i++)
    {cell[i]=cell();
    }//初始化cell
    cell[FIRSTCELL]=firstcell;//第一个方格初始化成给的那个方格
    which_position=0;
}
