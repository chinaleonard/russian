#ifndef SHAPE_H
#define SHAPE_H
//是所有形状的父类，每一个形状都要继承它
#include "public.h"
#include "cell.h"
#include "board.h"

class shape
{
public:
    shape(cell &, board& bd);//初始方格加棋盘编号得到形状生成的位置。
    virtual ~shape() = 0;
    virtual void rotate();
    int get_color() { return color; }
    cell& get_a_cell(int n) { return cells[n]; }
    void set_a_cell(int n, cell& _cell) { cells[n] = _cell; }
    

protected:
    virtual void ComputeRotatePositions();
    bool VaildPosition(int);//判断是否是有效位置
    int color;
    cell cells[4];//组成形状的数组
    QPoint RotatePositions[4][4];
    int which_position;//旋转按钮被按了几下（up键）
    board m_bd;//这个图形应该要放到哪块显示区
};

#endif // SHAPE_H
