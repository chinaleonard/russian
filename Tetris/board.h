#ifndef BOARD_H
#define BOARD_H
//棋盘有两种，一种是中心的游戏主棋盘，另一个是边上的显示下一个图形的小棋盘。
#include "public.h"
#include "cell.h"

class board
{
public:
    board() {  }
    board(int, int, int, int);
    board(const board& bd) { copy(bd); }//构造函数
    cell& getcell(int, int) const;
    void clearboard();
    void setcolor(cell &, int);
    void UpdateRow();//更新行
    int GetCellColor(cell &);//得到格子颜色
    bool full(int);;//判断行是否可以消除
    bool empty(int);
    bool some(int);//判断有无
    void ClearRow(int);//清空行
    void row_cut_paste(int, int);//分离一整个图形
    const QPoint GetStartLocation(int, int, int);
    //得到初始位置，从而得到形状刚诞生时存放的位置
    board& operator=(const board& bd) { return copy(bd); }
   //重载=运算符，使得棋盘的更新更方便
    ~board();

private:
    board& copy(const board&);
    cell* cells;//棋盘由很多个格子组成
    int board_h;
    int board_w;
};

#endif // BOARD_H
