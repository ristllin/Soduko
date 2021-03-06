/*
 * Solver.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*Modules:*/
#include "MainAux.h"

/*--------*/
/*int recursiveSolver(int[9][9][2]);*/


void legalOptions(int game_board[9][9][2], int x, int y, int options[9]){
	/*function description: function gets a board and an <X,Y> location, returns the legal options for the location
	 * in an array, in which each index represents the optional number. 0 -illegal, 1-optional*/
	int i = 0;
	int num = 0;
	int *p = options;
	for (i=0;i<10;i++){ /*reset var options*/
		*p++ = 1;
	}
	for (i=0;i<9;i++){
		num = game_board[i][y][2]; /*check x*/
		if (num > 0 && num < 10){
			options[num-1] = 0; /*mark the number as taken by marking matching index*/
		}
		num = game_board[x][i][2]; /*check y*/
		if (num > 0 && num < 10){
			options[num-1] = 0;
		}
		num = game_board[(((x)/3)*3)+(i%3)][(((y)/3)*3)+(i/3)][2]; {/*check box*/
		if (num > 0 && num < 10)
			options[num-1] = 0;
		}
	}
}

int recursiveSolver(int solved_board[9][9][2]){
	/*function description: function will alter both boards given, which should be taken into consideration upon func call*/
	/*for every cell, for every legal option, call self with 1 of the options, and accept if the board is full, reject if no options are available*/
	int x = 0;
	int y = 0;
	int first_zero_pos[2] = {-1};
	int i = 0;
	int option = -1;
	int options[9] = {1}; /*created locally in function scope for recursive uses*/
	int options_amount = -1;
	/*-------------------*/
	if (isFull(solved_board)){ /*some branch finished, the rest is irrelevant*/
		return 1;
	}
	findFirstZero(solved_board,first_zero_pos); /*if solution failed, try another opion, clean all cells after this cell from last use*/
	for (y=0;y < 9;y++){ /*for each cell*/
		for (x=0;x < 9;x++){
			if (solved_board[x][y][2] != 0){ /*if cell != 0, still in "built area"*/
				continue;
			}
			legalOptions(solved_board,x,y,options); /*check legal options*/
			option = chooseNextOption(options,9);
			if (option == -1){ /*if no legal options left, return 0*/
				clearFromPos(solved_board,first_zero_pos);
				return 0;
			}
			options_amount = sum_array(options,9);
			for (i=0;i<options_amount;i++){
				solved_board[x][y][2] = option;
				options[option-1] = 0; /*remove tested option from options*/
				if (isFull(solved_board) || recursiveSolver(solved_board)){ /*just filled the board or one of the branches did*/
					return 1;
				}
				option = chooseNextOption(options,9); /*set new option*/
				if (option == -1){
					clearFromPos(solved_board,first_zero_pos);
					return 0;
				}
			}
			clearFromPos(solved_board,first_zero_pos);
			return 0;
		}
	}
	return -1; /*function error*/
}

void solver(int game_board[9][9][2], int solved_board[9][9][2]){
	/*Function description: calls solver and duplicates variables, to avoid alteration of original boards by solver*/
	copyBoard(game_board,solved_board);
	if (recursiveSolver(solved_board)){
		printf("Validation passed: board is solvable\n");
	} else {
		printf("Validation failed: board is unsolvable\n");
	}
}

int randomizedBacktracking(int game_board[9][9][2]){
	/*function description: for each cell, compute legal options. then randomly and recursively chooses one of them and continues until board is full*/
	int x = 0;
	int y = 0;
	int first_zero_pos[2] = {-1};
	int i = 0;
	int option = -1;
	int options[9] = {1}; /*created locally in function scope for recursive uses*/
	int options_amount = -1;
	/*-------------------*/
	if (isFull(game_board)){ /*some branch finished, the rest is irrelevant*/
		return 1;
	}
	findFirstZero(game_board,first_zero_pos);
	for (y=0;y < 9;y++){ /*for each cell*/
		for (x=0;x < 9;x++){
			if (game_board[x][y][2] != 0){ /*if cell != 0, still in "built area"*/
				continue;
			}
			legalOptions(game_board,x,y,options); /*check legal options*/
			option = chooseRandomOption(options,9);
			if (option == -1){ /*if no legal options left, return 0*/
				clearFromPos(game_board,first_zero_pos);
				return 0;
			}
			options_amount = sum_array(options,9);
			for (i=0;i<options_amount;i++){
				game_board[x][y][2] = option;
				options[option-1] = 0; /*remove tested option from options*/
				if (isFull(game_board) || randomizedBacktracking(game_board)){ /*just filled the board or one of the branches did*/
					return 1;
				}
				option = chooseRandomOption(options,9); /*set new option*/
				if (option == -1){
					clearFromPos(game_board,first_zero_pos);
					return 0;
				}
			}
			clearFromPos(game_board,first_zero_pos);
			return 0;
		}
	}
	return -1; /*function error*/
}

void puzzleGenerator(int game_board[9][9][2],int solved_board[9][9][2], int hints){
	resetBoard(game_board);
	resetBoard(solved_board);
	randomizedBacktracking(solved_board);
	copyBoard(solved_board,game_board);
	fixNCells(game_board,hints);
	clearUnfixed(game_board);
}
