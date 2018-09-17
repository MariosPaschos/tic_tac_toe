#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H


#include "Cell.h"

#include <vector>

class Board {
private:
    vector<vector<Cell> > board;
    int state;
public:
    explicit Board(const vector<vector<Cell> > &board);
    ~Board();

    int getState() const;
    void setState(int state);
};


#endif //TIC_TAC_TOE_BOARD_H
