/*
 * CS/IS 211
 * Lab #4 - Implemenation of Eight Queens
 * Group Member(s): Amy Jiang, Aaron Lim, Charlson So
 */

#include <iostream>
#include "Queen.h"
using namespace std;

Queen::Queen(): row(1), col(1) {
	//default initalizer to start queen at top left.
}

Queen::Queen(int inRow, int inCol) : row(inRow), col(inCol) {
	//specified starting row & column.
}

Queen::~Queen() {

}

int Queen::getCol() const {
	return col;
}

int Queen::getRow() const {
	return row;
}

bool Queen::nextRow() {
	if (row < 8) { //max rows & columns are 8 
		row++; 
		return true; 
	}
	return false; //if already at 8 do not increment
}

bool Queen::isUnderAttack(vector<Queen> queen) { 
	//we know a queen is under attack when it is in the same row or column..as well as diagonals.
	for (int i = 0; i < queen.size(); i++) {
		if (getCol() == queen[i].getCol() || getRow() == queen[i].getRow())
			return true; //if current queen's row or col is equal to one of the row or 
						//cols of the vector queen, queen is under attack.
						//need to consider diagonals???
	}
	return false;

}


