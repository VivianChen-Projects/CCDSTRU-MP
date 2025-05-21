#include <stdio.h>


#define SIZE 6
typedef char String [50];

void printGrid ( char grid [][SIZE]){
	int i,j;
	char temp [SIZE][SIZE];
	
	for (i = 0; i < SIZE; i++) {
    	for (j = 0; j < SIZE; j++) {
    		
    	temp [i][j] = grid [i][j];	
		}
			
	}
	
	printf("   ");
	
    for (j = 1; j <= SIZE; j++) { //FOR DISPLAYING NUMBERING GUIDE
    	
        printf("%d ", j);
    }
    printf("\n\n");
	
	for (i = 0; i < SIZE; i++) {
		
		printf ("%d  ", i+1); // NUMBER GUIDE
    	for (j = 0; j < SIZE; j++) {
    		
    		
    		if (temp [i][j] != 'X' && temp [i][j] != 'O'){
			
    		temp [i][j] = '.';
    		}
    		printf ("%c ", temp	 [i][j]);
    		
		}
		
		printf("\n"); // MOVE TO NEXT ROW
	}
	
}

int checkInput (int row, char comma, int column){
	
	if (row >= 1 && row <=6 && column >=1 && column <=6 && comma == ','){ //valid input
		return 1;
	}
	return 0;
}

int checkAvailability (char grid [] [SIZE], int row, int column){
	
	int i,j;
	row--; //decrement due to formatting of the grid since first grid starts with 1,1
	column--;
	for (i=0; i<SIZE; i++){
		
		for (j=0; j<SIZE; j++){
			
			if (grid [row] [column] == 'X' || grid [row] [column] == 'O'){ //if space is occupied returns 1
				
				return 1;
			}
		}
	}
	
	return 0;
}

void clearGrid(char grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = ' '; // Fill with empty characters
        }
    }
}

int checkWinXback (char grid [][SIZE]){
	
	int i,j;
	
	 for (i = 0; i < SIZE ; i++) {
        for (j = 0; j < SIZE ; j++) {
            if ((grid[i][j] == 'X' ||grid[i][j] == 'O')&& //CHECKING OF UPPER LEFT
                grid[i][j] == grid[i][j + 2] && 
                grid[i][j] == grid[i + 2][j] && 
                grid[i][j] == grid[i + 2][j + 2]&&
				grid[i][j] == grid[i + 1][j + 1]) { 
                
             if  ((grid[i+3][j+3] == 'X' ||grid[i+3][j+3] == 'O')&& //CHECKING OF LOWER RIGHT
                grid[i+3][j+3] == grid[i+3][j + 5] && 
                grid[i+3][j+3] == grid[i + 5][j+3] && 
                grid[i+3][j+3] == grid[i + 4][j + 4]&&
				grid[i+3][j+3] == grid[i + 5][j + 5]){
                	
                	return 1; //UPPER LEFT AND LOWER RIGHT FORMATION DETECTED
				}
                
            }
        }
    }

    return 0; // No formation found
}

int checkWincross_equalSlash(char grid [][SIZE]){
	
	int i,j;
	
	 for (i = 0; i < SIZE ; i++) {
        for (j = 0; j < SIZE ; j++) {
          if ((grid[i][j+4] == 'X' ||grid[i][j+4] == 'O')&& //UPPER RIGHT
                grid[i][j+4] == grid[i+1][j+3] && 
                grid[i][j+4] == grid[i + 1][j+4] && 
                grid[i][j+4] == grid[i + 1][j + 5]&&
				grid[i][j+4] == grid[i + 2][j + 4]) { 
                
                
                 
              
              if  ((grid[i+3][j] == 'X' ||grid[i+3][j] == 'O')&& //LOWER LEFT
                grid[i+3][j] == grid[i+3][j+1] && 
                grid[i+3][j] == grid[i + 3][j+2] && 
                grid[i+3][j] == grid[i + 5][j]&&
				grid[i+3][j] == grid[i + 5][j + 1]&&
				grid[i+3][j] == grid[i + 5][j + 2]){
                	
                	return 1; //UPPER RIGHT AND LOWER LEFT FORMATION DETECTED
				}
                
            }
        }
    }
    
    return 0;
}



