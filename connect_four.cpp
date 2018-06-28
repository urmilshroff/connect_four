#include<iostream>
using namespace std;

class Board
{
public:

Board()
{
    int rowPos,colPos,p;
    string board[6][7]; //board of 6 rows and 7 columns
    string playerName[2];
    
    cout<<"Let's play!"<<endl; //2 players for now (TODO: AI)
    cout<<"Enter Player 1 name:"<<endl;
    cin>>playerName[0]; //player 1
    cout<<"Enter Player 2 name:"<<endl;
    cin>>playerName[1]; //player 2
    
    for(rowPos=0;rowPos<6;rowPos++)
    {
        for(colPos=0;colPos<7;colPos++)
        {
            board[rowPos][colPos]="_ ";
        }
    } //initializes empty board

    display(board);
    updater(board,playerName,0);
}


void updater(string board[6][7],string playerName[2],int p) //updates board with new moves
{
    int i,rowPos[7],colPos,winner;
    bool someWon=false; //by default it is false - nobody has won yet
    bool isFull=false;
    
    while(true) //when somebody wins, loop should break out
    {
        colPos=playerChoice(playerName,p); //player's choice goes into board
        isFull=isFullChecker(board,playerName,rowPos,colPos,p); //checks if the column the user is trying to play in is full or not
        
        if(isFull==true)
        {
            continue; //skips everything below and comes back to loop with same player id
        }
        
        if(p==0) //if Player 1 then use X
        {
            board[rowPos[colPos]][colPos]="X ";
            someWon=winnerChecker(board);
            
            if(someWon==true)
            {
                break;
            }
            else
            {
                p=1;
            }
        }
        
        else if(p==1) //if Player 2 then use O
        {    
            board[rowPos[colPos]][colPos]="O ";
            someWon=winnerChecker(board);
            
            if(someWon==true)
            {
                break;
            }
            else
            {
                p=0;
            }
        }
        
        display(board);
    }
}


void display(string board[6][7]) //simply displays current state of board
{
    int rowPos,colPos;
    
    cout<<"\nCurrent board looks like this:"<<endl;

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


bool winnerChecker(string board[6][7]) //the main logic lies here
{
    //TODO
    return false;
}


bool isFullChecker(string board[6][7],string playerName[2],int rowPos[7],int colPos,int p)
{
    if(board[5][colPos]=="_ ") //if no insert in that column yet
    {
        rowPos[colPos]=5;
    }
    
    while(board[rowPos[colPos]][colPos]!="_ ") //if someone has already played in that position
    {
        if(rowPos[colPos]==0)
        {
            cout<<"\nSorry, "<<playerName[p]<<" - it looks like this row is already full!"<<endl;
            return true;
            break;
        }
        rowPos[colPos]--; //keeps going up up up!
    }
    return false;
}


int playerChoice(string playerName[2],int p)
{
    int colPos;
    
    cout<<"\nIt's your turn, "<<playerName[p]<<"! Which column do you want to play in?"<<endl;
    
    while(true) //infinite loop
    {
        cin>>colPos;
        
        if(colPos<1 || colPos>7)
        {
            cout<<"\nSorry, "<<playerName[p]<<" - please enter a valid column number between 1 & 7!"<<endl;
        }
        else
        {
            break;
        }
    }
    
    return colPos-1; //because array position counting starts from 0

}

};


int main()
{
    cout<<"\nWelcome to CONNECT FOUR by Urmil Shroff!\n"<<endl;
    Board obj;
    return 0;
}