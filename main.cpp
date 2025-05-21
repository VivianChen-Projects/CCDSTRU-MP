#include <stdio.h>
#include "function.cpp"
#define SIZE 6
typedef char String [50];


int main (){
	
	char grid[SIZE][SIZE];
	char firstplayer;
	char comma;
	int rowx,columnx;
	int rowy,columny;
	int game =1;
	int moves =0;
	do {
	
	printf ("Who plays first? (X or O): ");
	scanf (" %c", &firstplayer);
	
	if (firstplayer != 'X' && firstplayer != 'O'){ //checking of validity of first player input
		printf ("INVALID INPUT!\n");
	}
	
 	}while (firstplayer != 'X' && firstplayer != 'O');
 	
	printGrid (grid);
	
	while (game) {
		
		do {
		
		printf ("Enter move (row x column | ex. 1,1): ");
		scanf ("%d%c%d", &rowx,&comma, &columnx);
		
		if (checkInput (rowx,comma,columnx)==0){
			printf ("INVALID INPUT!\n");
		}
		
		else if (checkAvailability (grid,rowx,columnx)==1){
			printf ("INVALID INPUT. SPACE OCCUPIED\n");
		}
		
		} while (checkInput (rowx,comma,columnx)==0 || checkAvailability (grid,rowx,columnx)==1); // loops while input is invalid
		
		if (firstplayer == 'X'){ //putting X or O in grids
			grid [rowx-1] [columnx-1] = 'X';
		} else 	grid [rowx-1] [columnx-1] = 'O';
	 
	 printGrid (grid);
	 moves++; //increment number of moves to check tie condition
	 
	 if (checkWinXback (grid)){
	 	printf ("%c WIN\n", firstplayer);
	 	game = 0;

	}else if (checkWincross_equalSlash(grid)){
	 	printf ("%c WIN\n", firstplayer);
	 	game = 0;
	 	
	} else if (moves == SIZE*SIZE){
		printf ("NOBODY WINS! IT IS A TIE\n");
		game =0;
	}
	
	
	 	if (firstplayer == 'X'){ //switching of player's turn
	 		firstplayer = 'O';
		 }else firstplayer = 'X';
	 
	
	}
	
	
 	
 
}