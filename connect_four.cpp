#include<iostream>
using namespace std;

class Board
{
public:

int i,j,p,choice,colPos,randNum;
string board[6][7],playerName[2]; //board of 6 rows and 7 columns

Board()
{
    for(i=0;i<6;i++) //rows
    {
        for(j=0;j<7;j++) //columns
        {
            board[i][j]="_ ";
        }
    } //initializes empty board
    
    cout<<"Choose your opponent:\n1. Human\n2. Computer"<<endl;
    cin>>choice;
    
    while(true)
    {
        if(choice==1)
        {
            cout<<"\nEnter Player 1 name:"<<endl;
            cin>>playerName[0]; //player 1
            cout<<"\nEnter Player 2 name:"<<endl;
            cin>>playerName[1]; //player 2
            
            display(board);
            updater(board,playerName,0,0);
            
            break;
        }
        
        else if(choice==2)
        {
            cout<<"\nEnter Player name:"<<endl;
            cin>>playerName[0]; //human player
            playerName[1]="Computer"; //bot
            
            display(board);
            updater(board,playerName,0,1);
            
            break;
        }
        
        else
        {
            cout<<"\nSorry, please enter either 1 or 2!"<<endl;
        }
    }
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


void updater(string board[6][7],string playerName[2],int p,int opponent) //updates board with new moves
{
    int rowPos[7],winner;

    while(isDraw(board)!=true) //as long as it is not a draw
    {
        colPos=playerChoice(playerName,p,opponent); //player's choice goes into board

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

        else if(p==1) //if Player 2 or bot then use "O"
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

    if(isDraw(board)==true)
    {
        cout<<"\nWhups, it's a draw!"<<endl;
    }
    else
    {
        if(opponent==0)
        {
            cout<<"\nCongratulations, "<<playerName[p]<<"! You won!"<<endl;
        }
        else if(opponent==1)
        {
            if(p==0)
            {
                cout<<"\nCongratulations, "<<playerName[p]<<"! You won!"<<endl;
            }
            else if(p==1)
            {
                cout<<"\nBad luck, "<<playerName[p]<<" - looks like the computer won this round!"<<endl;
            }
        }
    }
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


bool isDraw(string board[6][7])
{
    int isFullCount=0;
    for(j=0;j<6;j++)
    {
        if(board[0][j]=="_ ")
        {
            break;
        }
        else
        {
            isFullCount++;
        }
    }

    if(isFullCount==7)
    {
        return true; //draw
    }

    else
    {
        return false;
    }
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


bool verticalChecker(string board[6][7],int rowPos[7],int colPos,string playerName[2],int p)
{
    string winBoard[6][7];

    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            winBoard[i][j]="_ ";
        }
    }

    if(rowPos[colPos]<=2) //starts checking lower values after it reaches the third row (since we play from below)
    {
        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+1][colPos]) //checking down
        {
            if(rowPos[colPos]+1<=3) //WILD PENIS ALERT!!!
            {
                if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+2][colPos])
                {
                    if(rowPos[colPos]+2<=4)
                    {
                        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+3][colPos])
                        {
                            if(p==0)
                            {
                                for(i=0;i<4;i++)
                                {
                                    winBoard[rowPos[colPos]+i][colPos]="X ";
                                }
                            }

                            else if(p==1)
                            {
                                for(i=0;i<4;i++)
                                {
                                    winBoard[rowPos[colPos]+i][colPos]="O ";
                                }
                            }
                            display(winBoard);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


bool horizontalChecker(string board[6][7],int rowPos[7],int colPos,string playerName[2],int p)
{
    int colCount=1;
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
        if(p==0)
        {
            winBoard[rowPos[colPos]][colPos]="X ";
            winBoard[rowPos[colPos]][colPos+1]="X ";
        }
        else if(p==1)
        {
            winBoard[rowPos[colPos]][colPos]="O ";
            winBoard[rowPos[colPos]][colPos+1]="O ";
        }
        colCount++;

        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos+2])
        {
            if(p==0)
            {
                winBoard[rowPos[colPos]][colPos+2]="X ";
            }
            else if(p==1)
            {
                winBoard[rowPos[colPos]][colPos+2]="O ";
            }
            colCount++;

            if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos+3])
            {
                if(p==0)
                {
                    winBoard[rowPos[colPos]][colPos+3]="X ";
                }

                else if(p==1)
                {
                    winBoard[rowPos[colPos]][colPos+3]="O ";
                }
                colCount++;
            }
        }
    }

    if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos-1]) //going left
    {
        if(p==0)
        {
            winBoard[rowPos[colPos]][colPos]="X ";
            winBoard[rowPos[colPos]][colPos-1]="X ";
        }
        else if(p==1)
        {
            winBoard[rowPos[colPos]][colPos]="O ";
            winBoard[rowPos[colPos]][colPos-1]="O ";
        }
        colCount++;

        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos-2])
        {
            if(p==0)
            {
                winBoard[rowPos[colPos]][colPos-2]="X ";
            }
            else if(p==1)
            {
                winBoard[rowPos[colPos]][colPos-2]="O ";
            }
            colCount++;

            if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]][colPos-3])
            {
                if(p==0)
                {
                    winBoard[rowPos[colPos]][colPos-3]="X ";
                }

                else if(p==1)
                {
                    winBoard[rowPos[colPos]][colPos-3]="O ";
                }
                colCount++;
            }
        }
    }

    if(colCount>=4)
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
    string winBoard[6][7];

    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            winBoard[i][j]="_ ";
        }
    }

    if(rowPos[colPos]<=2)
    {
        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+1][colPos+1]) //bottom right
        {
            if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+2][colPos+2])
            {
                if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+3][colPos+3])
                {
                    if(p==0)
                    {
                        for(i=0;i<4;i++)
                        {
                            winBoard[rowPos[colPos]+i][colPos+i]="X ";
                        }
                    }

                    else if(p==1)
                    {
                        for(i=0;i<4;i++)
                        {
                            winBoard[rowPos[colPos]+i][colPos+i]="O ";
                        }
                    }
                    display(winBoard);
                    return true;
                }
            }
        }

        if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+1][colPos-1]) //bottom left
        {
            if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+2][colPos-2])
            {
                if(board[rowPos[colPos]][colPos]==board[rowPos[colPos]+3][colPos-3])
                {
                    if(p==0)
                    {
                        for(i=0;i<4;i++)
                        {
                            winBoard[rowPos[colPos]+i][colPos-i]="X ";
                        }
                    }

                    else if(p==1)
                    {
                        for(i=0;i<4;i++)
                        {
                            winBoard[rowPos[colPos]+i][colPos-i]="O ";
                        }
                    }
                    display(winBoard);
                    return true;
                }
            }
        }
    }
    return false;
}


int playerChoice(string playerName[2],int p,int opponent)
{
    if(opponent==0) //if human vs. human
    {
        cout<<"\nIt's your turn, "<<playerName[p]<<"! Which column do you want to play in?"<<endl;

        while(true)
        {
            cin>>colPos;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"\nSorry, "<<playerName[p]<<" - please enter a valid column number between 1 & 7!"<<endl;
            }
            
            else if(colPos<1 || colPos>7)
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
    
    else if(opponent==1)
    {
        colPos=rand()%6+1;
        return colPos-1;
    }
    
    else
    {
        return 0; //to prevent a warning
    }
}
};


int main()
{
    cout<<"\nWelcome to CONNECT FOUR by Urmil Shroff!"<<endl;
    Board obj; //lel
    return 0;
}