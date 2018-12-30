/*
 * Game.h
 *
 *  Created on: Dec 24, 2018
 *      Author: Roy Darnell
 */

#ifndef GAME_H_
#define GAME_H_

void execute(int[],int[9][9][2],int[9][9][2],int[1]);
void hint(int[9][9][2],int,int);
int isFull(int[9][9][2]);
void restart(int[9][9][2],int[9][9][2]);
void set(int[9][9][2],int,int,int);
void validate(int[9][9][2],int[9][9][2]);

#endif /* GAME_H_ */
