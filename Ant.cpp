#include "Ant.hpp"

#include <iostream>
using std::cout;
using std::endl;

Ant::Ant() {
	setAntRow(rowCount / 2);
	setAntCol(colCount / 2);
	setOrientation('r');
}

Ant::Ant(int row, int col) {
	setOrientation('r');
	setAntRow(row);
	setAntCol(col);
}

void Ant::setRowCount(int rows) {
	rowCount = rows;
}

void Ant::setColCount(int cols) {
	colCount = cols;
}

void Ant::setOrientation(char o) {
	if (o != 'r' && o != 'l' && o != 'u' && o != 'd')
		cout << "There was an Error: Invalid Orientation" << endl;
	else
		this->orientation = o;
}

char Ant::getOrientation() {
	return this->orientation;
}

void Ant::setAntRow(int row) {
	this->antRow = row;
}

void Ant::setAntCol(int col) {
	this->antCol = col;
}

int Ant::getAntRow() {
	return this->antRow;
}

int Ant::getAntCol() {
	return this->antCol;
}

void Ant::moveAnt() {
	char x = getOrientation();

	if (x == 'r') {
		if ((antCol + 2) >= colCount) {
			antCol = 1;
		}
		else
			antCol += 1;
	}

	else if (x == 'l') {
		if ((antCol - 1) <= 0) {
			antCol = colCount - 2;
		}
		else
			antCol -= 1;
	}

	else if (x == 'u') {
		if ((antRow - 1) <= 0) {
			antRow = rowCount - 2;
		}
		else
			antRow -= 1;
	}
	else if (x == 'd') {
		if ((antRow + 2) >= rowCount) {
			antRow = 1;
		}
		else
			antRow += 1;
	}

}