#ifndef TIC_TAC_TOE_TRAINING_H
#define TIC_TAC_TOE_TRAINING_H

#include "Game.h"
#include "Board.h"

#include <fstream>


class Training {

private:
    int numOfGames;
    int result;
    ofstream training_logs;

public:
    Training();
    explicit Training(int numOfGames);
    ~Training()= default;
    void startTraining();

};


#endif //TIC_TAC_TOE_TRAINING_H
