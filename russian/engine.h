#ifndef ENGINE_H
#define ENGINE_H
#include"public.h"
#include"board.h"
#include"cell.h"
#include"shape.h"
#include"oshape.h"
#include"sshape.h"
#include"zshape.h"
#include"jshape.h"
#include"tshape.h"
#include"jshape.h"
#include"lshape.h"
class engine
{
public:
    engine(int ,int,int,int);
    board& getmainbd()
    {return mainbd;}
    board& getnextbd()
    {return nextbd;}
    bool getmovedownok()
    {return movedownok;}
    void nextplaceashape();
    void mainplaceashape();
    void movedown();
    void moveleft ();
    void moveright();
    void clearrows();
    int numrowscld();
    void rowsmovedown();
    void rotate();
    int computescore();
    ~engine();
private:
    void traverserows(int *cldrows=NULL)
    int setshapecolor(int );
    shape* placeashape(board& ,int,int,int);
    bool ismoveable(int,int ,bool);
    void move(int,int);
    board mainbd;
    board nextbd;
    int mishape;
    shape* trackedshape;
    bool movedownok;
};

#endif // ENGINE_H
