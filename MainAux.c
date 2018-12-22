/*
 * MainAux.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/

void printGameBoard(int* game_board){
	/*print board, see reference*/
}

int getHintsAmount(){
	int hints;
	/*get hints from user - use scanf, assumes correct input*/
	return hints;
}

int* duplicateBoard(int* game_board){
	int result [9][9][2];
	/*go over board, copy to new board*/
	return &(result[0]);
}

void copyBoard(int* origin, int* target){
	/*function copies from origin board to the other copied target board*/
	/*go over every cell*/
	/*put in every target cell <x,y> value from origin*/
}

void resetBoard(int* game_board){
	/*go over board, set to 0*/
}

int isLegalNumber(char* num){
	/*function definition:
	 * 1. gets string, if it is a legal number (1-9), cast it and return it, otherwise returns -1*/
}
