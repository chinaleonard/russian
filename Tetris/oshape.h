#ifndef OSHAPE_H
#define OSHAPE_H

#include "public.h"
#include "shape.h"
#include "board.h"

class oshape : public shape
{
public:
    oshape(cell &, board &);
    virtual void rotate() override;
    ~oshape();

private:
    virtual void ComputeRotatePositions() override;
};
#endif // OSHAPE_H
