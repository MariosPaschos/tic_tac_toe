#include "Game.h"

// Default constructor made private so as to make it impossible to create a Game without size
Game::Game() : SIZE(0), board(0, vector<Cell>()), player1(nullptr), player2(nullptr), gameStatus('N') {}

Game::Game(size_t SIZE) : SIZE(SIZE), board(0, vector<Cell>()), player1(nullptr), player2(nullptr), gameStatus('N') {
    createBoard();
    startGame();
}

void Game::createBoard() {
    this->board = utils::create2DBoard(SIZE);
}

void Game::resetBoard() {
    utils::resetBoard(this->board);
}

const vector<vector<Cell>> &Game::getBoard() const {
    return this->board;
}

void Game::displayBoard() const {
    utils::showBoard(this->board);
}

void Game::selectPlayer() {
    char sign;
    while (true){
        cout << "Select player: (X/O)" << endl;
        try {
            cin >> sign;
            sign = static_cast<char>(toupper(sign));
            if (isPlayerValid(sign)) {
                switch (sign) {
                    case 'X':
                        player1 = new Human('X', board);
                        player2 = new Machine('O', board);
                        break;
                    case 'O':
                        player1 = new Machine('X', board);
                        player2 = new Human('O', board);
                        break;
                    default:
                        clog << "Player selection unsuccessful. Return to selection." << endl;
                        continue;
                }
                return;
            }
        }
        catch (int error){
            clog << "Error in player selection: " + to_string(error) << endl;
        }
    }
}

void Game::startGame() {
    resetBoard();
    displayBoard();
    selectPlayer();
    play();
}

void Game::play(){
    while (gameStatus == 'N') {
        nowPlaying(player1);
        checkGameStatus();

        nowPlaying(player2);
        checkGameStatus();
    }
    displayBoard();

    //exit(0);
}


bool Game::isMoveValid(Cell &cell) {
    return (cell.getI() > -1) && (cell.getI() < SIZE) && (cell.getJ() > -1) && (cell.getJ() < SIZE);
}

bool Game::isMoveLegal(Cell &cell) {
    return this->board[cell.getI()][cell.getJ()].isEmpty();
}

bool Game::isPlayerValid(char sign) {
    return sign == 'X' || sign == 'O';
}


char Game::checkWinner(){
    return utils::checkBoardForWinner(board);
}

// Check whether someone won, or if the board is full and the game ended as draw
bool Game::isGameOver() {
    return isDraw() || isWinnerX() || isWinnerO();
}

bool Game::isDraw() {
    return utils::isBoardFull(board) && (checkWinner() == 'N');
}

bool Game::isWinnerX() {
    return checkWinner() == 'X';
}

bool Game::isWinnerO() {
    return checkWinner() == 'O';
}

void Game::checkGameStatus() {
    bool gameOver = isGameOver();
    if (gameOver){
        gameStatus = checkWinner();
    }
    switch (gameStatus) {
        case 'X':
            cout << "Player 1 (X) won!" << endl;
            break;
        case 'O':
            cout << "Player 2 (O) won!" << endl;
            break;
        case 'D':
            cout << "Game is draw." << endl;
            break;
        default:    //case 'N'
            cout << "Game underway. Keep playing." << endl;
    }
}

bool Game::isMoveLegit(Cell &move) {
    if (!isMoveValid(move)) {    // Invalid move - out of bounds
        cout << "Move out of bounds!" << endl;
        return false;
    }
    if (!isMoveLegal(move)) {   // Illegal move - cell not empty
        cout << "Illegal move. Selected cell is not empty." << endl;
        return false;
    }
    return true;
}

void Game::nowPlaying(Player *player) {
    displayBoard();
    cout << "\nPlayer " << player->getSign() << " plays" << endl;
    Cell move;
    do {
        move = player->makeMove();  // Player makes a move
    }
    while (!isMoveLegit(move));

    // Legal move - place the marker on the corresponding cell
    board[move.getI()][move.getJ()].setSign(player->getSign());
}



