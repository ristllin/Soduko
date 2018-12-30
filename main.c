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
#include "Game.h"
#include "Initialization.h"
#include "MainAux.h"
#include "Parser.h"
#include "Solver.h"

/*Global variables:*/
int game_status = 0; /*0=initialization, 1= Game on 2=Game over*/
int solved_board[9][9][2] = {{{0}}}; /*initialized to an empty soduko borad, each cell is a tuple (fixed/not-fixed,value)*/
int play_board[9][9][2] = {{{0}}};
int show_flag[1] = {1};
char empty[1] = " ";
char* user_command;
char* pos;
int parsed_command[4] =  {0}; /*[command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit*/
/*---------Main:----------*/
int main(int argc, char *argv[]){
	if (argc == argc) {};
	SP_BUFF_SET(); /*Windows buffer auto print flush*/
	srand(atoi(argv[1])); /*randomizing by preset seed*/
	initialize(play_board,solved_board);/*generates new play board and solves it on the solved board*/
	getchar();
	while (!isFull(play_board)){ /*1 round in game, puzzle isn't complete*/
		if (show_flag[0]){
			printGameBoard(play_board);
		}
		show_flag[0] = 0;
		user_command = empty;
		fgets(user_command,1024,stdin);
		if ((pos=strchr(user_command, '\n')) != NULL){
		    *pos = '\0';
		}
		parseCommand(user_command, parsed_command);
		printf("user_command in main: [%d,%d,%d,%d]\n",parsed_command[1],parsed_command[2],parsed_command[3],parsed_command[4]); /*debug*/
		execute(parsed_command,solved_board,play_board,show_flag);
	}
	return(0);
}
