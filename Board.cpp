#include<iostream>
#include "Board.h"
using namespace std;

Board::Board() {

}

Board::~Board() {

}

bool Board::placeQueens(Queen queen, int row, int column) {
	if (column > BOARD_SIZE) {
		//problem is sovled
	}
	else {
		while (/*unconsidered squares exist in the given col and the problem is unsolved*/ ){ 
		//find the next square in the given col that is not under attack by the earlier column
			if (/*such square exists*/) {
				//place a queen in the square

				//try next col
				if (!placeQueens(queen, firstRow, column + 1)) {
					//delete the new queen
					//move last queen that was placed on the board to 
					//the next row in that col
				}
				else {
					//Delete new queen 
					return true;
				}
			}
		}
	}
}

void Board::doEightQueens(Queen queen) {
	placeQueens(queen, queen.getRow(), queen.getCol());
}

void Board::displayEightQueens() {
	//output 2D array with solved Eight Queens solutions
}
