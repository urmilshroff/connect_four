#include<iostream>
using namespace std;

class Board
{
public:
int rowPos,colPos;

Board()
{
    string board[6][7]; //board of 6 rows and 7 columns
    string player[2]; //array of 2 players
    
    cout<<"Let's play!"<<endl; //2 players for now (TODO: AI)
    cout<<"Enter Player 1 name:"<<endl;
    cin>>player[0]; //player 1
    cout<<"Enter Player 2 name:"<<endl;
    cin>>player[1]; //player 2
    
    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            board[rowPos][colPos]="_ ";
        }
    } //initializes empty board

    display(board);
    updater(board,player);
}






void updater(string board[6][7],string player[2]) //the main logic lies here
{
    int i,p,colPos[2];
    rowPos=0
    p=0
    
    for(i=0;i<6;i++)
    {
        colPos[p]=playerChoice(player[p],p); //player's choice goes into board
        
        if(p==0)
        {
            board[rowPos+i][colPos[p]]="X";
        }
        else if(p==1)
        {
            board[rowPos+i][colPos[p]]="O";
        }
        display(board);
    }
    
}






int playerChoice(string player[2],int playerId)
{
    int colPos;
    cout<<"It's your turn, "<<player[playerId]<<":"<<endl;
    cin>>colPos;
    return colPos-1; //because array position counting starts from 0
} 


void display(string board[6][7])
{

    cout<<"\nCurrent board looks like this:"<<endl;

    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            cout<<board[rowPos][colPos];
        }
        cout<<endl;
    }
    
    cout<<"1 2 3 4 5 6 7"<<endl<<endl; //positional indicators for each column
}

};


int main()
{
    cout<<"Welcome to CONNECT FOUR by Urmil Shroff!"<<endl<<endl;
    Board obj;
}