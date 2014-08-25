#include "headers/main.h"



int main()
{
  char boardhalf[] = "RNBQKBNRP8 9 9 6p8rnbqkbnr";
  
    
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
| are followed by an ASCII char from 48 to 57(they are the
| ASCII chars corresponding to integers 0-8), and that char
| tells the decompressor how many times to repeat it.
|
+Decompression
| The decompression process is simple:
| The decompressor(drawBoard), iterates through the string
| containing the board. Upon every iteration, it first checks
| if the next char in the string is an ASCII char from 47 to 58,
| if that is the case, then the programs loops that many times,
| printing the repeating char, and  Otherwise, it simply prints the   
-------------------------------
*****************************/
void drawBoard(char *board[])
{
  int iter;
  int inc = 1;
  for(iter = 0; iter <= sizeof(*board); iter+= inc)
    {
      if( (int *)board[iter+1] >= 48 || (int *)board[iter+1] <= 57 )
	{
	  int iii;
	  for(iii = 0; iii <= ((int *)board[iter+1] - 1); iii++)
	    {
	      //Ncurses print board[iter]
	    }
	}
      else {
	//Ncurses print board[iter]
      }
