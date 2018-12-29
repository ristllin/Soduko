/*
 * Parser.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Roy Darnell
 */

/*Libraries:*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Modules*/

int parseInt(char *userInput){
	int result = 0;
	char *p = userInput;
	int length = 0;
	while(*p != ' ' && *p != '\0'){ /*check var length and validity in user input, with a different pointer*/
		if (*p > '9' || *p < '0'){ /*illegal number*/
			return -1;
		}
		result = (result*10) + (*p-'0');
		length++;
		++p;
	}
	/*check length and validity*/
	/*cast to integer*/
	return result;
}

int compareInput(char* user_input, char command[]){
	int length = 0;
	int i = 0;
	char* p1;
	p1 = user_input;
	/*function description: gets pointer to the userInput and a char array, compares length, if diff returns false, if same compares each char and returns true or false*/
	while(*p1 != ' ' && *p1 != '\0'){ /*check var size in user input, with a different pointer*/
		length++;
		++p1;
	}
	if (strlen(command) != length){ /*check lengths match*/
		return 0;
	}
	p1 = user_input;
	for (i =0;i<length;i++){ /*check content matches*/
		if (*p1 != command[i]){
			return 0;
		}
		++p1;
	}
	return 1;
}

void parseCommand(char* userInput, int parsed_command[4]){
	/*function description: gets string, returns int array [command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit, and x\y\z are ints*/
	/*Variables:*/
	int i = 1;
	int command = -1;
	parsed_command[1] = -1; parsed_command[2] = -1; parsed_command[3] = -1; parsed_command[4] = -1;/*reset*/
	char set[4] = "set\0", hint[5] = "hint\0", validate[9] = "validate\0", restart[8] = "restart\0", exit[5] = "exit\0";
//	printf("parseCommand got: %s\n",userInput);
	while (*userInput != '\0' && *userInput == ' '){++*userInput;} /*clean white spaces*/
	while (*userInput != '\0'){ /*until string finished, white spaces deleted after each variable*/
		if (i > 4){return;} /*count variables, extra variables aren't interesting*/
		if (i == 1){ /*parse commands*/
			/*while not space or end, count word length*/
			/*if length == command length, compare each char*/
			/**/
			if (compareInput(userInput,set)) {
				command = 1;
			} else if (compareInput(userInput,hint)) {
				command = 2;
			} else if (compareInput(userInput,validate)) {
				command = 3;
			} else if (compareInput(userInput,restart)) {
				command = 4;
			} else if (compareInput(userInput,exit)) {
				command = 5;
			} else {
				command = -1;
				return; //invalid option <<<>>>
			}
			while (*userInput != '\0' && *userInput != ' '){++userInput;} /*get to next variable*/
		} else { /*parse number*/
			command = parseInt(userInput);
//			printf("parsed num is:%d\n",command);
			while (*userInput != '\0' && *userInput != ' '){++userInput;} /*until number finished*/
		}
		parsed_command[i] = command;
		if (*userInput == ' '){ /*clean white spaces and count +1*/
			while (*userInput == ' '){++userInput;}
		}
		i++;
	}
}
