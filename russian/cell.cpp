#include "cell.h"

cell::cell(QPoint& clocation,QPointF& cposition,int ccolor)
{location=clocation;
 position=cposition;
 color=ccolor;

}
cell &cell::copy(const cell &c)
{color=c.color;
 position=c.position;
 location=c.location;
 return *this;
}
QColor cell::draw_cell_color()const
{QColor qcolor;
 switch (color)
     {
 case RED:
     qcolor=QColor("red");
     break;
 case YELLOW:
     qcolor=QColor("yellow");
     break;
 case BLUE:
     qcolor=QColor("blue");
     break;
 case GRAY:
     qcolor=QColor("gray");
     break;
 case BLACK:
     qcolor=QColor("black");
     break;
 case PURPLE:
     qcolor=QColor("purple");
     break;
 case ORANGE:
     qcolor=Qcolor("orange");
     break;
 default:
     qcolor=QColor("transparent");
     break;
     }
 return qcolor;
}
cell ::~cell()
{

}
