#ifndef _HEAD_H
#define _HEAD_H

#include "stdlib.h"

#define DEBUG

#ifndef DEBUG

#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)){ \
printf("%s - Failed ",#n);\
printf("On %s ",__DATE__);\
printf("At %s ", __TIME__);\
printf("IN File %s ",__FILE__);\
printf("In Line %d ",__LINE__);\
exit(1);}
#endif

typedef unsigned long long U64;
#define NAME "MERA.1.0"
#define BRD_SQ_NUM 120 // размер доски
#define MAX_GAME_MOVES 2048 // половинчатые ходы

#define FR2SQ(f,r)  ((21+f) +(r*10))
#define SQ64(sq120) SQ120TO64[sq120] 
#define SQ120(sq64) SQ64TO120[sq64] 
#define POP(b) pop_bit(b)
#define CNT(b) count_bit(b)
#define CLRBIT(bb,sq) (bb &= ClearMask[sq])
#define SETBIT(bb,sq) (bb |= SetMask[sq])

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK};
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };

enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { WHITE, BLACK, BOTH};

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ, OFFBOARD
};
enum {FALSE,TRUE};

enum {WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8};  // 0 0 0 0 
typedef struct
{
    int move;
    int castlePerm;
    int enpas;
    int fifryMoves;
    U64 posKey;

} S_UNDO;
typedef struct
{
    int pieces[BRD_SQ_NUM];
    U64 pawns[3];
    int KingSQ[2]; // квадраты где находятся короли

    int side; // текущая сторона
    int enPas; // взятие пешки когда она сделала ход через клетки другой пешкой (взятие на проходе)
    // если пешка сделала ход на две клетки то эта enPas = const; иначе enPas = NO_SQ
    int fiftyMove; // правило 50 ходов
    int ply; // число половинчатых ходов в текущем поиске
    int hisPly; //число половинчатых ходов во всей игре
    U64 posKey; // позиция на доске

    int pceNum[13]; // колво фигур каждого вида
    int bigPce[3]; // колво фигур каждого вида кроме пешки по цветам
    int majPce[3]; // колво ферзей и ладей
    int minPce[3]; // колво коней и слонов
    int castlePerm; // 0 0 0 0 

    S_UNDO history[MAX_GAME_MOVES];
    //piece list

    int pList[13][10];

} S_Board;

extern int SQ120TO64[BRD_SQ_NUM];
extern int SQ64TO120[64];
extern const int BitTable[64];
extern U64 SetMask[64];
extern U64 ClearMask[64];

extern U64 PieceKeys[13][120];
extern U64 SideKey;
extern U64 CastleKeys[16];
//Functions
//init.c
extern void Allinit(void);

//bitboad.c
extern void PrintBoard(U64 bb);
extern int count_bit(U64 b);
extern int pop_bit(U64 *bb);

//hashkeys.c
extern U64 GeneratePosKey(const S_Board* pos);

//board.c
extern void ReseatBoard(S_Board * pos);

#endif