#include "game_engine.h"

gameEngine::gameEngine(int main_x, int main_y, int next_x, int next_y)
    : MainBoard(main_x, main_y, MAIN_BOARD_HEIGHT, MAIN_BOARD_WIDTH),
      NextBoard(next_x, next_y, NEXT_BOARD_HEIGHT, NEXT_BOARD_WIDTH)
{
    QTime time = QTime::currentTime();
    int seed = time.second() * 10000 + time.msec();
    m_ishape = 0;
    AbleDown = true;
    tracked_shape = NULL;
    qsrand(seed);
}

int gameEngine::SetShapeColor(int _color)
{
    int color = tracked_shape->get_color();

    for(int i = 0; i < 4; i++)
    {
        QPoint tmp = tracked_shape->get_a_cell(i).get_location();

        int r = tmp.x();
        int c = tmp.y();

        MainBoard.getcell(r, c).set_color(_color);
    }

    return color;
}

void gameEngine::rotate()
{
    SetShapeColor(NO_COLOR);

    tracked_shape->rotate();

    SetShapeColor(tracked_shape->get_color());
}

shape* gameEngine::PlaceShape(board& bd, int hrz, int vrtx, int num)
{
    shape* _shape = NULL;

    switch (num)
    {
    case L_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(L_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new lshape(tmp, bd);
    }
        break;
    case J_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(J_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new jshape(tmp, bd);
    }
        break;

    case I_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(I_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new ishape(tmp, bd);
    }
        break;

    case T_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(T_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new tshape(tmp, bd);
    }
        break;

    case Z_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(Z_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new zshape(tmp, bd);
    }
        break;

    case S_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(S_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new sshape(tmp, bd);
    }
        break;

    case O_SHAPE:
    {
        const QPoint point = bd.GetStartLocation(O_SHAPE, hrz, vrtx);
        cell& tmp = bd.getcell(point.x(), point.y());
        _shape = new oshape(tmp, bd);
    }
        break;

    default:
        break;
    }

    return _shape;
}

void gameEngine::PlaceShapeNext()//在小显示区里放形状
{
    int ishape = qrand() % NUM_OF_SHAPES;
    PlaceShape(NextBoard, HRZ_CENTER, VRTX_CENTER, ishape);
    m_ishape = ishape;
}

void gameEngine::PlaceShapeMain()//主显示区里放形状
{
    AbleDown = true;

    if(tracked_shape != NULL)
    {
        delete tracked_shape;
        tracked_shape = NULL;
    }

    tracked_shape = PlaceShape(MainBoard, HRZ_CENTER, VRTX_START, m_ishape);
}

void gameEngine::ClearRows()
{
    TraverseRows();
}

int gameEngine::num_rows_cld()
{
    int num = 0;

    TraverseRows(&num);

    return num;
}

void gameEngine::TraverseRows(int* cld_rows)//遍历一整行，并清空
{
    for(int i = MAIN_BOARD_HEIGHT - 1; i >= 0; i--)
    {
        if(MainBoard.full(i))
        {
            if(cld_rows == NULL)
            {
                MainBoard.ClearRow(i);
            }
            else
            {
                ++*cld_rows;
            }
        }
    }
}

int gameEngine::Score()
{
    int num = num_rows_cld();

    return num * num;
}

void gameEngine::rows_move_down()//整行下沉
{
    int pointer_empty = MAIN_BOARD_HEIGHT - 1;
    int pointer_something = pointer_empty;

    for(int i = pointer_empty; i >= 0; i--)
    {
        if(MainBoard.empty(i))
        {
            pointer_something = i - 1;

            for(int j = pointer_something; j >=0; j--)
            {
                if(MainBoard.some(j))
                {
                    MainBoard.row_cut_paste(j, i);
                    break;
                }
            }
        }
    }
}

void gameEngine::MoveDown()
{
    bool moveable = IsMoveable(DOWN, NO_MOVE, true);
    if(moveable) move(DOWN, NO_MOVE);
}

void gameEngine::MoveLeft()
{
    bool moveable = IsMoveable(NO_MOVE, LEFT, false);
    if(moveable) move(NO_MOVE, LEFT);
}

void gameEngine::MoveRight()
{
    bool moveable = IsMoveable(NO_MOVE, RIGHT, false);
    if(moveable) move(NO_MOVE, RIGHT);
}

bool gameEngine::IsMoveable(int up_down, int left_right, bool is_move_down)
{
    bool move_able = false;
    int color = NO_COLOR;

    for(int i = 0; i < 4; i++)
    {
        cell& tmp = tracked_shape->get_a_cell(i);
        color = MainBoard.GetCellColor(tmp);
        MainBoard.setcolor(tmp, NO_COLOR);
    }

    for(int i = 0; i < 4; i++)
    {
        int r = tracked_shape->get_a_cell(i).get_location().x();
        int c = tracked_shape->get_a_cell(i).get_location().y();

        r += up_down;
        c += left_right;

        if(r >= 0 && r < MAIN_BOARD_HEIGHT && c >= 0 && c < MAIN_BOARD_WIDTH && MainBoard.getcell(r, c).GetColor() == NO_COLOR)
        {
            move_able = true;
        }
        else
        {
            if((r >= MAIN_BOARD_HEIGHT || MainBoard.getcell(r, c).GetColor() != NO_COLOR) && is_move_down)
            {
                AbleDown = false;
            }

            move_able = false;
            break;
        }
    }

    if(!move_able)
    {
        for(int i = 0; i < 4; i++)
        {
            cell& tmp = tracked_shape->get_a_cell(i);
            MainBoard.setcolor(tmp, color);
        }
    }

    return move_able;
}

void gameEngine::move(int up_down, int left_right)
{
    for(int i = 0; i < 4; i++)
    {
        cell& tmp = tracked_shape->get_a_cell(i);

        int r = tmp.get_location().x();
        int c = tmp.get_location().y();

        r += up_down;
        c += left_right;

        cell& pass = MainBoard.getcell(r, c);

        tracked_shape->set_a_cell(i, pass);

        MainBoard.setcolor(pass, tracked_shape->get_color());
    }
}

gameEngine::~gameEngine()
{

}
