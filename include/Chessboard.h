#include<vector>
#include<windows.h>
#include<vector>
using namespace std;
enum chess{nochess,blackchess,whitechess};
class Chessboard
{
    public:
        Chessboard();
        void putchess(int a,int x,int y);///
        void board_output();
        void SetColor(int f,int b);
        void connection(int a,int x,int y);///���s
        void violation(int a,int x,int y);///�H�W
        void gameset();///connction��overtime��violation�����éw��Ĺ
        void handcounting();///�p����
        int get_handcount();///
        bool get_gamesetting();
        void gameset_output();///�i�D���a��Ĺ����X
        bool cover_judge(int x,int y);
    private:
        vector< vector<int> >board;
        int time;
        int handcount;
        bool connect;
        bool violate;
        bool gamesetting;
        int violatetype;
};

