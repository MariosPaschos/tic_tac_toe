#include "Player.h"


Player::Player(char sign, const vector<vector<Cell> > &board) : sign(sign), board(board), SIZE(board.size()), hasPlayed(false) {}

const vector<vector<Cell> > &Player::getBoard() const {
    return this->board;
}

char Player::getSign() const {
    return this->sign;
}

const vector<Cell> Player::getAvailableMoves() const {
    vector<Cell> moves;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j].isEmpty()){
                moves.push_back(board[i][j]);
            }
        }
    }
    return moves;
}





