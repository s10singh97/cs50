/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d, m, n;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();
    m = (d - 1);
    n = (d - 1);
    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int n, i, j;
    if((d % 2) == 0)                                       //For Even Matrix
    {
        n = 1;
        for(i = 0; i < d; i++)
        {
            for(j = 0; j < d; j++)
            {
                board[i][j] = (d * d) - n;
                n++;
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == 1)
                    board[i][j] = 2;
            }
        }
    }
    else                                                   //For Odd Matrix
    {
        n = 1;
        for(i = 0; i < d; i++)
        {
            for(j = 0; j < d; j++)
            {
                board[i][j] = (d * d) - n;
                n++;
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int i, j;
    for(i = 0; i < d; i++)
    {
        for(j = 0; j < d; j++)
        {
            if(board[i][j] == 0)
                printf("%c\t",95);
            else
                printf("%i\t", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int i , j;
    for(i = 0; i < d; i++)
    {
        for(j = 0; j < d; j++)
        {
            if(tile == board[i][j])
            {
                //Checking if the element of board[i][j] is adjacent to '0' tile
                if((((i - 1) == m) && (j == n)) || (((i + 1) == m) && (j == n)) || ((i == m) && ((j - 1) == n)) || ((i == m) && ((j + 1) == n)))
                {
                    board[m][n] = board[i][j];
                    board[i][j] = 0;
                    //Repositioning the '0' tile
                    m = i;
                    n = j;
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int i ,j;
    int check[DIM_MAX][DIM_MAX];                           //The matrix with winning configuration
    for(i = 0; i < d; i++)
    {
        for(j = 0; j < d; j++)
        {
            check[i][j] = 0;                               //Initializing this matrix with 0 to avoid garbage value
        }
    }
    int n = 1;
    for(i = 0; i < d; i++)                                 //Making this matrix according to the winning configuration
    {
        for(j = 0; j < d; j++)
        {
            check[i][j] += n;
            n++;
            if((i == (d - 1)) && (j == (d - 1)))
                check[i][j] = 0;
        }
    }
    int flag[DIM_MAX * DIM_MAX], k = 0;                    //Linear Array of Flags
    for(i = 0; i < (d * d); i++)
    {
        flag[i] = 0;    
    }
    for(i = 0; i < d; i++)                                 //Checking each element of 'board' with 'check' and increasing each element of flag by 1 if they match
    {
        for(j = 0; j < d; j++)
        {
            if(board[i][j] == check[i][j])
            {
                flag[k]++;
                k++;
            }
        }
    }
    for(i = 0; i < (d * d); i++)                           //Checking array of flags
    {
        if(flag[i] != 1)
            return false;
    }
    return true;
}