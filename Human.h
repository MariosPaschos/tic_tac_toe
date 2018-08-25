#ifndef TIC_TAC_TOE_HUMAN_H
#define TIC_TAC_TOE_HUMAN_H

#include "Player.h"
#include "Cell.h"


class Human: public Player {
public:
    explicit Human(char sign, const vector<vector<Cell> > &board);
    ~Human() override = default;

    const Cell makeMove() override;
};


#endif //TIC_TAC_TOE_HUMAN_H
