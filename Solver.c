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

void legalOptions(int play_board[9][9][2], int x, int y, int options[9]){
	/*function description: function gets a board and an <X,Y> location, returns the legal options for the location
	 * in an array, in which each index represents the optional number. 0 -illegal, 1-optional*/
	int i = 0;
	int num = 0;
	int *p = options;
	/*reset options*/
	for (i=0;i<10;i++){
		*p++ = 1;
	}
	for (i=0;i<10;i++){
		num = play_board[i][y][2]; /*check x*/
		if (num > 0 && num < 10){
			options[num-1] = 0; /*mark the number as taken by marking matching index*/
		}
		num = play_board[x][i][2]; /*check y*/
		if (num > 0 && num < 10){
			options[num-1] = 0;
		}
		num = play_board[(((x)/3)*3)+(i%3)][(((y)/3)*3)+(i/3)][2]; {/*check box*/
		if (num > 0 && num < 10)
			options[num-1] = 0;
		}
	}
}

void solver(int play_board[9][9][2], int solved_board[9][9][2]){
	/*calls solver and duplicates variables, to avoid alteration of original boards by solver*/
	/*duplicate play_board*/
	/*solver(dupe_play_board)*/
	/*copy data from duplicated to solved*/
}

void recursiveSolver(int solved_board[9][9][2]){
	/*function description:
	 * function will alter both boards given, which should be taken into consideration*/
	/*flag = true*/
	/*for x*/
		/*for y*/
			/*calculate legal options*/
			/*if 0 legal moves, terminate -> flag = false*/
			/*else if solved full, terminate {some branch finished}*/
			/*else, for legal options*/
				/*duplicate solved_board*/
				/*solver(duplicated board, original_solved_board)*/
				/*free duplicate*/
		/*if flag false, terminate*/
	/*if flag, terminate*/
}

void randomizedBacktracking(int play_board[9][9][2]){
	/*function description: for each cell, compute legal options and randomly chose one of them*/
	/*if not full*/
	/*if full return 1*/
	/*for each cell*/
	/*if cell == 0*/
	/*check legal options*/
	/*if none, return 0*/
	/*for each legal option*/
	/*set on board current option*/
	/*if call self == 1*/
	/*return 1*/

	int x = 0;
	int y = 0;
	int i = 0;
	int options_amount = -1;
	int options[9] = {1};
	for (y=0;y < 9;y++){
		for (x=0;x < 9;x++){
			printGameBoard(play_board); /*debug*/
			legalOptions(play_board,x,y,options);
			options_amount = (rand()%sum_array(options,9))+1;
			printf("["); /*debug*/
			for (i=0;i<9;i++){
				printf("%d,",options[i]); /*debug*/
			}
			printf("]\n");
			for (i=0;i<9;i++){ /*go over options*/
				if (options[i] == 1){ /*count valid option*/
					options_amount -= 1;
				}
				if (options[i] == 1 && options_amount <= 0){ /*reached randomly chosen index*/
					play_board[x][y][2] = i+1;
					printf("choose: %d\n",i+1);/*debug*/
					break;
				}
			}
		}
	}
}

void puzzleGenerator(int play_board[9][9][2], int hints){
	printf("de:PG:1\n"); /*debug*/
	resetBoard(play_board);
	printf("de:PG:2\n"); /*debug*/
	randomizedBacktracking(play_board);
	printf("de:PG:3\n"); /*debug*/
	fixNCells(play_board,hints);
	printf("de:PG:4\n"); /*debug*/
	clearUnfixed(play_board);
	printf("de:PG:5\n"); /*debug*/
}




