/*
 * MainAux.h
 *
 *  Created on: Dec 24, 2018
 *      Author: Roy Darnell
 */

#ifndef MAINAUX_H_
#define MAINAUX_H_

void printGameBoard(int[9][9][2]);
int getHintsAmount();
void resetBoard(int[9][9][2]);
int isLegalNumber(char*);
void clearUnfixed(int[9][9][2]);
void fixNCells(int[9][9][2],int);
int sum_array(int a[], int);
int chooseRandomOption(int[],int);
void copyBoard(int[9][9][2],int[9][9][2]);
int chooseNextOption(int[],int);
void findFirstZero(int[9][9][2], int[2]);
void clearFromPos(int[9][9][2], int[2]);
int isFull(int[9][9][2]);

#endif /* MAINAUX_H_ */
