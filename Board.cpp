

#include "Board.h"

Board::Board(const vector<vector<Cell> > &board) : board(board), state(0) {}

Board::~Board() {
    this->board.clear();
}

int Board::getState() const {
    return state;
}

void Board::setState(int state) {
    this->state = state;
}

