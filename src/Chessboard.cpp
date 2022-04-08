#include <Chessboard.h>
#include<iostream>
using namespace std;
Chessboard::Chessboard()
{
    for(int i=0;i<15;i++)
    {
        vector<int>t;
        for(int j=0;j<15;j++)
        {
            t.push_back(nochess);
        }
        board.push_back(t);
    }
    time=30;
    handcount=0;
    connect=false;
    violate=false;
    violatetype=0;
}

void Chessboard::putchess(int a,int x, int y)
{
    if(a==blackchess)
    {
        board[x][y]=blackchess;
    }
    if(a==whitechess)
    {
        board[x][y]=whitechess;
    }
}
void Chessboard::board_output()
{
    for(int x=0;x<15;x++)
    {
        SetColor(0,6);
        if(x==0)
        {
            UINT cp = GetConsoleOutputCP();
            SetConsoleOutputCP(CP_UTF8);
            SetColor(0,6);
            cout<<"   "<<"A "<<"B "<<"C "<<"D "<<"E "<<"F "<<"G "<<"H "<<"I "<<"J "<<"K "<<"L "<<"M "<<"N "<<"O "<<endl;
            SetConsoleOutputCP(cp);

        }
        for(int y=0;y<15;y++)
        {
            if(y==0)
            {
                cout<<x+1;
                if(x+1<10)
                    cout<<" ";
            }
            if(board[x][y]==nochess)
            {
                if(x==0&&y==0)
                {
                    cout<<"�z�w";
                }
                else if(x==0&&y==14)
                {
                    cout<<"�{  ";
                }
                else if(x==0)
                {
                    cout<<"�s�w";
                }
                else if(x==14&&y==0)
                {
                    cout<<"�|�w";
                }
                else if(x==14&&y==14)
                {
                    cout<<"�}  ";
                }
                else if(x==14)
                {
                    cout<<"�r�w";
                }
                else if(y==0)
                {
                    cout<<"�u�w";
                }
                else if(y==14&&x==1)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"�s�M";*/
                }
                else if(y==14&&x==2)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"����";*/
                }
                else if(y==14&&x==3)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"��L";*/
                }
                else if(y==14&&x==4)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"�ѤH";*/
                }
                else if(y==14&&x==5)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"����";*/
                }
                else if(y==14&&x==7)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"����";*/
                }
                else if(y==14&&x==8)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"�W�D";*/
                }
                else if(y==14&&x==9)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"�ˤU";*/
                }
                else if(y==14&&x==10)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"���l";*/
                }
                else if(y==14&&x==11)
                {
                    cout<<"�t  ";
                    /*SetColor(4,6);
                    cout<<"�M�n";*/
                }
                else if(y==14)
                {
                    cout<<"�t  ";
                }
                else
                {
                    cout<<"�q�w";
                }
            }
            else if(board[x][y]==blackchess)
            {
                if(y==14)
                {
                    cout<<"�� ";
                }
                else
                {
                    cout<<"��";
                }
            }
            else if(board[x][y]==whitechess)
            {
                SetColor(7,6);
                if(y==14)
                {
                    cout<<"�� ";
                }
                else
                {
                    cout<<"��";
                }
            }
            SetColor(0,6);
        }
        //SetColor(0,6);
        cout<<endl;
    }
    //SetColor(0,6);
    SetColor(4,6);
    cout<<"  �Q�U�L�H�@���� �Ťs�Q�l���ѽL  "<<endl;
    cout<<"  ���P�󦳯��P�� �d�j��Ĺ�U����  "<<endl;
}
void Chessboard::SetColor(int f=7,int b=0)
{
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

void Chessboard::connection(int a,int x,int y)///���s
{
    int i,j;
    int Count[4]={0};///�p��X�s

    ///�a�V
    for (int j=y;j<15;j++)///�a�V���e��
    {
        if(board[x][j]==a)
        {
            Count[0]++;
        }
        else break;///�X�l�s��~���
    }
    for (int j=y-1;j>=0;j--)///�a�V�����
    {
        if(board[x][j]==a)
        {
            Count[0]++;
        }
        else break;///�X�l�s��~���
    }
    ///��V
    for (int i=x;i<15;i++)///��V���e��
    {
        if(board[i][y]==a)
            {
                Count[1]++;
            }
        else break;///�X�l�s��~���
    }
    for (int i=x-1;i>=0;i--)///��V�����
    {
        if(board[i][y]==a)
        {
            Count[1]++;
        }
        else break;///�X�l�s��~���
    }
    ///�ץ�
    for (i=x+1,j=y+1;i<15&&j<15;i++,j++)///�ץ����e��
    {
        if(board[i][j]==a)
        {
            Count[2]++;
        }
        else break;///�X�l�s��~���
    }
    for (i=x,j=y;i>=0&&j>=0;i--,j--)///�ץ������
    {
        if(board[i][j]==a)
        {
            Count[2]++;
        }
        else break;///�X�l�s��~���
    }
    ///�ץk
    for (i=x,j=y;i>=0&&j<15;i--,j++)///�ץk�����
    {
        if(board[i][j]==a)
        {
            Count[3]++;
        }
        else break;///�X�l�s��~���
    }
    for (i=x+1,j=y-1;i<15&&j>=0;i++,j--)///�ץk�����
    {
        if(board[i][j]==a)
        {
            Count[3]++;
        }
        else break;///�X�l�s��~���
    }
    if(Count[0]==5||Count[1]==5||Count[2]==5||Count[3]==5)
    {
        connect=true;
    }
    else
    {
        connect=false;
    }
}

void Chessboard::violation(int a,int x,int y)
{
    ///�����T
    if(board[x][y]==blackchess)
    {
        int count1=0;
        int i,j;
        bool A=true;
        bool B=true;
        bool half=false;
        bool hole= false;
        int Count[4]={0};///�p��X�s
        ///�a�V
        for (int j=y;j<15;j++)///�a�V���e��
        {
            if(board[x][j]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[0]++;
            }
            if(board[x][j]!=a)
            {
                if(board[x][j]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        A=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T

            }
        }
        half=false;
        for (int j=y-1;j>=0;j--)///�a�V�����
        {
            if(board[x][j]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[0]++;
            }
            if(board[x][j]!=a)
            {
                if(board[x][j]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        B=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        if(Count[0]>=3)///�a�V�����T�s
        {
            if(A==false&&B==false)
            {
                count1++;
            }
        }
        ///��V
        A=true;
        B=true;
        hole= false;
        for (int i=x;i<15;i++)///��V���e��
        {
            if(board[i][y]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[1]++;
            }
            if(board[i][y]!=a)
            {
                if(board[i][y]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        A=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        for (int i=x-1;i>=0;i--)///��V�����
        {
            if(board[i][y]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[1]++;
            }
            if(board[i][y]!=a)
            {
                if(board[i][y]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        B=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        if(Count[1]>=3)///��V�����T�s
        {
            if(A==false&&B==false)
            {
                count1++;
            }
        }
        ///�ץ�
        A=true;
        B=true;
        hole= false;
        for (i=x+1,j=y+1;i<15&&j<15;i++,j++)///�ץ����e��
        {
            if(board[i][j]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[2]++;
            }
            if(board[i][j]!=a)
            {
                if(board[i][j]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        A=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        for (i=x,j=y;i>=0&&j>=0;i--,j--)///�ץ������
        {
            if(board[i][j]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[2]++;
            }
            if(board[i][j]!=a)
            {
                if(board[i][j]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        B=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        if(Count[2]>=3)///�ץ������T�s
        {
            if(A==false&&B==false)
            {
                count1++;
            }
        }
        ///�ץk
        A=true;
        B=true;
        hole= false;
        for (i=x,j=y;i>=0&&j<15;i--,j++)///�ץk�����
        {
            if(board[i][j]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[3]++;
            }
            if(board[i][j]!=a)
            {
                if(board[i][j]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        A=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        for (i=x+1,j=y-1;i<15&&j>=0;i++,j--)///�ץk�����
        {
            if(board[i][j]==a)
            {
                if(half==true)///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                {
                    hole=true;///if(board[x][j]==a)�i�H�P�w�Ů檺���k�O���O�¤l
                }
                Count[3]++;
            }
            if(board[i][j]!=a)
            {
                if(board[i][j]==nochess)
                {
                    if(half==false&&hole==false)///�w�g�O�Ů�N���|�i�o��if�P�_
                    {
                        half=true;///���D�O�Ů���L�k�P�_�O���O�Ŭ},�ҥH�n�Ҽ{�Ů檺���k�O���O�¤l
                    }
                    else
                    {
                        B=false;///�Ҽ{�̥��γ̥k�O���O����
                        break;///�X�l�s��~���
                    }
                }
                else break;///�դl�L�k�Φ����T
            }
        }
        half=false;
        if(Count[3]>=3)///�ץk�����T�s
        {
            if(A==false&&B==false)
            {
                count1++;
            }
        }
        if(count1>=2)
        {
            violate=true;
            violatetype=1;/// double live three
        }
        else;
    }

    ///���s
    int Count[4]={0};///�p��X�s
    int i,j;
    ///�a�V
    if(board[x][y]==blackchess)
    {
        for (int j=y;j<15;j++)///�a�V���e��
        {
            if(board[x][j]==a)
                {
                    Count[0]++;
                }
            else break;///�X�l�s��~���
        }
        for (int j=y-1;j>=0;j--)///�a�V�����
        {
            if(board[x][j]==a)
            {
                Count[0]++;
            }
            else break;///�X�l�s��~���
        }
        ///��V
        for (int i=x;i<15;i++)///��V���e��
        {
            if(board[i][y]==a)
                {
                    Count[1]++;
                }
            else break;///�X�l�s��~���
        }
        for (int i=x-1;i>=0;i--)///��V�����
        {
            if(board[i][y]==a)
            {
                Count[1]++;
            }
            else break;///�X�l�s��~���
        }
        ///�ץ�
        for (i=x+1,j=y+1;i<15&&j<15;i++,j++)///�ץ����e��
        {
            if(board[i][j]==a)
            {
                Count[2]++;
            }
            else break;///�X�l�s��~���
        }
        for (i=x,j=y;i>=0&&j>=0;i--,j--)///�ץ������
        {
            if(board[i][j]==a)
            {
                Count[2]++;
            }
            else break;///�X�l�s��~���
        }
        ///�ץk
        for (i=x,j=y;i>=0&&j<15;i--,j++)///�ץk�����
        {
            if(board[i][j]==a)
            {
                Count[3]++;
            }
            else break;///�X�l�s��~���
        }
        for (i=x+1,j=y-1;i<15&&j>=0;i++,j--)///�ץk�����
        {
            if(board[i][j]==a)
            {
                Count[3]++;
            }
            else break;///�X�l�s��~���
        }
        if(Count[0]>=6||Count[1]>=6||Count[2]>=6||Count[3]>=6)
        {
            violate=true;
            violatetype=2;/// multiple connection
        }
        else;
    }
}

void Chessboard::gameset()///connction��violation�����éw��Ĺ �P�_����: violation->connection
{
    if(violate==false)///not violation
    {
        if(connect==false)/// not connection
        {
            gamesetting=false;
        }
        if(connect==true)///connection
        {
            gamesetting=true;
        }
    }
    if(violate==true)///violation
    {
        gamesetting=true;
    }
}

void Chessboard::handcounting()
{
    handcount++;
}
int Chessboard::get_handcount()
{
    return handcount;
}
bool Chessboard::get_gamesetting()
{
    return gamesetting;
}
void Chessboard::gameset_output()///�i�D���a��Ĺ����X
{
    if(handcount%2==0)/// whitechess turn
    {
        if(connect==true)
        {
            cout<<"���ߥդl���"<<endl;
        }
    }
    if(handcount%2!=0)/// blackchess turn
    {
        if(violate==true)
        {
            if(violatetype==1)
            {
                cout<<"���ߥդl��� , �¤l�����T�H�W"<<endl;
            }
            if(violatetype==2)
            {
                cout<<"���ߥդl��� , �¤l�h�s�H�W"<<endl;
            }
        }
        if(connect==true)
        {
            cout<<"���߶¤l���"<<endl;
        }

    }
}

bool Chessboard::cover_judge(int x,int y)/// judge cover or not
{
    if(board[x][y]!=nochess)
    {
        return true;
    }
    else
    {
        return false;
    }
}

