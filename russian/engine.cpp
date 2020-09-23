#include "engine.h"

engine::engine(int mainx,int mainy,int nextx,int nexty)
      :mainbd(mainx,mainy,MAINBOARDHEIGHT,MAINBOAODWIDTH),
      :nextbd(nextx,nexty,MIANBOARDHEIGHT,MIANBOARDWIDTH)
{QTime time=QTime::currentTime();
    int seed=time.second()*TIMESCALAR+time.msec();
    mishape=0;
    movedownok=true;
    trackedshape=NULL;
    qsrand(seed);
}
int engine::setshapecolor(int ccolor)
{int color=trackedshape->get_color();
 for(int i=0;i<NUMOFCELLS;i++)
 {QPoint tmp=trackedshape->getacell(i).get_loaction();
     int r=tmp.x();
     int c=tmp.y();
     mainbd.getacell(r,c).setcolor(ccolor);
 }
return color;
}
void engine::rotate()
{setshapecolor(NOCOLOR);
trackedshape->rotate();
setshapecolor(trackedshape->get_color());
}
shape* engine::placeashape(board & bd, int hrz, int vrtx, int num)
//bd是哪个棋盘，主棋盘还是下一个,num形状的编号，hrz，vrtx形状位置
{shape * cshape=NULL;
 switch(num)
  {case LSHAPE:
      {const QPoint point=bd.getstartloaction(LSHPAE,hrz,vrtx);
       cell &tmp=bd.getacell(point.x(),point.y());//根据初始方格花整个图形
       cshape =new lshape(tmp,bd);//父类指针指向子类对象
       }
     break;
 case JSHAPE:
       {const QPoint point=bd.getstartloaction(JSHPAE,hrz,vrtx);
        cell &tmp=bd.getacell(point.x(),point.y());
        cshape =new jshape(tmp,bd);
        }
     break;
 case ISHAPE:
       {const QPoint point=bd.getstartloaction(ISHPAE,hrz,vrtx);
        cell &tmp=bd.getacell(point.x(),point.y());
        cshape =new ishape(tmp,bd);
        }
     break;
 case TSHAPE:
       {const QPoint point=bd.getstartloaction(TSHPAE,hrz,vrtx);
        cell &tmp=bd.getacell(point.x(),point.y());
        cshape =new tshape(tmp,bd);
        }
     break;
 case ZSHAPE:
       {const QPoint point=bd.getstartloaction(ZSHPAE,hrz,vrtx);
        cell &tmp=bd.getacell(point.x(),point.y());
        cshape =new zshape(tmp,bd);
        }
     break;
 case SSHAPE:
       {const QPoint point=bd.getstartloaction(SSHPAE,hrz,vrtx);
        cell &tmp=bd.getacell(point.x(),point.y());
        cshape =new sshape(tmp,bd);
        }
     break;
 case OSHAPE:
       {const QPoint point=bd.getstartloaction(OSHPAE,hrz,vrtx);
        cell &tmp=bd.getacell(point.x(),point.y());
        cshape =new oshape(tmp,bd);
        }
  break;
 default:break;
  }
 return cshape;
}
void engine::nextplaceashape()
{int ishape=qrand()%7;
    placeashape(nextbd,)

}
void engine::mainplaceashape()
{int ishape=qrand()%7;}
