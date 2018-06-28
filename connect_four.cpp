#include<iostream>
using namespace std;

class Board
{
public:

Board()
{
    int rowPos,colPos;
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
    updater(board,playerName);
}



void updater(string board[6][7],string playerName[2]) //updates board with new moves
{
    int i,p=0,rowPos[7],colPos,winner;
    bool someWon=false; //by default it is false - nobody has won yet
    
    while(true) //when somebody wins, loop breaks out
    {
        colPos=playerChoice(playerName[p]); //player's choice goes into board
        
        if(board[5][colPos]=="_ ") //if no insert in that column yet
        {
            rowPos[colPos]=5;
        }
        
        while(board[rowPos[colPos]][colPos]!="_ ") //if someone has already played in that position
        {
            if(rowPos[colPos]==0)
            {
                cout<<"Whups, this row is now full!"<<endl;
                break;
            }
            rowPos[colPos]--; //keeps going up up up!
        }
        
        if(p==0) //if player 1 then use X
        {
            board[rowPos[colPos]][colPos]="X ";
            someWon=checker(board);
            if(someWon==true)
            {
                break;
            }
            else
            {
                p=1;
            }
        }
        
        else if(p==1) //if player 2 then use O
        {    
            board[rowPos[colPos]][colPos]="O ";
            someWon=checker(board);
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





bool checker(string board[6][7]) //the main logic lies here
{
    return false;
}






int playerChoice(string player) //try renaming parameter to playerName later
{
    int colPos;
    
    cout<<"It's your turn, "<<player<<"! Which column do you want to play in?"<<endl;
    
    while(true) //infinite loop
    {
        cin>>colPos;
        
        if(colPos<1 || colPos>7)
        {
            cout<<"Sorry, please enter a valid column number between 1 & 7!"<<endl;
        }
        else
        {
            break;
        }
    }
    
    return colPos-1; //because array position counting starts from 0
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
    
    cout<<"1 2 3 4 5 6 7"<<endl<<endl; //positional indicators for each column
}

};


int main()
{
    cout<<"Welcome to CONNECT FOUR by Urmil Shroff!"<<endl<<endl;
    Board obj;
}