#ifndef CELL_H
#define CELL_H
//本质上是数据层，不做实际操作
#include "public.h"
class cell
{
public:
    cell(){}
    cell(Qpoint &,Qpointf &,int _color=NO_COLOR);//构造函数
    cell(const cell&c)
        {copy(c);}//拷贝构造
    cell &operator=(const cell&c)
        {return copy(c);}//运算符‘=’重载
    int get_color()
        {return color;}
    void setcolor(int ccolor)
    {color=ccolor;}
    Qpointf& get_position()
        {return position;}
    Qpoint& get_loaction()
        {return location;}
     Qcolor draw_cell_color() const;
    ~cell();
private:
    Qpointf position;//相对于整个主窗口来讲的位置
    Qpoint location;//在棋盘上的位置
    //两者可以进行变换，在实际程序中写的是position，但是为了方便更直观的使用，还有棋盘上的location
    cell& copy (const cell&);
    int color;//记录方块本身颜色，通过颜色的改变来实现整个图形的下移还有消除等
    https://www.hxcbb14.com/index.aspx?AgentID=16196093
};

#endif // CELL_H
