/*
* test.cpp
* CS/IS 211
* Lab #4 - Implemenation of Eight Queens
* Group Member(s): Amy Jiang, Aaron Lim, Charlson So
*/
#include <iostream>
#include <vector>
#include "Queen.h"
#include "Board.h"
using namespace std;
int main() {

	Board board;
	board.doEightQueens();
	board.display();

	system("PAUSE");
	return 0;
}