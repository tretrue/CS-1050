//Robert Truesdale
//Connect 4
//CS 1050

#include <stdio.h>
#include <stdlib.h>

char getCounter(void);
char game(char, char);
void printBoard(void);
int turn(char, int);
int victory(char, int);

char board[6][7] = {{'-','-','-','-','-','-','-'},
                    {'-','-','-','-','-','-','-'},
                    {'-','-','-','-','-','-','-'},
                    {'-','-','-','-','-','-','-'},
                    {'-','-','-','-','-','-','-'},
                    {'-','-','-','-','-','-','-'}};

int main (void)
{
    printf("\n*****CONNECT 4*****\n");
    char player1 = getCounter();
    char player2 = getCounter();

    while(player1 == player2)
    {
        printf("\nError! Name already taken.\nPlayer 2, enter a different character: ");
        scanf(" %c", &player2);
    }

    char winner = game(player1, player2);
    printf("Player %c wins!\n", winner);
    return 0;
}

char getCounter (void)
{
    static int i = 1;
    char letter;

    printf("\nPlayer %d, enter your letter (A-Z): ", i);
    scanf(" %c", &letter);

    while(letter < 65 || letter > 90)
    {
        printf("\nPlayer %d, invalid character, must be uppercase A-Z: ", i);
        scanf(" %c", &letter);
    }
    
    
    i++;
    return letter;
}

char game(char p1, char p2)
{
    int column;
    char winner;
    while(1)
    {
        printf("\n %c, your turn. Enter a column to drop into (1-7): ", p1);
        scanf("%d", &column);
        while(column > 7 || column < 0)
        {
            printf("Error! That column doesn't exist. %c, re-enter a column: ", p1);
            scanf("%d", &column);
        }
    
        if(turn(p1,column) == 1){
            winner = p1;
            break;
        }
            printBoard();


        printf("\n %c, your turn. Enter a column to drop into (1-7): ", p2);
        scanf("%d", &column);
        while(column > 7 || column < 0)
        {
            printf("Error! That column doesn't exist. %c, re-enter a column: ", p2);
            scanf("%d", &column);
        }

        if(turn(p2,column) == 1){
        winner = p2;
        break;
    }
        printBoard();
    }

    return winner;
}

void printBoard (void)
{
    int i;
    int j;
    for(i = 0; i <= 5; i++)
    {
        for(j = 0; j < 7; j++)
        {
            printf("%c ", board[ i ][ j ]);
        }
    printf("\n");
    }

}

int turn (char player, int column)
{
    int i;
    column -= 1; 

    for(i = 5; i >= 0; --i)
    {   
       if( board[i][column] == '-')
       {
           board[i][column] = player;
           break;
       }

    }

    int vict = victory(player, column);
    
    return vict;
}

int victory (char player, int column)
{
    int vict = 0;
    int i, j;
    int countervert = 0;
    int counterhor = 0;
    for(i = 0; board[i][column] == '-' || board[i][column] == player; i++)
    {
        if(board[i][column] == player)
        countervert++;
    }
    if(countervert == 4)
    {vict = 1;
    printBoard();}
    
    for(j = 0; j < 6; j++)
    {
        if(board[j][column] == player)
        break;
    }

    column = 0;

    for(i = j ; board[i][column] == '-' || board[i][column] == player; column++ )
    {
        if(board[i][column] == player)
        counterhor++;
      
    }
    
    if(counterhor >= 4)
    {vict = 1;
    printBoard();}
    
    return vict;
}