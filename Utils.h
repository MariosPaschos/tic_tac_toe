#ifndef TIC_TAC_TOE_UTILS_H
#define TIC_TAC_TOE_UTILS_H



#include "Cell.h"

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

namespace utils {

    vector<vector<Cell> > create2DBoard(size_t SIZE);
    void resetBoard(vector<vector<Cell> > &board);
    void showBoard(const vector<vector<Cell> > &board);
    bool isBoardFull(const vector<vector<Cell> > &board);

    char checkRows(const vector<vector<Cell> > &board);
    char checkColumns(const vector<vector<Cell> > &board);
    char checkFstDiagonal(const vector<vector<Cell> > &board);
    char checkSndDiagonal(const vector<vector<Cell> > &board);
    char checkBoardForWinner(const vector<vector<Cell> > &board);

};




#endif //TIC_TAC_TOE_UTILS_H
