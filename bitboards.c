#include "stdio.h"
#include "head.h"
const int BitTable[64] = {
    63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
    51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
    26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
    58, 20, 37, 17, 36, 8
  };
  
int count_bit(U64 b) {
    int r;
    for(r = 0; b; r++, b &= b - 1); // b &= b - 1 заменяет один бит с 1 на 0 самый крайниий
    return r;
}

int pop_bit(U64 *bb) {
    U64 b = *bb ^ (*bb - 1);
    unsigned int fold = (unsigned) ((b & 0xffffffff) ^ (b >> 32));
    *bb &= (*bb - 1);
    return BitTable[(fold * 0x783a9b23) >> 26];
}
  
void PrintBoard(U64 bb)
{
    U64 mask = 1ULL;
    int rank,file,sq,sq64;
    for( rank = RANK_8;rank>=0;rank--)
    {
        for( file = FILE_A;file<=FILE_H;file++)
        {
            sq = FR2SQ(file,rank); 
            sq64 = SQ64(sq);
            if((mask<<sq64)&bb) printf("X");
            else printf("-");
        }
        printf("\n");
    }
    printf("\n");
}