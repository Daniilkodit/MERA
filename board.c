#include "head.h"
#include "stdio.h"

void ReseatBoard(S_Board * pos)
{
    int index = 0;
    for(index = 0;index<BRD_SQ_NUM;++index)
    {
        pos->pieces[index] = OFFBOARD;
    }
    for(index = 0 ;index<64;index++)
    {
        pos->pieces[SQ120(index)] = EMPTY;
    }
    for(index = 0 ;index<3;index++)
    {
        pos->majPce[index] = 0;
        pos->minPce[index] = 0;
        pos->bigPce[index] = 0;
        pos->pawns[index] = 0LL;
    }
    for(index = 0 ;index<13;index++) pos->pceNum[index] =0;

    pos->KingSQ[WHITE] = pos->KingSQ[BLACK] = EMPTY;
    pos->side = BOTH;
    pos->enPas = NO_SQ;

    pos->hisPly = 0;
    pos->ply = 0;

    pos->fiftyMove = 0;
    pos->castlePerm = 0;
    pos->posKey = 0LL;

}