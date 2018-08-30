#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H

#include "Cell.h"
#include "Utils.h"

#include <random>
#include <vector>
#include <time.h>

using namespace std;


class Player {
public:
    explicit Player(char sign, const vector<vector<Cell> > &board);
    virtual ~Player() = default;
    virtual const Cell makeMove() = 0;
    char getSign() const;
    const vector<vector<Cell> > &getBoard() const ;
    const vector<Cell> getAvailableMoves() const;
    bool hasPlayed;



private:
    char sign;
    const vector<vector<Cell> > &board;
    size_t SIZE;

    // Private and without implementation to avoid duplicate Player instances - each player is unique
    Player(const Player &player);
    Player &operator=(const Player &player);
};


#endif //TIC_TAC_TOE_PLAYER_H
