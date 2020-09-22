//棋盘有两种，一种是中心的游戏主棋盘，另一个是边上的显示下一个图形的小棋盘。
#ifndef BOARD_H
#define BOARD_H
#include"public.h"
#include "cell.h"
class board
{private:
 board& copy(const board&);
 cell* cells;//棋盘由很多个格子组成
 int boardh;
 int boardw;
public:
    board(){ };
    board(int,int,int,int);
    board (const board &bd){copy(bd);}//构造函数
    cell &getacell(int ,int) const;
    void clearboard();
    void setcellcolor(cell &, int );
    void updaterows();//更新行
    int getcellcolor(cell&);//得到格子颜色
    bool isfull(int );//判断行是否可以消除
    bool issth(int );//判断有无
    bool isempty(int );
    void clearrow(int );//清空行
    void rowcutpaste(int,int );//分离一整个图形
    const Qpoint getstartloaction(int ,int,int);//得到初始位置
    board &operator=(board &bd)//重载=运算符，使得棋盘的更新更方便
    {return copy(bd);}
    ~board();

};

#endif // BOARD_H
