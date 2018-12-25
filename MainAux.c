/*
 * MainAux.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/
#include <stdio.h>
#include <stdlib.h>


/*Functions:*/
void printGameBoard(int game_board[9][9][2]){ /*<<<<<<<DONE>>>>>>>*/
	/*print board*/
	int x = 0;
	int y = 0;
	printf("----------------------------------\n");
	for (y = 1;y<10;y++){
		for (x=1;x<10;x++){
			if (x==1) {/*first line*/
				printf("|");
			}
			if (game_board[x-1][y-1][1] == 1){
				printf(".%d",game_board[x-1][y-1][2]);
			} else {
				printf(" %d",game_board[x-1][y-1][2]);
			}
			if (x%9 == 0 && x>0){ /*end of line*/
				printf("|\n");
			} else if (x%3 == 0) { /*end of box*/
				printf("|");
			}
			if (x%9 == 0 && y%3 == 0){ /*3 rows separation*/
				printf("----------------------------------\n");
			}
		}
	}
}

int getHintsAmount(){ /*<<<<<<<DONE>>>>>>>>*/
	int hints = -1;
	int* hintsp = &hints;
	/*get hints from user - use scanf, assumes correct input*/
	while (*hintsp == -1){ /*illegal input, error and retry*/
		printf("Please enter the number of cells to fill [0-80]:\n");
		if (scanf("%d",hintsp) == EOF){
			printf("Exiting…\n");
			exit(1);
		}
		if (*hintsp < 0 || *hintsp > 80){ /*check legality*/
			*hintsp = -1;
			printf("Error: invalid number of cells to fill (should be between 0 and 80)\n");
		}
	}
	return *hintsp;
}

void copyBoard(int* origin, int* target){
	/*function copies from origin board to the other copied target board*/
	/*go over every cell*/
	/*put in every target cell <x,y> value from origin*/
}

void resetBoard(int game_board[9][9][2]){
	/*go over board, set to 0*/
	int i = 0;
	int j = 0;
	for (;i<10;i++){
		for (;j<10;j++){
			game_board[i][j][0] = 0;
			game_board[i][j][1] = 0;
		}
	}
}

int isLegalNumber(char* num){
	int result = -1;
	/*function definition:
	 * 1. gets string, if it is a legal number (1-9), cast it and return it, otherwise returns -1*/
	return result;
}

void clearUnfixed(int play_board[9][9][2]){
	int i = 0;
	int j = 0;
	for (;i<10;i++){
		for (;j<10;j++){
			if (play_board[i][j][0] == 0){
				play_board[i][j][1] = 0;
			}
		}
	}
}

void fixNCells(int play_board[9][9][2],int n){
	/*function description: randomize n times an <x,y> location, if it is un-fixed, fix it, update n to n-1 and continue until n=0*/

}

int sum_array(int a[], int num_elements){
   int i, sum=0;
   for (i=0; i<num_elements; i++)
   {
	 sum = sum + a[i];
   }
   return(sum);
}
