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
	fgets(user_command,1024,stdin);
	printf("echo: %s",user_command);
	/*Initialize(play_board,solved_board);*/
	/*while TRUE*/
		/*printGameBoard()*/
		/*user_command = getUserCommand()*/
		/*parsed_command = ParseCommand(userCommand)*/
		/*execute(parsed_command,solved_baord,play_baord)*/
	return(0);
}
