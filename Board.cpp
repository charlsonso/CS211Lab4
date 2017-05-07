/*
* Board.cpp
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#include <iostream>
#include <vector>
#include "Board.h"
using namespace std;

/** Supplies the Queen class with a pointer to the board. */
Board::Board() {
	
}

/** Clears the board and removes pointer from queens. */
Board::~Board() {
	clear();
}

/** Attempts to place queens on board, starting with the designated queen. */
bool Board::placeQueens(Queen* queenPtr) {
	if (queenPtr->getCol() >= BOARD_SIZE) {
		delete queenPtr;
		return true;
	}
	bool isQueenPlaced = false;

	while (!isQueenPlaced && queenPtr->getRow()<BOARD_SIZE) {
		if (queenPtr->isUnderAttack()) {
			queenPtr->nextRow();
		}
		else {
			setQueen(queenPtr);
			Queen* newQueenPtr = new Queen(0, queenPtr->getCol() + 1);
			isQueenPlaced = placeQueens(newQueenPtr);
			if (!isQueenPlaced) {
				delete newQueenPtr;
				removeQueen();
				queenPtr->nextRow();
			}
		}
	}
	return isQueenPlaced;
}

/** Initiates the Eight Queens problem. */
void Board::doEightQueens() {
	placeQueens(new Queen);
}

/** Clears board. */
void Board::clear() {
	if (!queens.empty()) {
		for (int i = 0; i < (int)queens.size(); i++) 
			delete queens[i];	
	}
}

/** Removes the last queen from the board, but does not deallocate it. */
void Board::removeQueen() {
	queens.pop_back();
}

/** Sees whether a queen exists in position (inRow, inCol). */
bool Board::isQueen(int row, int col) const {
	bool isOnBoard = false;
	for (int i = 0; i < (int)queens.size(); i++) {
		if (queens[i]->getRow() == row) {
			if (queens[i]->getCol() == col) {
				isOnBoard = true;
			}
		}
	}
	return isOnBoard;
}

/** Places a queen on the board. */
void Board::setQueen(const Queen* queenPtr) {	
	//queens.push_back(queenPtr);
}


/** Displays board. */
void Board::display() const {
	//char chessArray[BOARD_SIZE][BOARD_SIZE];
	for (int row = 0; row < BOARD_SIZE; row++) {
		for(int col = 0; col < BOARD_SIZE; col++) {
			cout << " + ";
		}
		cout << endl;
	}

}

/** @return The number of queens on the board. */
int Board::getNumQueens() {
	return queens.size();
}

/** @return A pointer to the queen at the designated index. */
const Queen* Board::getQueen(int index) const {
	return queens[index];
}