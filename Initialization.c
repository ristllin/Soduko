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
	 * asks user for amount of hints, then generates a puzzle with that amount of hints
	 * then sloves it, saving the boards by the reference given*/
	/*Function variables:
	 */
	int hints_amount = 0;
	/*-------------------*/
	hints_amount = getHintsAmount();
	puzzleGenerator(play_board,hints_amount);
	solver(play_board,solved_board);
}
