/*
 * Initialization.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/

/*Modules:*/
#include "MainAux.h";
#include "Solver.h";

void initialize(int[9][9][2] play_board, int[9][9][2] solved_board){
	/*function description:
	 * 1. asks user for amount of hints,
	 * 2. generates a puzzle with that amount of hints
	 * 3. sloves it, saving the boards at the references given*/
	/*Function variables:*/
	int hints_amount = 0;
	/*-------------------*/
	hints_amount = getHintsAmount();
	puzzleGenerator(play_board,hints_amount);
	solver(play_board,solved_board);
}
