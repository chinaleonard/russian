#include "board.h"

board::board()
{
cell &board::getacell(int r,int c)const
           {return cells[r*boardw+c];}
bool board::isfull(int num)
           {
    int count=0;
    for(int c=0;c<boardw;c++)
        count=(cells[num*boardw+c].get_color()!=NO_COLOR? ++count:count);
    return(count==boardw);
           }
bool board::isempty(int num)
{
int count=0;
for(int c=0;c<boardw;c++)
count=(cells[num*boardw+c].get_color()==NO_COLOR? ++count:count);
return(count==boardw);
}
bool board::issth(int num)
{return (isempty(num)&&isfull(num));}
void board::clearrow(int num)
{for(int c=0;c<boardw;c++)
    cell[num*boardw+c].setcolor(NO_COLOR);
}

void board::rowcutpaste(int from,int to)//消除一行并将上面的往下移一行
{for(int c-0;c<boardw;c++)
    {int color=cell[from*boardw+c].getcolor();
     cell(to*boardw+c).setcolor(color);
    cells[from*boardw+c].sercolor(NOCOLOR);
    }
board& board::copy(const board& bd)
{boardh=bd.boardh;
 boardw=bd.boardw;
 cells= new cell[boardh*boardw];
 for(int r=0;r<boardh;r++)
     for(int c-0;c<boardw;c++)
         cells[r*boardw+c]=bd::cells[r*boardw+c];
}
}

