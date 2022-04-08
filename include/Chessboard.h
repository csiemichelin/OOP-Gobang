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
        void connection(int a,int x,int y);///五連
        void violation(int a,int x,int y);///違規
        void gameset();///connction或overtime或violation結束並定輸贏
        void handcounting();///計算手數
        int get_handcount();///
        bool get_gamesetting();
        void gameset_output();///告訴玩家輸贏的輸出
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

