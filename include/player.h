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
        void bchess_input(chesscoordinate x);///�´Ѥl�y�п�J
        void wchess_input(chesscoordinate x);///�մѤl�y�п�J
        chesscoordinate blackgetback();///�´ѳ̷s�@��y��
        chesscoordinate whitegetback();///�մѳ̷s�@��y��
    private:
        vector<chesscoordinate>blackchesscoordinate;
        vector<chesscoordinate>whitechesscoordinate;
};

