#ifndef SHAPE_H
#define SHAPE_H
//是所有图形的父类，每一个图形都要继承它

class shape
{
public:
    shape(cell&,board& bd);//初始方格加棋盘编号得到形状生成。
    virtual~shape()=0;
    virtual void   rotate();//旋转函数，因为不同形状的旋转实现不同，所以采用虚函数重载
    int get_color()
        {return color;}
    cell&getacell(int n)
    {return cells[n];}
    void setacell(int n,cell &_cell;)
    {cells[n]=_cell;}
protected:
    virtual void compute_rotate_positions();
    bool is_valid_position(int );//判断是否是有效位置
    int color;
    cell cells[NUMOFCELLS];
    Qpoint rotate_positions[NUMBER_OF_ROTATE_POSITIONS][NUMOFCELLS];
    int which_position;
    board m_bd;//这个图形是要放到那块显示区的
};

#endif // SHAPE_H
