#include<iostream>
using namespace std;

class Board
{
public:
    
int player,rowPos,colPos,rowPos1,colPos1,rowPos0,colPos0,board[6][7]; //board of 6 rows and 7 columns
string p1,p2;

Board()
{
    cout<<"Let's play!"<<endl; //2 players for now (TODO: AI)
    cout<<"Enter player 1 name:"<<endl;
    cin>>p1;
    cout<<"Enter player 2 name:"<<endl;
    cin>>p2;

    display(NULL,NULL,NULL,NULL,true); //initially the board is empty
    updater();
}


int updater()
{
    return 0;
}


int display(int rowPos1,int colPos1,int rowPos0,int colPos0,bool isEmpty)
{
    //cout<<rowPos1<<colPos1<<rowPos0<<colPos0;
    
    cout<<"Current board looks like this:"<<endl;
    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            if (rowPos==rowPos1 && colPos==colPos1 && isEmpty==false)
            {
                cout<<"1 ";
            }
            
            else if(rowPos==rowPos0 && colPos==colPos0 && isEmpty==false)
            {
                cout<<"0 ";
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



int playerChoice(string player)
{
    cout<<"Enter the column you wish to play in, "<<player<<":"<<endl;
    cin>>colPos;
    return colPos;
}    
    

};



int main()
{
    cout<<"Welcome to CONNECT FOUR by Urmil Shroff!"<<endl<<endl;
    Board obj;
}