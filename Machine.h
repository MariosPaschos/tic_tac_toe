#ifndef TIC_TAC_TOE_MACHINE_H
#define TIC_TAC_TOE_MACHINE_H


#include "Player.h"


#include <random>

class Machine: public Player {
public:
    explicit Machine( char sign, const vector<vector<Cell> > &board);
    ~Machine() override = default;

    const Cell makeMove() override;
};


#endif //TIC_TAC_TOE_MACHINE_H
