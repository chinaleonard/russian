#ifndef ISHAPE_H
#define ISHAPE_H

#include "public.h"
#include "shape.h"
#include "board.h"

class ishape : public shape
{
public:
    ishape(cell &, board &);
    ~ishape();

private:
    virtual void ComputeRotatePositions() override;
};

#endif // ISHAPE_H
