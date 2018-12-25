/*
 * MainAux.h
 *
 *  Created on: Dec 24, 2018
 *      Author: Roy Darnell
 */

#ifndef MAINAUX_H_
#define MAINAUX_H_

void copyBoard(int[9][9][2],int[9][9][2]);
int getHintsAmount();
int isLegalNumber(char*);
void printGameBoard(int[9][9][2]);
void resetBoard(int[9][9][2]);

#endif /* MAINAUX_H_ */
