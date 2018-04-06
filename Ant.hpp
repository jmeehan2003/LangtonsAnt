#ifndef ANT_HPP 
#define ANT_HPP

class Ant {
private:
	int rowCount;
	int colCount;
	int antRow;
	int antCol;
	char orientation;

public:
	Ant();
	Ant(int row, int col);
	void setOrientation(char);
	void setRowCount(int);
	void setColCount(int);
	void setAntRow(int);
	void setAntCol(int);
	char getOrientation();
	int getAntRow();
	int getAntCol();
	void moveAnt();
};

#endif
