#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<fstream>

using namespace std;

int random_index();

void textColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class GameFunction{
    public:
        int canMove=123;
        int dontMove=321;
        int win=1;
        int lose=-1;
        int continueLoop=-2;
        int board[4][4];
        int copyBoard[4][4];
        char control;
        int score=0;

        void gotoxy(int x,int y);
        void drawBoard();
        void displayGameWithArandomNumber(int,int);
        void inputControlButton();
        int checkWinOrLose();
        void setZero();
        void fillSpace();
        void plusValue();
        void copy();
        int compareTwoBoardGame();
        int findTwoValueIsSame();
        void printfInformationWinOrLose();
        void gamePlay();
};
//function
int random_index()
{
    int index=0;
    do{
        index=rand()%10;
    }while(index>3);

    return index; //get random number about: 0 to 3
}

void GameFunction::inputControlButton(){
    control=getch();
    if(control=='r' || control=='R'){
        score=0;
        setZero();
    }
    if(control=='h' || control=='H'){
            gotoxy(50,17);
        cout<<endl<<"w:move up"<<endl<<"s:move down"<<endl<<"a:move left"<<endl<<"d:move right"<<endl;
    }
    if(control=='W') control='w';
    else if(control=='S') control='s';
    else if(control=='A') control='a';
    else if(control=='D') control='d';
    else if(control=='Q') control='q';
    else if(control=='Y') control='y';
}

void GameFunction::setZero(){
    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
           board[i][j]=0;
}

int GameFunction::checkWinOrLose(){
    int countNumberIsNotZero=0;

    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++){
            if(board[i][j]==2048)   return win;
            else if(board[i][j]!=0)  countNumberIsNotZero++;
        }
    if(countNumberIsNotZero==16|| control=='q' || control=='Q') return lose;
    return continueLoop;
}

void GameFunction::displayGameWithArandomNumber(int i,int j){
    while(board[i][j]!=0){
        i=random_index();
        j=random_index();
    }
    int k=random_index();
    if(k<=1) board[i][j]=2;
    else if(k>=2) board[i][j]=4;

    drawBoard();

    gotoxy(49,0);
    textColor(66);
    cout<<"Score : "<<score;

    textColor(14);
    gotoxy(49,6); cout<<"H: help game";
    gotoxy(49,7); cout<<"R: restart game";
    gotoxy(49,8); cout<<"Q: quit game";


    textColor(7);


    int a =0,b=0;
    for(int i = 0; i <= 3;i++){
        for(int j = 0;j <= 3; j++){
            if ( j == 0) a = 2;
            else if ( j == 1) a = 10;
            else if ( j == 2) a = 18;
            else if(j == 3) a = 26;

            if ( i == 0) b = 2;
            else if ( i == 1) b = 6;
            else if ( i == 2) b = 10;
            else if(i == 3) b = 14;

            gotoxy(a,b);
            if(board[i][j] == 2){
                textColor(1);
                cout<<"  2 ";
            }
            else if(board[i][j] == 4) {
                textColor(2);
                cout<<"  4 ";
            } else if(board[i][j] == 8) {
                textColor(3);
                cout<<"  8 ";
            } else if(board[i][j] == 16) {
                textColor(4);
                cout<<" 16 ";
            } else if(board[i][j] == 32) {
                textColor(5);
                cout<<" 32 ";
            } else if(board[i][j] == 64) {
                textColor(6);
                cout<<" 64 ";
            } else if(board[i][j] == 128) {
                textColor(10);
                cout<<" 128";
            } else if(board[i][j] == 256) {
                textColor(11);
                cout<<" 256";
            } else if(board[i][j] == 512) {
                textColor(12);
                cout<<" 512";
            } else if(board[i][j] == 1024) {
                textColor(13);
                cout<<"1024";
            } else if(board[i][j] == 2048) {
                textColor(14);
                cout<<"2048";
            } else {
                textColor(7);
            }
        }
    }

}

void GameFunction::fillSpace(){

        switch(control)
        {
            case 'w':
                for(int i=0;i<4;i++)
                    for(int j=0;j<4;j++){
                        if(board[j][i]==0){
                            for(int k=j+1;k<4;k++)
                                if(board[k][i]!=0){
                                    board[j][i]=board[k][i];
                                    board[k][i]=0;
                                    break;
                                }
                        }
                    }break;

            case 's':
                for(int i=0;i<4;i++)
                    for(int j=3;j>=0;j--){
                        if(board[j][i]==0){
                            for(int k=j-1;k>=0;k--)
                                if(board[k][i]!=0){
                                    board[j][i]=board[k][i];
                                    board[k][i]=0;
                                    break;
                                }
                        }

                    }
                break;
            case 'a':
                for(int i=0;i<4;i++)
                    for(int j=0;j<4;j++){
                        if(board[i][j]==0){
                            for(int k=j+1;k<4;k++)
                                if(board[i][k]!=0){
                                    board[i][j]=board[i][k];
                                    board[i][k]=0;
                                    break;
                                }
                        }

                    }break;


            case 'd':
                for(int i=0;i<4;i++)
                    for(int j=3;j>=0;j--){
                        if(board[i][j]==0){
                            for(int k=j-1;k>=0;k--)
                                if(board[i][k]!=0){
                                    board[i][j]=board[i][k];
                                    board[i][k]=0;
                                    break;
                                }
                        }

                    }break;
        }
}


