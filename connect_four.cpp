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
        
        if(isFull(board,playerName,rowPos,colPos,p))
        {
            continue; //skips everything below and comes back to the loop with same player id
        }
        
        if(p==0) //if Player 1 then use "X"
        {
            board[rowPos[colPos]][colPos]="X ";
            
            if(someWon(board,rowPos,colPos,playerName,p)) //rowPos is an integer array of size 7
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
            
            if(someWon(board,rowPos,colPos,playerName,p))
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

    cout<<"\nCongratulations, "<<playerName[p]<<"! Looks like you won!"<<endl;
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


bool someWon(string board[6][7],int rowPos[7],int colPos,string playerName[2],int p)
{
    if(verticalChecker(board,rowPos,colPos,playerName,p))
    {
        return true; //returns true if there is a four in a row vertically
    }

    else if(horizontalChecker(board,rowPos,colPos,playerName,p))
    {
        return true; //returns true if there is a four in a horizontally
    }

    else if(diagonalChecker(board,rowPos,colPos,playerName,p))
    {
        return true; //returns true if there is a four in a diagonally
    }

    else
    {
        return false; //returns false if there is no a four in a row
    }
}


bool verticalChecker(string board[6][7],int rowPos[7],int colPos,string playerName[2],int p)
{
    int colCount=1;
    string winBoard[6][7];

    if(rowPos[colPos]<=2) //starts checking lower values after it reaches the third row (since we play from below)
    {
        if(p==0)
        {
            winBoard[rowPos[colPos]][colPos]="X "; //TODO: make this into a function
        }
        else if(p==1)
        {
            winBoard[rowPos[colPos]][colPos]="O ";
        }

        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+1][colPos]) //checking down
        {
            colCount++;

            if(p==0)
            {
                winBoard[rowPos[colPos]+1][colPos]="X ";
            }
            else if(p==1)
            {
                winBoard[rowPos[colPos]+1][colPos]="O ";
            }

            if(rowPos[colPos]+1<=3) //WILD PENIS ALERT!!!
            {
                if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+2][colPos])
                {
                    colCount++;

                    if(p==0)
                    {
                        winBoard[rowPos[colPos]+2][colPos]="X ";
                    }
                    else if(p==1)
                    {
                        winBoard[rowPos[colPos]+2][colPos]="O ";
                    }

                    if(rowPos[colPos]+2<=4)
                    {
                        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+3][colPos])
                        {
                            colCount++;

                            if(p==0)
                            {
                                winBoard[rowPos[colPos]+3][colPos]="X ";
                            }

                            else if(p==1)
                            {
                                winBoard[rowPos[colPos]+3][colPos]="O ";
                            }
                        }
                    }
                }
            }
        }
    }

    if(colCount>=4)
    {
        display(winBoard); //still not displaying winBoard correctly
        return true;
    }

    else
    {
        return false;
    }
}


bool horizontalChecker(string board[6][7],int rowPos[7],int colPos,string playerName[2],int p)
{
    int rowCount=1;
    string winBoard[6][7];

    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            winBoard[i][j]="_ ";
        }
    }

    if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos+1]) //going right
    {
        rowCount++;
        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos+2])
        {
            rowCount++;
            if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos+3])
            {
                rowCount++;

                if(p==0)
                {
                    winBoard[rowPos[colPos]][colPos]="X ";
                    winBoard[rowPos[colPos]][colPos+1]="X ";
                    winBoard[rowPos[colPos]][colPos+2]="X ";
                    winBoard[rowPos[colPos]][colPos+3]="X ";
                }

                else if(p==1)
                {
                    winBoard[rowPos[colPos]][colPos]="O ";
                    winBoard[rowPos[colPos]][colPos+1]="O ";
                    winBoard[rowPos[colPos]][colPos+2]="O ";
                    winBoard[rowPos[colPos]][colPos+3]="O ";
                }
            }
        }
    }

    if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos-1]) //going left
    {
        rowCount++;
        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos-2])
        {
            rowCount++;
            if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos-3])
            {
                rowCount++;

                if(p==0)
                {
                    winBoard[rowPos[colPos]][colPos]="X ";
                    winBoard[rowPos[colPos]][colPos-1]="X ";
                    winBoard[rowPos[colPos]][colPos-2]="X ";
                    winBoard[rowPos[colPos]][colPos-3]="X ";
                }

                else if(p==1)
                {
                    winBoard[rowPos[colPos]][colPos]="O ";
                    winBoard[rowPos[colPos]][colPos-1]="O ";
                    winBoard[rowPos[colPos]][colPos-2]="O ";
                    winBoard[rowPos[colPos]][colPos-3]="O ";
                }
            }
        }
    }

    if(rowCount>=4)
    {
        display(winBoard);
        return true;
    }

    else
    {
        return false;
    }
}


bool diagonalChecker(string board[6][7],int rowPos[7],int colPos,string playerName[2],int p)
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