/*
 * Game.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/
#include <stdio.h>
#include <stdlib.h>
/*Modules:*/
#include "Solver.h"
#include "Initialization.h"
#include "MainAux.h"

/*Global variables: */
static const char INVALID[] = "Error: invalid command\n";

/*functions:*/

int legalInput(int parsed_command[4],int amount_of_variants){
	int i = 0;
	for (i=1;i<=amount_of_variants;i++){
		if (parsed_command[i] == -1 || parsed_command[i] > 9 || parsed_command[i] < 0){
			return 0;
		}
	}
	return 1;
}

void set(int parsed_command[4], int game_board[9][9][2],int show_flag[1]){
	/*set play board at location x,y to value z if legal*/
	int options[9] = {1};
	int x = parsed_command[2]-1;
	int y = parsed_command[3]-1;
	int z = parsed_command[4];
	int HeizenBugFix = 0;
	if (legalInput(parsed_command,4)){
		if (game_board [x][y][1] == 1){ /*is fixed*/
				printf("Error: cell is fixed\n");
			}
		else{
			legalOptions(game_board,x,y,options);
			for (HeizenBugFix = 0;HeizenBugFix<9;HeizenBugFix++){
			}
			if (options[z-1] == 1 || game_board[x][y][2] == z){
				game_board[x][y][2] = z;
				show_flag[0] = 1;
			} else {
				printf("Error value is invalid\n");
			}
		}
	} else{
		printf("%s",INVALID);
	}
}

void hint(int parsed_command[4],int solved_board[9][9][2]){
	int x = parsed_command[2]-1;
	int y = parsed_command[3]-1;
	printf("Hint: set cell to %d\n",solved_board[x][y][2]);
}

void execute(int parsed_command[4],int solved_board [9][9][2],int game_board [9][9][2],int show_flag[1]){
	int command = parsed_command[1]; /*[command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit*/
	switch(command){
	case -1: /*invalid option*/
		printf("%s",INVALID);
		break;
	case 1: /*set change in game_board, in location <X,Y> to value Z*/
		set(parsed_command,game_board,show_flag);
		break;
	case 2: /*go to slved_baord at location <X,Y> and print Z*/
		hint(parsed_command,solved_board);
		break;
	case 3: /*validate*/
		resetBoard(solved_board);
		solver(game_board,solved_board);
		break;
	case 4:
		initialize(game_board,solved_board);
		show_flag[0] = 1;
		break;
	case 5:
		printf("Exiting...\n");
		exit(1);
		break;
	}
}


