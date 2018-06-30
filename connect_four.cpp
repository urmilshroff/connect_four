#include<iostream>
using namespace std;

class Board
{
public:

int i,j,p,colPos;
string board[6][7],playerName[2]; //board of 6 rows and 7 columns

Board()
{
    cout<<"\nEnter Player 1 name:"<<endl;
    cin>>playerName[0]; //player 1
    cout<<"\nEnter Player 2 name:"<<endl;
    cin>>playerName[1]; //player 2
    
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            board[i][j]="_ ";
        }
    } //initializes empty board

    display(board);
    updater(board,playerName,0);
}


void updater(string board[6][7],string playerName[2],int p) //updates board with new moves
{
    int rowPos[7],winner;
    
    while(true) //when somebody wins, this loop should break out
    {
        colPos=playerChoice(playerName,p); //player's choice goes into board
        
        if(isFull(board,playerName,rowPos,colPos,p)==true)
        {
            continue; //skips everything below and comes back to loop with same player id
        }
        
        if(p==0) //if Player 1 then use "X"
        {
            board[rowPos[colPos]][colPos]="X ";
            
            if(someWon(board,rowPos[colPos],colPos,playerName,p)==true)
            {
                break;
            }
            else
            {
                p=1;
            }
        }
        
        else if(p==1) //if Player 2 then use "O"
        {    
            board[rowPos[colPos]][colPos]="O ";
            
            if(someWon(board,rowPos[colPos],colPos,playerName,p)==true)
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

    cout<<"Congratulations, "<<playerName[p]<<"! You won!"<<endl;
}


void display(string board[6][7]) //simply displays current state of board
{
    cout<<"\nCurrent board looks like this:"<<endl;

    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    
    cout<<"1 2 3 4 5 6 7"<<endl; //positional indicators for each column
}


bool someWon(string board[6][7],int rowPos,int colPos,string playerName[2],int p) //returns true if there is a four in a row
{
    if(verticalChecker(board,rowPos[colPos],colPos,playerName,p)==true)
    {
        return true;
    }

    else if(horizontalChecker(board,rowPos[colPos],colPos,playerName,p)==true)
    {
        return true;
    }

    else if(diagonalChecker(board,rowPos[colPos],colPos,playerName,p)==true)
    {
        return true;
    }

    else
    {
        return false;
    }
}


bool verticalChecker(string board[6][7],string rowPos,int colPos,string playerName[2],int p)
{
    return false;
}


bool horizontalChecker(string board[6][7],string rowPos,int colPos,string playerName[2],int p)
{
    int rowCount=1;

    if(board[rowPos][colPos]==board[rowPos][colPos+1]) //going right
    {
        rowCount++;
        if(board[rowPos][colPos]==board[rowPos][colPos+2])
        {
            rowCount++;
            if(board[rowPos][colPos]==board[rowPos][colPos+3])
            {
                rowCount++;
            }
        }
    }

    if(board[rowPos][colPos]==board[rowPos][colPos-1]) //going left
    {
        rowCount++;
        if(board[rowPos][colPos]==board[rowPos][colPos-2])
        {
            rowCount++;
            if(board[rowPos][colPos]==board[rowPos][colPos-3])
            {
                rowCount++;
            }
        }
    }

    if(rowCount>=4)
    {
        return true;
    }

    else
    {
        return false;
    }
}


bool diagonalChecker(string board[6][7],string rowPos,int colPos,string playerName[2],int p)
{
    return false;
}


bool isFull(string board[6][7],string playerName[2],int rowPos[7],int colPos,int p)
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
    cout<<"\nIt's your turn, "<<playerName[p]<<"! Which column do you want to play in?"<<endl;
    
    while(true)
    {    
        while(true)
        {
            cin>>colPos;
            
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"\nSorry, "<<playerName[p]<<" - please enter a valid column number between 1 & 7!"<<endl;
            }
            
            else
            {
                break;
            }
        }
        
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
    cout<<"\nWelcome to CONNECT FOUR by Urmil Shroff!"<<endl;
    Board obj;
    return 0;
}