#include "Board.hpp"
#include "Ant.hpp"
#include "mainFunctions.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

struct userOptions {
	int rowCount = 10;
	int colCount = 10;
	int steps = 50;
	int antRow = 5;
	int antCol = 5;
	char or = 'l';
} myUser;
int startMenu();
void optionsMenu();
void displayMenu();
Ant configAnt(userOptions);
Board configBoard(userOptions, int, int);

int main() {
	int play = startMenu();
	while (play) {
		optionsMenu();

		//set up Ant
		class Ant ant = configAnt(myUser);

		//set up Board and print initial Board
		class Board antboard = configBoard(myUser, ant.getAntRow(), ant.getAntCol());

		//move user defined number of steps
		int count = 0;
		while (count < myUser.steps) {
			cout << "Step#: " << (count + 1) << endl;
			char color = antboard.getCurrentColor();

			//change color of square underneath ant, rotate ant, and move forward
			ant.setOrientation(antboard.moveAnt(ant.getAntRow(), ant.getAntCol(), ant.getOrientation() , color));
			ant.moveAnt();

			//get color that will be underneath ant, store it, and place ant in new location
			color = antboard.getColor(ant.getAntRow(), ant.getAntCol());
			antboard.setCurrentColor(color);
			antboard.placeAnt(ant.getAntRow(), ant.getAntCol());

			//the step is complete, print board and increment count.
			antboard.printBoard();
			count++;
		}

		cout << endl << "Great news! The simulation has completed successfully." << endl;
		//reset number of rows to user values for menu (due to borders)
		myUser.rowCount -= 2;
		myUser.colCount -= 2;

		play = startMenu();
	}

	return 0;
}

int startMenu() {
	int val;
	cout << "Please select one of the following two options:" << endl << endl;
	cout << "   1. Start Langton's Ant Simulation" << endl;
	cout << "   2. Quit" << endl << endl;
	cout << "Press 1 to Start or 2 to Quit: ";
	cin >> val;
	while (cin.fail()) {
		cout << "Error: You did not enter an integer.  Please enter either 1 or 2." << endl;
		cout << "Please select one of the following two options:" << endl << endl;
		cout << "   1. Start Langton's Ant Simulation" << endl;
		cout << "   2. Quit" << endl << endl;
		cout << "Press 1 to Start or 2 to Quit: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> val;
	}
	while (val != 1 && val != 2) {
		cout << "Error: Invalid number entered.  Please enter only either 1 or 2." << endl;
		cout << "Please select one of the following two options:" << endl << endl;
		cout << "   1. Start Langton's Ant Simulation" << endl;
		cout << "   2. Quit" << endl << endl;
		cout << "Press 1 to Start or 2 to Quit: ";
		cin >> val;
	}

	if (val == 1)
		return 1;
	else {
		cout << "Exiting the program. G'day mate!" << endl;
		return 0;
	}
}

