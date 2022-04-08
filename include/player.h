#include<vector>
using namespace std;
struct chesscoordinate
{
    int xcoordinate;
	int ycoordinate;
};
class player
{
    public:
        void bchess_input(chesscoordinate x);///黑棋子座標輸入
        void wchess_input(chesscoordinate x);///白棋子座標輸入
        chesscoordinate blackgetback();///黑棋最新一手座標
        chesscoordinate whitegetback();///白棋最新一手座標
    private:
        vector<chesscoordinate>blackchesscoordinate;
        vector<chesscoordinate>whitechesscoordinate;
};