void GameFunction::plusValue(){
    switch (control) {
        case 'a':
            for(int i=0;i<=3;i++)
                for(int j=0;j<=2;j++){
                    if(board[i][j]==board[i][j+1]){
                        score+=2*board[i][j];
                        board[i][j]*=2;
                        board[i][j+1]=0;
                        fillSpace();
                    }
                }break;

        case 'd':
            for(int i=0;i<=3;i++)
                for(int j=3;j>=1;j--){
                    if(board[i][j]==board[i][j-1]){
                        score+=2*board[i][j];
                        board[i][j]*=2;
                        board[i][j-1]=0;
                        fillSpace();
                    }
                }break;
        case 'w':
            for(int j=0;j<=3;j++)
                for(int i=0;i<=2;i++){
                    if(board[i][j]==board[i+1][j]){
                        score+=2*board[i][j];
                        board[i][j]*=2;
                        board[i+1][j]=0;
                        fillSpace();
                    }
                }break;
        case 's':
            for(int j=0;j<=3;j++)
                for(int i=3;i>=1;i--){
                    if(board[i][j]==board[i-1][j]){
                        score+=2*board[i][j];
                        board[i][j]*=2;
                        board[i-1][j]=0;
                        fillSpace();
                    }
                }break;
    }
}

void GameFunction::copy(){
    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
            copyBoard[i][j]=board[i][j];
}

int GameFunction::compareTwoBoardGame(){

    for(int i=0;i<=3;i++)
        for(int j=0;j<=3;j++)
            if(board[i][j]!=copyBoard[i][j]) return canMove;
    return dontMove;
}

int GameFunction::findTwoValueIsSame(){
    int same1=0;
    int same2=0;
    for(int i=0;i<=3;i++)
        for(int j=0;j<=2;j++)
            if(board[i][j] == board[i][j+1]){
                same1=1;
                break;
            }
    for(int j=0;j<=3;j++)
        for(int i=0;i<=2;i++)
            if(board[i][j]==board[i+1][j]){
                same2=1;
                break;
            }
    return same1+same2;
}

void GameFunction::printfInformationWinOrLose(){
    if(checkWinOrLose()==lose){
        gotoxy(50,2);
        textColor(4);
        cout<<"YOU LOSE";
        gotoxy(45,3);   cout<<"------------------";
    }
    else if(checkWinOrLose()==win){
        gotoxy(50,2);
        textColor(2);
        cout<<"YOU WIN";
        gotoxy(45,3);   cout<<"------------------";
    }
    else if(control=='q'){
        gotoxy(50,2);
        textColor(4);
        cout<<"YOU LOSE";
        gotoxy(45,3);   cout<<"------------------";

    }
    textColor(7);
    gotoxy(44,4);
    cout<<"Press Y to play again";

}

void GameFunction::gamePlay(){
    do{
        setZero();
        do{
            system("cls");
            displayGameWithArandomNumber(random_index(), random_index());

            copy();
            do{
                inputControlButton();
                fillSpace();
                plusValue();
                if(findTwoValueIsSame()==0|| control=='q') break;
            }while(compareTwoBoardGame()==dontMove);

        }while(checkWinOrLose()==continueLoop);
        printfInformationWinOrLose();

        do{
            inputControlButton();
        }while(control!='y');
        score=0;
    }while(control=='y');
}

void GameFunction::gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void clrscr()
{
    CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
    HANDLE  hConsoleOut;
    COORD   Home = { 0, 0 };
    DWORD   dummy;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
    csbiInfo.dwCursorPosition.X = 0;
    csbiInfo.dwCursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void hideCursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void GameFunction::drawBoard()
{
    textColor(64);
    gotoxy(36,0);
    for(int i=0;i<=16;i++)
    {
        for(int j=0;j<=32;j++)
        {
            if(i==0 && j==0)
            {
                gotoxy(j,i);
                cout<<char(-55);
            }
            else if(i==16 && j==0)
            {
                gotoxy(j,i);
                cout<<char(-56);
            }
            else if(i==0 && j==32)
            {
                gotoxy(j,i);
                cout<<char(-69);
            }
            else if(i==16 && j==32)
            {
                gotoxy(j,i);
                cout<<char(-68);
            }
            else if((i==4 || i==8 || i==12) && j==0)
            {
                gotoxy(j,i);
                cout<<char(-52);
            }
            else if((i==4 || i==8 || i==12) && j==32)
            {
                gotoxy(j,i);
                cout<<char(-71);
            }
            else if(i==0 && (j==8||j==16||j==24))
            {
                gotoxy(j,i);
                cout<<char(-53);
            }
            else if(i==16 && (j==8 || j==16 || j==24))
            {
                gotoxy(j,i);
                cout<<char(-54);
            }
            else if((i==4 || i==8 || i==12) && ( j==8 || j==16 || j==24))
            {
                gotoxy(j,i);
                cout<<char(-50);
            }
            else if(i==0 || i==4 || i==8 || i==12 || i==16)
            {
                gotoxy(j,i);
                cout<<char(-51);
            }
            else if(j==0 || j==8 || j==16 || j==24 || j==32)
            {
                gotoxy(j,i);
                cout<<char(-70);
            }
        }
    }
    textColor(7);
}

int main( ){

    srand(time(0));
    GameFunction exe;
    exe.gamePlay();
    system("pause");
    return 0;
}
