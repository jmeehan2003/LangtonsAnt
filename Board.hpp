#ifndef BOARD_HPP 
#define BOARD_HPP

#include <iostream>

class Board {
private:
	int rows = 0;
	int cols = 0;
	class Ant;
	char **antBoard;
	char currentColor = ' ';

public:
	Board();
	Board(int arow, int acol);
	void printBoard();
	void setRows(int);
	void setCols(int);
	int getRows();
	int getCols();
	void placeAnt(int, int);
	char moveAnt(int row, int col, char orientation, char color);
	char getCurrentColor() { return currentColor; };
	void setCurrentColor(char color) { currentColor = color; };
	char getColor(int row, int col);
	~Board();
};

#endif 


