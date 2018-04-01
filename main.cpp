
#include <iostream>
#include <cstring>
#include <time.h>
#include<cstdlib>
#include<conio.h>
#include<windows.h>

using namespace std;
int random_index();
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

//main function
int main( ){

    srand(time(0));
    GameFunction exe;
    exe.gamePlay();
    system("pause");
    return 0;
}


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
    cout<<endl<<"\t\t\t------ score:"<<score<<" ------"<<endl;
    cout<<endl<<"\t\t\t--------------------- \t\tR: Restart game."<<endl;
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(j==0) cout<<"\t\t\t|";
            if(board[i][j]==2 || board[i][j]==4 || board[i][j]==8) cout<<"  "<<board[i][j]<<" |";
            else if(board[i][j]==16 || board[i][j]==32 || board[i][j]==64)
                    cout<<" "<<board[i][j]<<" |";
            else if(board[i][j]==128 || board[i][j]==256 || board[i][j]==512 )
                    cout<<" "<<board[i][j]<<"|";
            else if(board[i][j]==1024 || board[i][j]==2048  )
                    cout<<board[i][j]<<"|";
            else if(board[i][j]==0) cout<<"    |";
        }
        if(i==0) cout<<endl<<"\t\t\t--------------------- \t\tH: Help game."<<endl;
        else if(i==1) cout<<endl<<"\t\t\t--------------------- \t\tQ: Quit game."<<endl;
        else    cout<<endl<<"\t\t\t---------------------"<<endl;
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
                        score+=board[i][j];
                        board[i][j]*=2;
                        board[i][j+1]=0;
                        fillSpace();
                    }
                }break;

        case 'd':
            for(int i=0;i<=3;i++)
                for(int j=3;j>=1;j--){
                    if(board[i][j]==board[i][j-1]){
                        score+=board[i][j];
                        board[i][j]*=2;
                        board[i][j-1]=0;
                        fillSpace();
                    }
                }break;
        case 'w':
            for(int j=0;j<=3;j++)
                for(int i=0;i<=2;i++){
                    if(board[i][j]==board[i+1][j]){
                        score+=board[i][j];
                        board[i][j]*=2;
                        board[i+1][j]=0;
                        fillSpace();
                    }
                }break;
        case 's':
            for(int j=0;j<=3;j++)
                for(int i=3;i>=1;i--){
                    if(board[i][j]==board[i-1][j]){
                        score+=board[i][j];
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
    if(checkWinOrLose()==lose) cout<<endl<<"\t\t\t"<<"      You Lose    "<<endl;
    else if(checkWinOrLose()==win) cout<<endl<<"\t\t\t      You Win     "<<endl;
    else if(control=='q') cout<<endl<<"\t\t\t"<<"      You Lose    "<<endl;
    cout<<endl<<"\t\t\tPress Y to play gain "<<endl;

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
