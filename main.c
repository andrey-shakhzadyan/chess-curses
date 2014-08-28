
#include "headers/main.h"
#include <sys/time.h>


int main()
{
  char boardhalf[] = "RNBQKBNRP8*8*8*8*8p8rnbqkbnr";
  char boad[] = "RNBQKBNRPPPPPPPP********************************ppppppppRNBQKBNR";
  struct timeval stop,start;
  int runtimes[99];
  int iii = 0;
  while(iii < 100)
    {
      gettimeofday(&start,NULL);
      drawBoard(boardhalf, sizeof(boardhalf)-1);
      gettimeofday(&stop,NULL);
      
  printf("took %lu\n", stop.tv_usec - start.tv_usec);
  gettimeofday(&start,NULL);
  draw(boad);
  gettimeofday(&stop,NULL);
  printf("took %lu\n", stop.tv_usec - start.tv_usec);
}
/*****************************
void drawBoard(char *board[])

Summary
------------------------------
| This function is an attempt 
| to display an 8x8 chessboard
| compressed with my proprietary
| algorithm.
------------------------------

Algorithm
------------------------------
+The Board
| The board compression works as follows:
| The chessmen on the board are represented
| as ASCII chars RNBQKP(white) and rnkbqkp(black),
| the main figures corresponding to their 
| symbols in algebraic notation(e.g R -> rook).
| Spaces are simply whitespace; they are not distinguished
| until the board is displayed.
| Repeating values(for example, the initial row of pawns)
| are followed by an ASCII char from 50 to 57(they are the
| ASCII chars corresponding to integers 2-9), and that char
| tells the decompressor how many times to repeat it.
|
+Decompression
| The decompression process is simple:
| The decompressor(drawBoard), iterates through the string
| containing the board. Upon every iteration, it first checks
| if the next char in the string is an ASCII char from 50 to 58,
| if that is the case, then the programs loops that many times,
| printing the repeating char, and if it is any other ASCII char,
| the program prints once.
+Performance 
|
-------------------------------
*****************************/
void drawBoard(char board[],int size)
{
  
  int iter;
  int tiles = 0;
  for(iter = 0; iter < size; iter++)
    {
      if( (int)board[iter+1] >= 50 && (int)board[iter+1] <= 57 )
	{
	  int iii;
	  for(iii = 1; iii <=  ((int)board[iter+1]) - 48; iii++)
	    {
	   
	      printf("%c", board[iter]);
	      tiles++;
	      if(tiles % 8 == 0)
		{
		  printf("\n");
		}
	      
	    }
	  iter += 1;
	} else 
	{
	  printf("%c",board[iter]);
	  tiles++;
	  if( tiles  % 8  == 0 && tiles > 0)
	    {
	 
	      printf("\n");
	    }
	 
	  

      }
    }
  printf("\n");
}


void draw(char board[])
{
  int iii;
  for(iii = 0; iii < 64; iii++)
    {
      if(iii%8 == 0 && iii != 0)
	{
	  printf("\n");
	}
      printf("%c",board[iii]);

    }
}

