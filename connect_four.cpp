#include<iostream>
using namespace std;

class Board
{
public:
int rowPos,colPos;

Board()
{
    string p1,p2,board[6][7]; //board of 6 rows and 7 columns
    
    cout<<"Let's play!"<<endl; //2 players for now (TODO: AI)
    cout<<"Enter player 1 name:"<<endl;
    cin>>p1;
    cout<<"Enter player 2 name:"<<endl;
    cin>>p2;
    
    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            board[rowPos][colPos]="_";
        }
    } //initializes empty board

    display(board[6][7]); //initially the board is empty
    //updater(p1,p2,board);
}


void updater(string p1,string p2,string board) //the main logic lies here
{
    int colPosX=playerChoice(p1);
    //board[row][colPos1];
    
    
}


int playerChoice(string player)
{
    int colPos;
    cout<<"It's your turn, "<<player<<":"<<endl;
    cin>>colPos;
    return colPos-1; //because array position counting starts from 0
} 



void display(string board)
{

    cout<<"Current board looks like this:"<<endl;

    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            cout<<board[rowPos][colPos];
        }
        cout<<endl;
    }
    
    cout<<"1 2 3 4 5 6 7"<<endl; //positional indicators for each column
}

};


int main()
{
    cout<<"Welcome to CONNECT FOUR by Urmil Shroff!"<<endl<<endl;
    Board obj;
}