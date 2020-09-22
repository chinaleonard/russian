#ifndef SHAPE_H
#define SHAPE_H
//是所有图形的父类，每一个图形都要继承它

class shape
{
public:
    shape(cell&,board& bd);//初始方格加棋盘编号得到形状生成。
    virtual~shape()=0;
    virtual void   rotate();
    int get_color()
        {return color;}
    cell&getacell(int n)
    {return cells[n];}
    void setacell(int n,cell &_cell;)
    {cells[n]=_cell;}
protected:
    virtual void compute_rotate_positions();
    bool is_valid_position(int );
    int color;
    cell cells[NUMOFCELLS]
    Qpoint rotate_positions[NUMBER_OF_ROTATE_POSITIONS][NUMOFCELLS];
    int which_position;
    board m_bd;
};

#endif // SHAPE_H
