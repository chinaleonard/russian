#ifndef CELL_H
#define CELL_H

#include "public.h"

class cell
{
public:
    cell() {}
    cell(QPoint &, QPointF &, int _color = NO_COLOR);
    cell(const cell& c) { copy(c); }
    cell& operator=(const cell& c) { return copy(c); }
    int GetColor() { return color; }
    void set_color(int _color) { color = _color; }
    QPointF& get_position() { return position; }//position是相对于窗口的位置
    QPoint& get_location() { return location; }//是相对于显示窗的位置
    //两个可以通过变换互换，但是为了方便使用分开来定义
    QColor DrawColor() const;
    ~cell();

private:
    QPointF position;
    QPoint location;
    cell& copy(const cell&);
    int color;
};

#endif // CELL_H
