#include<iostream>
using namespace std;

class Board
{
public:
    
int player,rowPos,colPos,rowPosX,colPosX,rowPosO,colPosO,board[6][7]; //board of 6 rows and 7 columns
bool isFull;

Board()
{
    cout<<"Let's play!"<<endl; //2 players for now
    display(NULL,NULL,NULL,NULL);
    updater();
}


int updater()
{
    return 0;
}


int display(int rowPosX,int colPosX,int rowPosO,int colPosO)
{
    cout<<"Current board looks like this:"<<endl;
    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            if (rowPos==rowPosX && colPos==colPosX)
            {
                cout<<"X ";
            }
            
            else if(rowPos==rowPosO && colPos==colPosO)
            {
                cout<<"O ";
            }
            
            else
            {
                cout<<"_ ";
            }
        }
        cout<<endl;
    }
    return 0;
}



int playerChoice(int player)
{
    cout<<"Player"<<player<<": Enter the column you wish to play in:"<<endl;
    cin>>colPos;
    return colPos;
}    
    

};



int main()
{
    cout<<"Welcome to CONNECT FOUR by Urmil Shroff!"<<endl<<endl;
    Board obj;
}