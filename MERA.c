#include "stdio.h"
#include "head.h"
int main(void)
{
    Allinit();
    U64 play = 0ULL;
    SETBIT(play,SQ64(D2));
    PrintBoard(play);
    
    /*for(i = 0;i<BRD_SQ_NUM;i++)
    {
        if(i%10==0)printf("\n");
        printf("%5d",SQ120TO64[i]); 
    }
    printf("\n");
    printf("\n");
    for(i = 0;i<64;i++)
    {
        if(i%8==0) printf("\n");
        printf("%5d",SQ64TO120[i]);
    }*/
    return 0;
}