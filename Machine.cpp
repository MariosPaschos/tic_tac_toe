#include "Machine.h"

Machine::Machine(char sign, const vector<vector<Cell> > &board) : Player (sign, board){}


const Cell Machine::makeMove() {

    size_t num_of_moves = Player::getAvailableMoves().size();

    vector<Cell> emptyCells = getAvailableMoves();

    std::random_device rd;
    std::mt19937 mt(rd());      // Initialize random seed
    std::uniform_int_distribution<int> dist(0, int(num_of_moves)-1);
    int index = dist(mt);

    return getAvailableMoves()[index];
}



