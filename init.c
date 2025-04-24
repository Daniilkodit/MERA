#include "head.h"
#include "stdlib.h"

#define RAND_64 ((U64)rand() + (U64)rand()<<15 +(U64)rand()<<30 +(U64)rand()<<45 + ((U64)rand() & 0xf)<<60)
int SQ120TO64[BRD_SQ_NUM];
int SQ64TO120[64];

U64 SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][120];
U64 SideKey;
U64 CastleKeys[16];

void InitHashKeys(void)
{
    int i,j;
    for(i = 0;i<13;i++)
    {
        for(j = 0;j<120;j++)
        {
            PieceKeys[i][j] = RAND_64;
        }
    }
    SideKey = RAND_64;
    for(i=0;i<16;i++)
    {
        CastleKeys[i] = RAND_64;
    }
}
void InitBitMask(void)
{
    int i  = 0;
    for(i = 0;i<64;i++)
    {
        SetMask[i] = 0ULL;
        ClearMask[i] = 0ULL;
    }
    for( i = 0;i<64;i++)
    {
        SetMask[i] = (1ULL<<i);
        ClearMask[i] = ~SetMask[i];
    }
    

}
void InitSq120to64(void)
{
    int i = 0, file = FILE_A, rank = RANK_1;
    int sq, sq64 = 0;
    for(i = 0;i<BRD_SQ_NUM;i++)
    {
        SQ120TO64[i] = 65;
    }
    for(i = 0;i<64;i++)
    {
        SQ64TO120[i] = 120;
    }
    for(rank = RANK_1;rank<=RANK_8;rank++)
    {
        for(file = FILE_A;file<=FILE_H;file++)
        {
            sq = FR2SQ(file,rank);
            SQ64TO120[sq64] = sq;
            SQ120TO64[sq] = sq64;
            sq64++;
        }
    }
    return;
}
void Allinit(void)
{
    InitSq120to64();
    InitBitMask();
    InitHashKeys();
    return;
}