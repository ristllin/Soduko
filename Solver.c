/*
 * Solver.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/

/*Modules:*/
#include "MainAux.h";

/*--------*/


void solver(int* play_board, int* solved_board){
	/*calls solver and duplicates variables, to avoid alteration of original boards by solver*/
	/*duplicate play_board*/
	/*solver(dupe_play_board)*/
	/*copy data from duplicated to solved*/
}

void recursiveSolver(int* solved_board){
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

void puzzleGenerator(int* play_board, int hints){
	resetBoard(play_board);

}

int* legalOptions(int* play_board, int x, int y){
	/*function description: function gets a board and an <X,Y> location, returns the legal options for the location
	 * in an array, in which each index represents the optional number. 0 -illegal, 1-optional*/
	/*int results[9];*/
	/*check x*/
	/*check y*/
	/*check square*/
	return &(results[0]);
}
