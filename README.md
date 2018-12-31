# Soduko
Soduko project in C

*SoloWork: my partner is doing a "recourse" so she is only obliged to hand over the final project, therefore I hand it over solo.

*For graphic overviews:
Program flow: https://atlas.mindmup.com/roydarnell/initialization/index.html
Functions interaction: https://atlas.mindmup.com/roydarnell/soduko_documentation/index.html

*Github link: https://github.com/ristllin/Soduko

*Program Flow:
1. initialization
	1.a get parameters for game 
	1.b initialize game (create board and solve it)	
2. while game not over:
	2.a show board if it has been changed
	2.b get command from user
	2.c parse it to check legality
	2.d execute command
		> set - change board if legal
		> hint - give <x,y> value from preproduced solved board
		> exit - terminate program, no memory allocations are made in program, so nothing to free
		> validate - reset current solution and try to solve current board
		> restart - call initialization process

*Functions description (by modules:):
1. main:
	main: handles general game flow as described above.
2. Intialization:
	initialize: * 1. asks user for amount of hints * 2. generates a puzzle with that amount of hints * 3. saving the boards at the references given*/
3. Game:
	LegalInput: gets a parsed command and amount of variables to be checked, makes sure input is legal
	set: set play board at location x,y to value z if legal
	hint: returns value z in location <x,y> of given board
	execute: gets a parsed command and executes the relevant command according to input: [command,x,y,z] where '-1'-error, '1'-set, '2'-hint, '3'-validate, '4'-restart, '5'-exit
4. MainAux:
	printGameBoard
	getHintsAmount: gets a legal number from user
	resetBoard: resets matrix to 0 in value field and in fixed indicator field.
	isLegalNumber
	clearUnfixed: goes over given matrix and resets cell that isn't marked as fixed in fixed field.
	fixNCells: randomly changes additional N cells to fixed state.
	sum_array: returns the sum of the values in the array cells
	chooseRandomOption - returns index of a random valid option from a boolean array
	copyBoard
	chooseNextOption - returns the lowest index of a true option in a boolean array
	findFirstZero - goes over a matrix and returns the x,y of the first non zero value
	clearFromPos - clears a matrix (values to zero) from a given location <x,y>
	isFull - if all values in matrix != 0
5. Parser:
	parse_command: gets user input, ouputs a legal parsed command from user input
	parseInt: turns legal user inputs into integers.
	compareInput: compares userinputs to a given string.
6. solver:
	legalOptions: returns a boolean array of the legal sudoku values options for a specific cell by index
	solver: gets a partially played sudoku board, copies it and solves it with recursive solver
	recursiveSolver: solves a given sudoku board.
	randomizedBackTracking - randomly creates a legal sudoku board using a broodForce backTracking algo
	PuzzleGenerator - gets 2 boards, resets them, generates a random solution, fixes n cells in it and deletes the rest, resulting in 1 solved board and 1 partially empty solvable board.