void optionsMenu() {
	int opt;
	displayMenu();

	bool accepted = false;
	while (!accepted) {
		cin.clear();
		cin.ignore(256, '\n');
		cin >> opt;

		while (cin.fail() || opt < 1 || opt > 7) {
			cout << "You must select one of the seven options.  Please enter the number of your selection: ";
			cin >> opt;
		}

		if (opt == 1) {
			cout << "Select the number of rows for the board (min: 4 max: 100): ";
			cin >> myUser.rowCount;
			while (cin.fail() || myUser.rowCount < 4 || myUser.rowCount > 100 || myUser.rowCount < myUser.antRow) {
				if (myUser.rowCount < myUser.antRow) {
					cout << "Error: This would place the ant of bounds. Please make the number of rows at least " << myUser.antRow << endl;
					cout << "Select the number of rows for the board (max: 100): ";
				}
				else {
					cout << "Error: You entered an invalid number" << endl;
					cout << "Select the number of rows for the board (min: 4 max: 100): ";
				}
				cin.clear();
				cin.ignore(256, '\n');
				cin >> myUser.rowCount;
			}
			displayMenu();
		}
		else if (opt == 2) {
			cout << "Select the number of columns for the board (min: 4 max: 100): ";
			cin >> myUser.colCount;
			while (cin.fail() || myUser.colCount < 4 || myUser.colCount > 100 || myUser.colCount < myUser.antCol) {
				if (myUser.colCount < myUser.antCol) {
					cout << "Error: This would place the ant of bounds. Please make the number of columns at least " << myUser.antCol << endl;
					cout << "Select the number of rows for the board (max: 100): ";
				}
				else {
					cout << "Error: You entered an invalid number" << endl;
					cout << "Select the number of columns for the board (min: 4 max: 100): ";
				}
				cin.clear();
				cin.ignore(256, '\n');
				cin >> myUser.colCount;
			}
			displayMenu();
		}
		else if (opt == 3) {
			cout << "Please select a starting row for the ant between 1 and " << myUser.rowCount << ": ";
			cin >> myUser.antRow;
			while (cin.fail() || myUser.antRow < 1 || myUser.antRow > myUser.rowCount) {
				cout << "Error: The starting row must be inside the board." << endl;
				cout << "Please select a starting row for the ant between 1 and " << myUser.rowCount << ": ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> myUser.antRow;
			}
			displayMenu();
		}
		else if (opt == 4) {
			cout << "Please select a starting column for the ant between 1 and " << myUser.colCount << ": ";
			cin >> myUser.antCol;
			while (cin.fail() || myUser.antCol < 1 || myUser.antCol > myUser.colCount) {
				cout << "Error: The starting row must be inside the board." << endl;
				cout << "Please select a starting column for the ant between 1 and " << myUser.colCount << ": ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> myUser.antCol;
			}
			displayMenu();
		}
		else if (opt == 5) {
			cout << "Select the number of steps during simulation (min: 1 max: 200): ";
			cin >> myUser.steps;
			while (cin.fail() || myUser.steps < 1 || myUser.steps > 200) {
				cout << "Error: You entered an invalid number" << endl;
				cout << "Select the number of steps during simulation (min: 1 max: 200): ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> myUser.steps;
			}
			displayMenu();
		}
		else if (opt == 6) {
			cout << "Enter the ant's starting orientation.  Enter 'l' for left, 'd' for down, 'u' for up, or 'r' for right: ";
			cin >> myUser. or ;
			while (cin.fail() || (myUser.or != 'u' && myUser.or !='d' && myUser.or !='l' && myUser.or != 'r')) {
				cout << "Error: You must enter only either 'u', 'd', 'l', 'r'." << endl;
				cout << "Enter the ant's starting orientation.  Enter 'l' for left, 'd' for down, 'u' for up, or 'r' for right: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> myUser. or ;
			}
			displayMenu();
		}
		else
			accepted = true;
	}

	//to create board outline
	myUser.rowCount += 2;
	myUser.colCount += 2;
}

void displayMenu() {
	//convert or char values to strings
	std::string ort;
	switch (myUser. or ) {
	case 'r':
		ort = "right";
		break;
	case 'l':
		ort = "left";
		break;
	case 'd':
		ort = "down";
		break;
	case 'u':
		ort = "up";
		break;
	}

	//display menu
	cout << endl << endl << endl << endl << endl << endl;
	cout << endl << "Welcome to James's Langton's Ant Simulation." << endl;
	cout << "You can change the settings below or accept the current options" << endl << endl;
	cout << "User Options                                           Value" << endl;
	cout << "1. Change the board's number of Rows:                    " << myUser.rowCount << endl;
	cout << "2. Change the board's number of Columns:                 " << myUser.colCount << endl;
	cout << "3. Change ant's row starting location:                   " << myUser.antRow << endl;
	cout << "4. Change the ant's column starting location:            " << myUser.antCol << endl;
	cout << "5. Change the number of steps for the simulation:        " << myUser.steps << endl;
	cout << "6. Change ant's default orientation:                   " << ort << endl;
	cout << "7. Accept current options" << endl << endl;
	cout << "Enter the number of your option selection: ";
}

Ant configAnt(userOptions myUser) {
	class Ant ant(myUser.antRow, myUser.antCol);
	ant.setRowCount(myUser.rowCount);
	ant.setColCount(myUser.colCount);
	ant.setOrientation(myUser. or );
	return ant;
}

Board configBoard(userOptions myUser, int row, int col) {
	Board antboard(myUser.rowCount, myUser.colCount);
	antboard.placeAnt(row, col);
	cout << endl << "Step#: 0" << endl;
	antboard.printBoard();
	return antboard;
}



