/*
 * Game.h
 *
 *  Created on: Dec 24, 2018
 *      Author: Roy Darnell
 */

#ifndef GAME_H_
#define GAME_H_

int legalInput(int[4],int);
void execute(int[4],int[9][9][2],int[9][9][2],int[1]);
void set(int[4],int[9][9][2],int[1]);
void hint(int[4],int[9][9][2]);

#endif /* GAME_H_ */
