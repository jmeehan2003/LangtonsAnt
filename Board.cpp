#include "Board.hpp"

#include <iostream>
using std::cout;
using std::endl;

Board::Board() {
	rows = 0;
	cols = 0;
}

Board::Board(int arow, int acol) {
	setRows(arow);
	setCols(acol);
	antBoard = new char*[rows];
	for (int i = 0; i < rows; i++)
		antBoard[i] = new char[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == 0 || i == rows - 1) {
				antBoard[i][j] = '-';
			}
			else if (j == 0 || j == cols - 1) {
				antBoard[i][j] = '|';
			}
			else
				antBoard[i][j] = ' ';
		}
	}
}

void Board::printBoard() {
	for (int i = 0; i < rows; i++) {
		cout << "    ";
		for (int j = 0; j < cols; j++)
			cout << antBoard[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void Board::setRows(int arows) {
	rows = arows;
}

void Board::setCols(int acols) {
	cols = acols;
}

int Board::getCols() {
	return cols;
}

int Board::getRows() {
	return rows;
}

void Board::placeAnt(int antRow, int antCol)
{
	antBoard[antRow][antCol] = '*';
}

char Board::moveAnt(int antRow, int antCol, char orientation, char color) {
	if (color == ' ') {
		antBoard[antRow][antCol] = '#';
		if (orientation == 'r')
			orientation = 'd';
		else if (orientation == 'd')
			orientation = 'l';
		else if (orientation == 'l')
			orientation = 'u';
		else if (orientation == 'u')
			orientation = 'r';
		else
			cout << "Error: Invalid orientation value";
		return orientation;
	}
	else if (color == '#') {
		antBoard[antRow][antCol] = ' ';
		if (orientation == 'r')
			orientation = 'u';
		else if (orientation == 'd')
			orientation = 'r';
		else if (orientation == 'l')
			orientation = 'd';
		else if (orientation == 'u')
			orientation = 'l';
		else
			cout << "Error: Invalid orientation value";
		return orientation;
	}
	else {
		cout << "Error: Invalid color value [" << color << "] at " << antRow << ", " << antCol << endl;
		exit(-1);
	}
}

char Board::getColor(int row, int col)
{
	char color = antBoard[row][col];
	return color;
}

Board::~Board() {
	for (int i=0; i < rows; i++)
		delete [] antBoard[i];
	delete [] antBoard;

}



