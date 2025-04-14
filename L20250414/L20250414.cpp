#include<iostream>
#include <windows.h>
#include<conio.h>
#define SIZEOFMAP 10
using namespace std;


struct PlayerState
{
    int xpos;
    int ypos;
    char Playerchar;
    int GETNum;
};

void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Render(PlayerState *ps,char (*arr)[SIZEOFMAP], bool *IsRunning)
{
    
    system("cls");


    for (int i = 0; i < SIZEOFMAP; i++)
    {
        for (int j = 0; j < SIZEOFMAP; j++)
        {
            cout << arr[i][j];
        }
        
        cout << endl;
    }

    gotoxy(ps->xpos, ps->ypos);
    cout << ps->Playerchar;

    if (!(*IsRunning))
    {
        cout << endl <<"You Won";
    }
}

void Input(PlayerState * NewPlayer)
{
    NewPlayer->GETNum = _getch();
}


void Tick(PlayerState* NewPlayer, char arr[][SIZEOFMAP],bool *ISRunning)
{
    switch (NewPlayer->GETNum)
    {
    case 72:
        NewPlayer->ypos -= 1;
        if (arr[NewPlayer->xpos][NewPlayer->ypos] == '*')
        {
            NewPlayer->ypos += 1;
        }
        break;
    case 75:
        NewPlayer->xpos -= 1;
        if (arr[NewPlayer->xpos][NewPlayer->ypos] == '*')
        {
            NewPlayer->xpos += 1;
        }
        break;
    case 77:
        NewPlayer->xpos += 1;
        if (arr[NewPlayer->xpos][NewPlayer->ypos] == '*')
        {
            NewPlayer->xpos -= 1;
        }
        break;
    case 80:
        NewPlayer->ypos += 1;
        if (arr[NewPlayer->xpos][NewPlayer->ypos] == '*')
        {
            NewPlayer->ypos -= 1;
        }
        break;
    }

    if (arr[NewPlayer->xpos][NewPlayer->ypos] == 'G')
    {
        *ISRunning = FALSE;
    }

}


void ClearMap(char arry[][SIZEOFMAP])
{
    for (int i = 0; i < SIZEOFMAP; i++)
    {
        for (int j = 0; j < SIZEOFMAP; j++)
        {
            if (i == 0 || i == SIZEOFMAP - 1)
            {
                arry[i][j] = '*';
            }
            else if (j == 0 || j == SIZEOFMAP - 1)
            {
                arry[i][j] = '*';
            }
            else if(i ==8 && j == 8)
            {
                arry[i][j] = 'G';
            }
            else
            {
                arry[i][j] = ' ';
            }
        }
    }
}

int main()
{
    char arry[SIZEOFMAP][SIZEOFMAP] = {};
    ClearMap(arry);


    PlayerState * NewPlayer = new PlayerState;
    NewPlayer->xpos = 5;
    NewPlayer->ypos = 5;
    NewPlayer->Playerchar = 'k';

    bool IsRunning = true;

    Render(NewPlayer, arry, &IsRunning);

    while (IsRunning)
    {
        Input(NewPlayer);
        Tick( NewPlayer, arry,&IsRunning);
        Render(NewPlayer,arry, &IsRunning);
    }



    delete NewPlayer;
    NewPlayer = nullptr;

    return 0;

}