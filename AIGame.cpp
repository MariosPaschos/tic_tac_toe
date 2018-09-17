#include "AIGame.h"


AIGame::AIGame(size_t size) : Game(size) {
    createBoard();
    resetBoard();
    watchGame();
    play();
}
