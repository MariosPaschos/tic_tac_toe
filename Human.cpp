#include "Human.h"

Human::Human(char sign, const vector<vector<Cell> > &board) : Player (sign, board){}


const Cell Human::makeMove() {
    int x;
    int y;

    try {
        cout << "Enter x-coordinate: " << endl;
        x = userInput();
        cout << "Enter y-coordinate: " << endl;
        y = userInput();
    }
    catch (string &error) {
        clog << "Error: " << error << endl;
        return Cell(-1, -1);
    }

    return Cell(x, y);
}

int Human::userInput() {
    int i;
    while (true){
        try {
            cout << "Select a cell to make a move on: " << endl;
            cin >> i;
            if (cin.fail()) {    // user didn't input a number
                cin.clear();    // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                continue;
            }
            else {
                return i;
            }
        }
        catch (string &e){
            cout << "Error in input: " << e << endl;
        }
    }
}



