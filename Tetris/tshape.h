#ifndef TSHAPE_H
#define TSHAPE_H

#include "public.h"
#include "shape.h"
#include "board.h"

class tshape : public shape
{
public:
    tshape(cell &, board &);
    ~tshape();

private:
    virtual void ComputeRotatePositions() override;
};

#endif // TSHAPE_H
