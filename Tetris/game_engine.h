#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "public.h"
#include "board.h"
#include "cell.h"
#include "shape.h"
#include "oshape.h"
#include "sshape.h"
#include "zshape.h"
#include "tshape.h"
#include "ishape.h"
#include "jshape.h"
#include "lshape.h"

class gameEngine
{
public:
    gameEngine(int, int, int, int);
    board& GetMainBoard() { return MainBoard; }
    board& GetNextBoard() { return NextBoard; }
    bool GetAbleDown() { return AbleDown; }
    void PlaceShapeNext();
    void PlaceShapeMain();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void ClearRows();
    int num_rows_cld();
    void rows_move_down();
    void rotate();
    int Score();
    ~gameEngine();



private:
    void TraverseRows(int* cld_rows = NULL);
    int SetShapeColor(int);
    shape* PlaceShape(board &, int, int, int);
    bool IsMoveable(int, int, bool);
    void move(int, int);
    board MainBoard;
    board NextBoard;
    int m_ishape;
    shape* tracked_shape;
    bool AbleDown;
};

#endif // GAME_ENGINE_H
