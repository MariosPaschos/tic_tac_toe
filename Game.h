#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include "Player.h"
#include "Human.h"
#include "Machine.h"


class Game {
public:
    explicit Game(size_t SIZE);
    ~Game()= default;
    void createBoard();
    void resetBoard();
    const vector<vector<Cell>> & getBoard() const;
    void displayBoard() const;
    bool isMoveValid(Cell &cell);
    bool isMoveLegal(Cell &cell);
    inline bool isPlayerValid(char sign);
    void startGame();
    void selectGameMode();
    void selectPlayer();
    void watchGame();
    void nowPlaying(Player *player);
    bool isMoveLegit(Cell &move);
    void play();
    void replay();
    bool isBoardFinal();
    Player *getCurrentPlayer();
    char checkGameStatus();
    char checkForWinner();
private:
    size_t SIZE;
    vector<vector<Cell> > board;
    Player *player1;
    Player *player2;
    char gameStatus;

    // Private and without implementation to avoid duplicate Game instances-each game is unique
    Game();
    Game(const Game&);
    Game&operator=(const Game&);
};


#endif //TIC_TAC_TOE_GAME_H
