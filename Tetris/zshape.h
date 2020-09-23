#ifndef ZSHAPE_H
#define ZSHAPE_H

#include "public.h"
#include "shape.h"
#include "board.h"

class zshape : public shape
{
public:
    zshape(cell &, board &);
    ~zshape();

private:
    virtual void ComputeRotatePositions() override;
};

#endif // ZSHAPE_H
