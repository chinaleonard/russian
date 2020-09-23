#ifndef SSHAPE_H
#define SSHAPE_H

#include "public.h"
#include "shape.h"
#include "board.h"

class sshape : public shape
{
public:
    sshape(cell &, board &);
    ~sshape();

private:
    virtual void ComputeRotatePositions() override;
};

#endif // SSHAPE_H
