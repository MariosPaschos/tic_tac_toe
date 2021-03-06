#include "Utils.h"

#include <iomanip>


namespace utils {

    // Creates a square board of a given size
    vector<vector<Cell> > create2DBoard(size_t SIZE) {

        vector<vector<Cell> > board(SIZE, vector<Cell>(SIZE, Cell()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                board[i][j] = Cell(i, j);
            }
        }
        return board;
    }

    // Reset a 2D board to the default tic tac toe board configuration
    void resetBoard(vector<vector<Cell> > &board) {

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                board[i][j].setSign('_');
            }
        }
    }

    // Displays the 2D board on the screen
    // For resizable border alignment the formula is:   (board_size * 3) + (board_size + 3)
    void showBoard(const vector<vector<Cell> > &board) {
        int size = static_cast<int >(board.size());

        cout <<setfill('-') << setw(size * 3 + (size + 3)) << "-" << endl;
        for (int i = 0; i < board.size(); ++i) {
            cout << " | ";
            for (int j = 0; j < board.size(); ++j) {
                cout << board[i][j].getSign() << " | ";
            }
            cout << endl << setfill('-') << setw(size * 3 + (size + 3)) << "-" << endl;
        }
        cout << endl;
    }

    bool isBoardFull(const vector<vector<Cell> > &board){
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j].isEmpty()){
                    return false;
                }
            }
        }
        return true;
    }

    char checkRows(const vector<vector<Cell> > &board) {

        size_t count = 0;
        for (size_t i = 0; i < board.size(); ++i) {
            char sign = board[i][0].getSign();   // The first cell of each row is the pivot element
            count = 0;
            for (size_t j = 0; j < board.size(); ++j) {
                if (board[i][j].getSign() == sign){
                    count++;
                }
            }
            if (count == board.size() && (sign != '_')){
                return sign;
            }
        }
        return 'N';
    }

    char checkColumns(const vector<vector<Cell> > &board) {

        size_t count = 0;
        for (size_t j = 0; j < board.size(); ++j) {
            char sign = board[0][j].getSign();   // The first cell of each column is the pivot element
            count = 0;
            for (size_t i = 0; i < board.size(); ++i) {
                if (board[i][j].getSign() == sign){
                    count++;
                }
            }
            if (count == board.size() && (sign != '_')){
                return sign;
            }
        }
        return 'N';
    }

    char checkFstDiagonal(const vector<vector<Cell> > &board) {

        size_t count = 0;
        char sign = board[0][0].getSign();   // Check the cells of the main diagonal

        for (size_t i = 0; i < board.size(); ++i) {
            if (board[i][i].getSign() == sign){
                count++;
            } else {
                break;
            }
        }
        if (count == board.size() && (sign != '_')){
            return sign;
        }
        else return 'N';
    }

    char checkSndDiagonal(const vector<vector<Cell> > &board){

        int count = 0;
        char sign = board[0][board.size() - 1].getSign();

        for (int j = (static_cast<int>(board.size()) - 1); j > -1; j--) {
            if (board[(board.size() - 1) - j][j].getSign() == sign) {
                count++;
            } else{
                break;
            }
        }
        if (count == board.size() && (sign != '_')){
            return sign;
        }
        else return 'N';
    }

    char checkBoardForWinner(const vector<vector<Cell> > &board){

        // Check the rows
        char row = checkRows(board);
        if (row != 'N') return row;

        // Check the columns
        char col = checkColumns(board);
        if (col != 'N') return col;

        //Check main diagonal
        char fstDiag = checkFstDiagonal(board);
        if (fstDiag != 'N') return fstDiag;

        // Check secondary diagonal
        char sndDiag = checkSndDiagonal(board);
        if (sndDiag != 'N') return sndDiag;

        if (isBoardFull(board)) return 'D';     // If not tic tac toe was found and the board is full return 'D' (Draw)

        // If not tic tac toe was found and the board is not full yet return 'N' (None wins)
        return 'N';
    }

}
