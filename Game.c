/*
 * Game.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

int full(int game_board [9][9][2]){
	/*checks if a board is full of numbers*/
	int full = 1;
	/*for x*/
	/*for y*/
	/*if 1 > cell > 9*/
	/*full = 0 and break*/
	return full;
}

void execute(int parsed_command[4],int solved_board[9][9][2],int play_board[9][9][2]){
	int command = parsed_command[0]; /*[command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit*/
	switch(command){
	case -1:
		/*set*/
		/*print Error:invalid command*/
		break;
	case 1:
		/*set*/
		/*change in play_board, in location <X,Y> to value Z*/
		break;
	case 2:
		/*hint*/
		/*go to slved_baord at location <X,Y> and print Z*/
		break;
	case 3:
		/*validate*/

		break;
	case 4:
		/*restart*/
		break;
	case 5:
		/*exit*/
		break;
	}
}
