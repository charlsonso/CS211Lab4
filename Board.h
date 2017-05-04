#ifndef _BOARD
#define _BOARD
#include "Queen.h"
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

static const int BOARD_SIZE=8;
class Board{
	private:
		vector<Queen*> queens;
		bool isQueen(int inRow, int inCol) const;
		const placeQueens(Queen* queenPtr);
		void removeQueen();
		void setQueen(const Queen* queenPtr);
	public:
		Board();
		~Board();
		void clear();
		void display() const;
		void doEightQueens();
		int getNumQueens();
		const Queen* getQueen(int index) const;		

	bool Board::placequeens(Queen* queenPtr){
		if (queenPtr->getCol()>=BOARD_SIZE){
			delete queenPtr;
			return true;
		}
		bool isQueenPlace=false;
		while(!isQueenPlace && queenPtr->getRow()<BOARD_SIZE){
			if (queenPtr->isUnderAttack()){
				queenPtr->nextRow();
			}
			else{
				setQueen(queenPtr);
				Queen* newQueenPtr = new Queen(0,queenPtr->getCol()+1);
				isQueenPlace = placeQueens(newQueenPtr);
				if(!isQueenPlace){
					delete newQueenPtr;
					removeQueen();
					queenPtr->nextRow();
				}
			}
		}
		return isQueenPlaced;
	}

};
#endif