#include <iostream>
#include <Chessboard.h>
#include <player.h>
#include <windows.h>
#include <Windows.h>
#include <cstdio>
using namespace std;

int main()
{
    while(1)
    {
        Chessboard mainboard;
        player mainplayer;
        mainboard.SetColor(13,0);
            cout<<"��������������������������"<<endl
                <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
                <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
                <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
                <<"���@���H���l�ѹ�٨t��  ��"<<endl
                <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
                <<"���@�@�@�@      �@�@�@�@��"<<endl
                <<"���@�@              �@  ��"<<endl
                <<"���@�@�@�@      �@�@�@�@��"<<endl
                <<"���@�@�@�@      �@�@�@�@��"<<endl
                <<"���@�@�@�@      �@�@�@�@��"<<endl
                <<"���@�@�@�@      �@�@�@�@��"<<endl
                <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
                <<"���@                 �@ ��"<<endl
                <<"��������������������������"<<endl;
                system("pause");
                system("cls");
        mainboard.board_output();
        chesscoordinate pre_bc;
        chesscoordinate pre_wc;
        while(1)
        {
            mainboard.SetColor(7,0);
            bool s2=true;
            cout<<"�¤�п�J�y��(�������)"<<endl;
            chesscoordinate bc;/// declare blackchess***********�ڧ��L�H�U����J�覡
jump:
            while(1)
            {
                mainboard.SetColor(7,0);
                if(mainboard.get_handcount()==0)
                {
                    cout<<"�դ襼���l"<<endl;
                }
                else
                {
                    pre_wc=mainplayer.whitegetback();
                    cout<<"�դl�e�@�⬰:"<<pre_wc.xcoordinate+1<<","<<(char)(pre_wc.ycoordinate+65)<<endl;
                }
                float a=0;
                char b;
                float b_num=0;
                cin>>a;
                cin>>b;
                if((a-int(a)!=0))
                {
                    cout<<"��J�榡���~�A�п�J�ѽL�W���T�y��!"<<endl;
                    continue;
                }

                else if(int(b)<65 || int(b)>79)
                {
                    cout<<"��J�榡���~�A�п�J�ѽL�W���T�y��!"<<endl;
                    continue;
                }
                b_num = int(b) - 64;
                bc.xcoordinate=a;
                bc.ycoordinate=b_num;
                if(a-bc.xcoordinate!=0||b_num-bc.ycoordinate!=0)
                {
                    cout<<"�y�жW�X�ѽL�A�п�J�ѽL�W���T�y��!"<<endl;
                }
                else if(bc.xcoordinate>15 || bc.ycoordinate>15 || bc.xcoordinate<=0 || bc.ycoordinate<=0)
                {
                    cout<<"�y�жW�X�ѽL�A�п�J�ѽL�W���T�y��!"<<endl;
                }
                else if(mainboard.cover_judge(bc.xcoordinate-1,bc.ycoordinate-1)==true)
                {
                    cout<<"�ѽL�y�Фw���X�l�A�п�J�ѽL�W�Ѿl�y��!"<<endl;
                }
                else
                {
                    break;
                }
            }
            mainboard.handcounting();
            bc.xcoordinate--;
            bc.ycoordinate--;
            mainplayer.bchess_input(bc);/// put blackchess to vector
            mainboard.putchess(blackchess,bc.xcoordinate,bc.ycoordinate);
            system("cls");
            mainboard.board_output();
            mainboard.SetColor(7,0);
            mainboard.violation(blackchess,bc.xcoordinate,bc.ycoordinate);///  judce violation
            mainboard.connection(blackchess,bc.xcoordinate,bc.ycoordinate);/// judce violation
            mainboard.gameset();
            if(mainboard.get_gamesetting()==true)
            {
                mainboard.gameset_output();
                break;
            }
            if(mainboard.get_handcount()==169)
            {
                cout<<"����"<<endl;
                break;
            }
            cout<<"�դ�п�J�y��(�������)"<<endl;
            chesscoordinate wc;/// declare whitechess
next:
            while(1)
            {
                pre_bc=mainplayer.blackgetback();
                mainboard.SetColor(7,0);
                cout<<"�¤l�e�@�⬰:"<<pre_bc.xcoordinate+1<<","<<(char)(pre_bc.ycoordinate+65)<<endl;
                float a=0;
                char b;
                float b_num=0;
                cin>>a;
                cin>>b;
                if(a-int(a)!=0)
                {
                    cout<<"��J�榡���~�A�п�J�ѽL�W���T�y��!"<<endl;
                    continue;
                }

                else if(int(b)<65 || int(b)>79)
                {
                    cout<<"��J�榡���~�A�п�J�ѽL�W���T�y��!"<<endl;
                    continue;
                }
                b_num = int(b) - 64;
                wc.xcoordinate=a;
                wc.ycoordinate=b_num;
                if(a-wc.xcoordinate!=0||b_num-wc.ycoordinate!=0)
                {
                    cout<<"�y�жW�X�ѽL�A�п�J�ѽL�W���T�y��!"<<endl;
                }
                else if(wc.xcoordinate>15 || wc.ycoordinate>15 || wc.xcoordinate<=0 || wc.ycoordinate<=0)
                {
                    cout<<"�y�жW�X�ѽL�A�п�J�ѽL�W���T�y��!"<<endl;
                }
                else if(mainboard.cover_judge(wc.xcoordinate-1,wc.ycoordinate-1)==true)
                {
                    cout<<"�ѽL�y�Фw���X�l�A�п�J�ѽL�W�Ѿl�y��!"<<endl;
                }
                else
                {
                    break;
                }
            }
            if(s2==true)
            {
                mainboard.handcounting();
                wc.xcoordinate--;
                wc.ycoordinate--;
                mainplayer.wchess_input(wc);
                mainboard.putchess(whitechess,wc.xcoordinate,wc.ycoordinate);
                system("cls");
                mainboard.board_output();
                mainboard.SetColor(7,0);///***************
                mainboard.violation(whitechess,wc.xcoordinate,wc.ycoordinate);
                mainboard.connection(whitechess,wc.xcoordinate,wc.ycoordinate);
                mainboard.gameset();
                if(mainboard.get_gamesetting()==true)
                {
                    mainboard.gameset_output();
                    break;
                }
            }
        }
        system("pause");
        system("cls");
        cout<<"��������������������������"<<endl
            <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
            <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
            <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
            <<"���@                    ��"<<endl
            <<"���@�@DO YOU WANT TO�@�@��"<<endl
            <<"���@�@PLAY AGAIN????    ��"<<endl
            <<"���@�@              �@  ��"<<endl
            <<"���@�@    (Y/N)         ��"<<endl
            <<"���@�@�@�@      �@�@�@�@��"<<endl
            <<"���@�@�@�@      �@�@�@�@��"<<endl
            <<"���@�@�@�@      �@�@�@�@��"<<endl
            <<"���@�@�@�@�@�@�@�@�@�@�@��"<<endl
            <<"���@                 �@ ��"<<endl
            <<"��������������������������"<<endl;
        char ans;
        cin>>ans;
        if(ans=='Y'||ans=='y')
        {
            system("cls");
            continue;
        }
        else
        {
            break;
        }
    }
    system("pause");
    return 0;
}
