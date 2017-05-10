/*
* Queens.cpp
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#include "Queen.h"

Queen::Queen() : row(0), col(0) {
	//default initalizer to start queen at top left
}

Queen::Queen(int inRow, int inCol) : row(inRow), col(inCol) {
	//specified starting row & column.
}

Queen::~Queen() {

}

/**@return Col number.**/
int Queen::getCol() const {
	return col;
}

/**@return Row number.**/
int Queen::getRow() const {
	return row;
}
/**Moves queen to next row.**/
void Queen::nextRow() {
	const int BOARD_SIZE = 8;
	if (row < BOARD_SIZE)  //max rows & columns are 8;;;;     [ 0 1 2 3 4 5 6 7 ]
		++row;	   // eg. (0,0) [ Q 0 0 0 0 0 0 0 ] --> (0,1) [ 0 Q 0 0 0 0 0 0 ]
	else cout << "unsuccessful, Queen is on the last row. BACKTRACK NEEDED.";
}

/** Sees whether the queen is under attack by another queen.
@return True if another queen is in the same row or the same
diagonal; otherwise, returns false. */
bool Queen::isUnderAttack() const {

	//access pointer, check if it contains queens in the same row, column, or diagonal
	//use get numQueens and getQueen to find the queens
	//check current queen against them and see if theres issue
	//if issue return false else true

	for(int i =0; i<boardPtr->getNumQueens(); i++){
		//find queens already on the board;
		Queen* q = boardPtr->getQueen(i);
		//save current col and row
		double c=(double) q->getCol();
		double r=(double q->getRow();
		//find slope between added queen and queen on board
		double slope = (c-col)/(r-row);
		

		if (c==col||r==row||slope==1||slope==-1)
			return false;
		
	}
	//if no duplicates 
	return true;
	/*//we know a queen is under attack when it is in the same row or column..as well as diagonals.
	cout << "Current row: " << getRow() << endl;
	cout << "Current col: " << getCol() << endl;
	
	//if current queen's row or col is equal to one of the 
	//row or cols of the vector queen, queen is under attack.
	//check row - col for left diagonal (downward diagonal?)
	//check row + col for right diagonal (upward diagonal?)
	if (getCol() == queen.getCol() || getRow() == queen.getRow() || (getRow() - getCol()) == (queen.getRow() - queen.getCol())
		|| (getRow() + getCol()) == (queen.getRow + queen.getCol()))
		return true;
	else */
	//	return false; //FALSE when placed queen is NOT under attack!
}

/** Saves a pointer to the board for all queens. */
void Queen::setBoard(const Board* bPtr) { 
	 const Board* boardPtr = bPtr; //Note: const Board* Queen::boardPtr = bPtr is used if not part of queen class
}

