/*
 * Main.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*Modules*/
#include "SPBufferset.h"


/*Global variables:*/
int game_status = 0; /*0=initialization, 1= Game on 2=Game over*/
int solved_board[9][9][2] = {0}; /*initialized to an empty soduko borad, each cell is a tuple (fixed/not-fixed,value)*/
int play_board[9][9][2] = {0};
char user_command[1024];
int parsed_command[4] =  {0}; /*[command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit*/

int main(int argc, char *argv[]){
	SP_BUFF_SET(); /*Windows buffer auto print flush*/
	srand(atoi(argv[1])); /*randomizing by preset seed*/
	initialize(play_board,solved_board);/*generates new play board and solves it on the solved board*/
	while (!full(play_board)){ /*1 round in game*/
		printGameBoard(play_board);
		user_command = "";
		fgets(user_command,1024,stdin); /*get user command*/
		parsed_command = ParseCommand(user_command);
		execute(parsed_command,solved_board,play_board);
	}
	return(0);
}
