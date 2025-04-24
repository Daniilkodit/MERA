#include "head.h"
#include"stdio.h"
U64 GeneratePosKey(const S_Board* pos)
{
    int sq = 0;
    U64 finalkey;
    int piece = EMPTY;
    for(sq = 0;sq<BRD_SQ_NUM;sq++)
    {
        piece = pos->pieces[sq];
        if(piece != NO_SQ && piece != EMPTY)
        {
            ASSERT(piece>=wP && piece<= bK);
            finalkey^= PieceKeys[piece][sq];
        }
    }
    if(pos->side == WHITE) finalkey ^= SideKey;
    if(pos->enPas != NO_SQ) //пешка походила на 2 клетки вперед типа
    {
        ASSERT(pos->enPas>0 && pos->enPas<BRD_SQ_NUM);
        finalkey ^= PieceKeys[EMPTY][pos->enPas];
    }
    ASSERT(pos->castlePerm>=0 && pos->castlePerm<=15 );
    finalkey ^= CastleKeys[pos->castlePerm];
    return finalkey;
}