#include "board.h"

board::board(int x, int y, int board_height, int board_width)
{
    board_h = board_height;
    board_w = board_width;

    cells = new cell[board_height * board_width];

    for(int r = 0; r < board_height; r++)
    {
        for(int c = 0; c < board_width; c++)
        {
            float _x = float(c) * float(CELL_LENGTH) + float(x);
            float _y = float(r) * float(CELL_LENGTH) + float(y);

            QPoint location(r, c);
            QPointF position(_x, _y);

            cells[r * board_width + c] = cell(location, position);
        }
    }
}

void board::setcolor(cell& _cell, int _color)//放颜色
{
    int _index = _cell.get_location().x() * board_w + _cell.get_location().y();
    cells[_index].set_color(_color);
}

int board::GetCellColor(cell& _cell)//得到方格颜色
{
    int _index = _cell.get_location().x() * board_w + _cell.get_location().y();
    return cells[_index].GetColor();
}

void board::clearboard()//清空整个显示区
{
    for(int r = 0; r < board_h; r++)
    {
        for(int c = 0; c < board_w; c++)
        {
            cells[r * board_w + c].set_color(NO_COLOR);
        }
    }
}

const QPoint board::GetStartLocation(int _shape, int hrz, int vrtx)//得到哪里放新的形状（这个定位到形状的核心方块的位置）
//hrz，vrtx本质上是个bool值，判断到底应该放在哪里（有中间和头的区别）
{
    int h = 0;
    int w = 0;

    switch (_shape)
    {
    case L_SHAPE:
        w = (hrz == HRZ_CENTER ? board_w / 2 : 0);
        h = (vrtx == VRTX_CENTER ? board_w / 2 + 1 : 2);
        break;

    case J_SHAPE:
        w = (hrz == HRZ_CENTER ? board_w / 2 - 1 : 0);
        h = (vrtx == VRTX_CENTER ? board_w / 2 + 1 : 2);
        break;

    case I_SHAPE:
        w = (hrz == HRZ_CENTER ? board_w / 2 : 0);
        h = (vrtx == VRTX_CENTER ? board_w / 2 + 1 : 3);
        break;

    case Z_SHAPE:
        w = (hrz == HRZ_CENTER ? board_w / 2 + 1 : 0);
        h = (vrtx == VRTX_CENTER ? board_w / 2 : 1);
        break;

    case T_SHAPE:
        w = (hrz == HRZ_CENTER ? board_w / 2 : 0);
        h = (vrtx == VRTX_CENTER ? board_w / 2 : 1);
        break;

    case S_SHAPE:
    case O_SHAPE:
        w = (hrz == HRZ_CENTER ? board_w / 2 - 1 : 0);
        h = (vrtx == VRTX_CENTER ? board_w / 2 : 1);
        break;

    default:
        break;
    }

    return QPoint(h, w);
}

cell& board::getcell(int r, int c) const
{
    return cells[r * board_w + c];
}

bool board::full(int num)
{
    int count = 0;

    for(int c = 0; c < board_w; c++)
    {
        count = (cells[num * board_w + c].GetColor() != NO_COLOR ? ++count : count);
    }

    return (count == board_w);
}

bool board::empty(int num)
{
    int count = 0;

    for(int c = 0; c < board_w; c++)
    {
        count = (cells[num * board_w + c].GetColor() == NO_COLOR ? ++count : count);
    }

    return (count == board_w);
}

bool board::some(int num)
{
    return (!empty(num) && !full(num));
}

void board::ClearRow(int num)
{
    for(int c = 0; c < board_w; c++)
    {
        cells[num * board_w + c].set_color(NO_COLOR);
    }
}

void board::row_cut_paste(int from, int to)
{
    for(int c = 0; c < board_w; c++)
    {
        int color = cells[from * board_w + c].GetColor();
        cells[to * board_w + c].set_color(color);
        cells[from * board_w + c].set_color(NO_COLOR);
    }
}

board& board::copy(const board& bd)
{
    board_h = bd.board_h;
    board_w = bd.board_w;

    cells = new cell[board_h * board_w];

    for(int r = 0; r < board_h; r++)
    {
        for(int c = 0; c < board_w; c++)
        {
            cells[r * board_w + c] = bd.cells[r * board_w + c];
        }
    }

    return *this;
}

board::~board()
{
    delete[] cells;
    cells = NULL;
}
