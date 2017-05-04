class Board;
class Queen{
	public:
		Queen();
		Queen(int inRow, int inCol);
		int getCol() const;
		int getRow() const;
		void nextRow();
		bool isUnderAttack() const;
		static void setBoard(const Board* bPtr);
	private:
		int row;
		int col;
		static const Board* boardPtr;

	Queen(){
		row =1;
		col = 1;
	}
	Queen(int inRow,int inCol){
		row = inRow;
		col = inCol;
	}
	
};