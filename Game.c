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

/*functions:*/
void set(int[4],int[9][9][2]);
void hint(int [4], int[9][9][2]);
void validate(int[9][9][2], int[9][9][2]);

static const char INVALID[] = "Error: invalid command\n";

int isFull(int game_board[9][9][2]){
	/*checks if a board is full of numbers*/
	int x = 0;
	int y = 0;
	for ( y=0 ; y<9 ; y++ ){
		for ( x=0 ; x<9 ; x++){
			if (game_board[x][y][2] == 0){
				return 0;
			}
		}
	}
	return 1;
}

int legalInput(int parsed_command[4],int amount_of_variants){
	int i = 0;
	for (i=1;i<=amount_of_variants;i++){
		if (parsed_command[i] == -1 || parsed_command[i] > 9 || parsed_command[i] < 0){
			return 0;
		}
	}
	return 1;
}

void execute(int parsed_command[4],int solved_board [9][9][2],int game_board [9][9][2]){
	int command = parsed_command[1]; /*[command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit*/
	switch(command){
	case -1:
		/*invalid option*/
		printf("%s",INVALID);
		break;
	case 1: /*set*/
		/*change in game_board, in location <X,Y> to value Z*/
		set(parsed_command,game_board);
		break;
	case 2:
		/*hint*/
		/*check legality of vars*/
		hint(parsed_command,solved_board);
		/*go to slved_baord at location <X,Y> and print Z*/
		break;
	case 3:
		/*validate*/
		validate(solved_board,game_board);
		break;
	case 4:
		printf("executing restart\n");
		initialize(game_board,solved_board);
		break;
	case 5:
		printf("Exiting...\n");
		exit(1);
		break;
	}
}

void set(int parsed_command[4], int game_board[9][9][2]){
	/*set play board at location x,y to value z if legal*/
	int options[9] = {1};
	int x = parsed_command[2]-1;
	int y = parsed_command[3]-1;
	int z = parsed_command[4];
	int debug = 0;
	printf("executing set\n");
	if (legalInput(parsed_command,4)){
		if (game_board [9][9][1] == 1){ /*is fixed*/
				printf("Error: cell is fixed");
			}
		else{
			legalOptions(game_board,x,y,options);
			printf("options: ["); /*from here debug*/
			for (debug = 0;debug<9;debug++){
				printf("%d,",options[debug]);
			}
			printf("]\n"); /*to here debug*/
			if (options[z-1] == 1){
				game_board[x][y][2] = z;
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
	printGameBoard(solved_board);/*debug*/
	printf("executing hint with x:%d,y:%d\n",x,y);/*debug*/
	printf("Hint: set cell to %d\n",solved_board[x][y][2]);
}

void validate(int solved_board[9][9][2], int game_board[9][9][2]){
	printf("executing validate\n");
	resetBoard(solved_board);
	solver(game_board,solved_board);
}
