#include "Human.h"

Human::Human(char sign, const vector<vector<Cell> > &board) : Player (sign, board){}


const Cell Human::makeMove() {
    int x = -1;
    int y = -1;
    cout << "Select a cell to make a move on: " << endl;
    try {
        cout << "Enter x-coordinate: " << endl;
        cin >> x;
        cout << "Enter y-coordinate: " << endl;
        cin >> y;

        return Cell(x, y);
    }
    catch (int error) {
        clog << "Error: " + to_string(error) << endl;
    }
}



