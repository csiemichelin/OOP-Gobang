#include "player.h"
void player::bchess_input(chesscoordinate x)
{
    blackchesscoordinate.push_back(x);
}
void player::wchess_input(chesscoordinate x)
{
    whitechesscoordinate.push_back(x);
}
chesscoordinate player::blackgetback()
{
    chesscoordinate b;
    b=blackchesscoordinate.back();
    return b;
}
chesscoordinate player::whitegetback()
{
    chesscoordinate w;
    w=whitechesscoordinate.back();
    return w;
}
