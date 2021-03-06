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
    selectGameMode();
    play();
    replay();
}

void Game::play(){

    do{
        displayBoard();
        nowPlaying(getCurrentPlayer());
        gameStatus = checkGameStatus();
    } while (gameStatus == 'N');

    cout << "\nGame is over. Final board:" << endl;
    this->finalBoard = board;
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

char Game::checkForWinner(){
    return utils::checkBoardForWinner(board);
}

bool Game::isBoardFinal() {
    return utils::isBoardFull(board);
}

// Check whether someone won, or if the board is full and the game ended as draw
char Game::checkGameStatus() {

    gameStatus = checkForWinner();
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
        default:    //case 'N' - game is not over yet
            cout << "Keep playing." << endl;
    }
    return gameStatus;
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

//TODO -> WHEN HUMAN ENTERS A COMBINATION OF CHARACTERS AND NUMBERS THE GAME GOES INTO AN INFINITE LOOP ->FIX
void Game::nowPlaying(Player *player) {
    Cell move = Cell();
    do {
        cout << "\nPlayer " << player->getSign() << " plays." << endl;
        move = player->makeMove();  // Player makes a move
    }
    while (!isMoveLegit(move));

    // Legal move - place the player's marker on the selected cell on the game board
    board[move.getI()][move.getJ()].setSign(player->getSign());
    player->hasPlayed = true;
}

Player *Game::getCurrentPlayer() {
    if (!player1->hasPlayed){
        player2->hasPlayed = false;
        return player1;
    }
    else {
        player1->hasPlayed = false;
        return player2;
    }
}

void Game::selectGameMode() {
    bool modeSelected = false;
    char mode = 'u';
    while  (!modeSelected){
        cout << "Do you want to play against the program (P) or watch a match between 2 programs (W)? " << endl;
        cin >> mode;
        mode = static_cast<char>(toupper(mode));
        if (!(mode == 'P' || mode == 'W')){
            continue;
        }
        else if (mode == 'P'){
            selectPlayer();
            modeSelected = true;
        }
        else if (mode == 'W'){
            watchGame();
            modeSelected = true;
        }
    }
}

void Game::watchGame() {

    //Machine vs Machine
    player1 = new Machine('X', board);
    player2 = new Machine('O', board);
}

void Game::replay() {
    char choice = 'N';
    bool selected = false;
    while (!selected){
        cout << "Do you want to play again? Y/N" << endl;
        cin >> choice;
        choice = static_cast<char>(toupper(choice));
        switch (choice) {
            case 'Y':
                selected = true;
                break;
            case 'N' :
                cout << "Thank you for playing! Bye!" << endl;
                clog << "Program terminates...";
                exit(0);
            default:
                continue;
        }
    }
    startGame();
}

const vector<vector<Cell>> &Game::getFinalBoard() const {
    return this->finalBoard;
}

char Game::getGameStatus() const {
    return this->gameStatus;
}







