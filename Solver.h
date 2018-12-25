/*
 * Solver.h
 *
 *  Created on: Dec 24, 2018
 *      Author: Roy Darnell
 */

#ifndef SOLVER_H_
#define SOLVER_H_

void legalOptions(int[9][9][2],int,int,int[9]);
void puzzleGenerator(int[9][9][2],int[9][9][2],int);
void recursiveSolver(int[9][9][2]);
void solver(int[9][9][2],int[9][9][2]);
void randomizedBacktracking(int[9][9][2],int[9][9][2]);

#endif /* SOLVER_H_ */
