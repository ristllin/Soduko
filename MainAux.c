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
			if (game_board[x-1][y-1][1] == 1){ /*1 -> fixed*/
				printf(".%d",game_board[x-1][y-1][2]);
			} else if (game_board[x-1][y-1][2] == 0){
				printf("  ");
			}else{
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

void copyBoard(int origin[9][9][2], int target[9][9][2]){
	/*function copies from origin board to the other copied target board*/
	int x = 0;
	int y = 0;
	for (y=0;y<9;y++){
		for (x=0;x<9;x++){
			target[x][y][2] = origin[x][y][2];
		}
	}
	/*put in every target cell <x,y> value from origin*/
}

void resetBoard(int game_board[9][9][2]){
	/*go over board, set to 0*/
	int i = 0;
	int j = 0;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			game_board[i][j][1] = 0;
			game_board[i][j][2] = 0;
		}
	}
}

void clearUnfixed(int game_board[9][9][2]){
	int x = 0;
	int y = 0;
	for (y=0;y<9;y++){
		for (x=0;x<9;x++){
			if (game_board[x][y][1] == 0){
				game_board[x][y][2] = 0;
			}
		}
	}
}

void fixNCells(int game_board[9][9][2],int n){
	/*function description: randomize n times an <x,y> location, if it is un-fixed, fix it, update n to n-1 and continue until n=0*/
	int x = -1;
	int y = -1;
	while (n > 0){ /*hints left*/
		x = rand()%9;
		y = rand()%9;
		if (game_board[x][y][1] == 0){
			n-=1;
			game_board[x][y][1] = 1;
		}
	}
}

int sum_array(int a[], int num_elements){
   int i, sum=0;
   for (i=0; i<num_elements; i++)
   {
	 sum = sum + a[i];
   }
   return(sum);
}

int chooseRandomOption(int options[],int length){
	/*length gets the size of options, e.g. {0,1,2} -> length = 3*/
	/*if no options are available returns -1*/
	int i = 0;
	int random_option = -1;
	if (sum_array(options,length) > 0){
		random_option = (rand()%sum_array(options,length))+1;
		for (i=0;i<length;i++){ /*go over options*/
			if (options[i] == 1){ /*count valid option*/
				random_option -= 1;
			}
			if (options[i] == 1 && random_option <= 0){ /*reached randomly chosen index*/
				return i+1;
			}
		}
	}
	return -1;
}

int chooseNextOption(int options[],int length){
	/*length gets the size of options, e.g. {0,1,2} -> length = 3*/
	/*if no options are available returns -1*/
	int i = 0;
	if (sum_array(options,length) > 0){
		for (i=0;i<length;i++){ /*go over options*/
			if (options[i] == 1){ /*reached first option*/
				return i+1;/*returns option index+1*/
			}
		}
	}
	return -1; //no options were found
}

void findFirstZero(int game_board[9][9][2], int pos[2]){
	int x = 0;
	int y = 0;
	for (y=0;y<9;y++){
		for(x=0;x<9;x++){
			if (game_board[x][y][2] == 0){
				pos[0] = x;
				pos[1] = y;
				return;
			}
		}
	}
}

void clearFromPos(int game_board[9][9][2], int pos[2]){
//	printf("clean called on x: %d, y: %d\n",pos[0],pos[1]);/*debug*/
	int x = 0;
	int y = 0;
	for (y=pos[1];y<9;y++){
		for(x=pos[0];x<9;x++){
			game_board[x][y][2] = 0;
		}
	}
//	printGameBoard(game_board); /*debug*/
}
