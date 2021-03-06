#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int height, int width, GameMode gameMode)
        : width(width), height(height), board(height, std::vector<Field>(width)),
          isFirstAction(true), fieldsToReveal(0), toggledFields(0) {
    amountOfMines = ceil((height * width) * (static_cast<double>(gameMode) / 100));
    fieldsToReveal = (height * width) - amountOfMines;
    generateMinesOnBoard(amountOfMines);
    debug_display();
}

MinesweeperBoard::~MinesweeperBoard() {
}

int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}

int MinesweeperBoard::getMineCount() const {
    return amountOfMines;
}

//Displays the raw board
void MinesweeperBoard::debug_display() {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            std::cout << board[row][col].getRawField();
        }
        std::cout << '\n';
    }
}

//Generates mines on board at random positions
void MinesweeperBoard::generateMinesOnBoard(int amountOfMines) {
    int randomHeight, randomWidth;
    srand(time(NULL));
    do {
        randomHeight = rand() % height;
        randomWidth = rand() % width;
        if (!board[randomHeight][randomWidth].hasMine) {
            board[randomHeight][randomWidth].hasMine = true;
            amountOfMines--;
        }
    } while (amountOfMines > 0);
}

//Checks whether the cell at the position (row, col) is valid or not
bool MinesweeperBoard::isInRange(int row, int col) const {
    if (row >= 0 && row < width && col >= 0 && col < height) {
        return true;
    }
    return false;
}

//  #############
//  # 6 # 1 # 5 #
//  #############
//  # 4 # O # 3 #    Neighbours of the revealed cell
//  #############
//  # 8 # 2 # 7 #
//  #############

//Used to count mines around the revealed cell
int MinesweeperBoard::countMines(int row, int col) const {
    int minesAround = 0; //Number of mines around the revealed cell
    if (isInRange(row, col) && board[row][col].isRevealed) {
        //----------- 1st Neighbour ------------
        if (isInRange(row - 1, col)) {
            if (board[row - 1][col].hasMine)
                minesAround++;
        }
        //----------- 2nd Neighbour ------------
        if (isInRange(row + 1, col)) {
            if (board[row + 1][col].hasMine)
                minesAround++;
        }
        //----------- 3rd Neighbour ------------
        if (isInRange(row, col + 1)) {
            if (board[row][col + 1].hasMine)
                minesAround++;
        }
        //----------- 4th Neighbour ------------
        if (isInRange(row, col - 1)) {
            if (board[row][col - 1].hasMine)
                minesAround++;
        }
        //----------- 5th Neighbour ------------
        if (isInRange(row - 1, col + 1)) {
            if (board[row - 1][col + 1].hasMine)
                minesAround++;
        }
        //----------- 6th Neighbour ------------
        if (isInRange(row - 1, col - 1)) {
            if (board[row - 1][col - 1].hasMine)
                minesAround++;
        }
        //----------- 7th Neighbour ------------
        if (isInRange(row + 1, col + 1)) {
            if (board[row + 1][col + 1].hasMine)
                minesAround++;
        }
        //----------- 8th Neighbour ------------
        if (isInRange(row + 1, col - 1)) {
            if (board[row + 1][col - 1].hasMine)
                minesAround++;
        }

    } else {
        return -1;
    }
    return minesAround;
}

//Returns true if the field at (row,col) position was marked with flag & not revealed
bool MinesweeperBoard::hasFlag(int row, int col) const {
    if (isInRange(row, col) && board[row][col].hasFlag && !board[row][col].isRevealed) {
        return true;
    }
    return false;
}

//If the field at (row,col) was not revealed - change flag status for this field
void MinesweeperBoard::toggleFlag(int row, int col) {
    if (isInRange(row, col) && !board[row][col].isRevealed) {
        board[row][col].hasFlag = true;
    } else {
        std::cout << "Try again." << std::endl;
    }
    if (isFirstAction) {
        isFirstAction = false;
    }
}

void MinesweeperBoard::revealField(int row, int col) {
    if (isInRange(row, col) && !board[row][col].isRevealed && !board[row][col].hasFlag) {
        //If its the first player action - move mine to another location
        if (board[row][col].hasMine && isFirstAction) {
            board[row][col].hasMine = false;   //"Delete" mine
            generateMinesOnBoard(1);           //Generate new mine 1 time at random position
            board[row][col].isRevealed = true; //Reveal field
        } else {
            //just reveal field
            board[row][col].isRevealed = true;
        }
        isFirstAction = false;  //Change flag state
        fieldsToReveal--;
    } else {
        std::cout << "Try again." << std::endl;
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const {
    return board[row][col].isRevealed;
}

std::string MinesweeperBoard::getFieldForPlayer(int row, int col) const {
    //if the field is revealed and has some mines around
    int minesAround = countMines(row, col);
    if (board[row][col].isRevealed && minesAround > 0 && !board[row][col].hasMine) {
        std::stringstream ss;
        ss << "[" << minesAround << "]";
        return ss.str();
    } else {
        return board[row][col].getField();
    }
}

// return current game state:
GameState MinesweeperBoard::getGameState() const {
    // - FINISHED_LOSS - if the player revealed field with mine
    for (auto &elem : board) {
        // - FINISHED_LOSS - if the player revealed field with mine
        if (std::any_of(elem.begin(), elem.end(),
                        [](const Field &field) { return (field.hasMine && field.isRevealed); })) {
            return GameState::FINISHED_LOSS;
        }
    }
    // - FINISHED_WIN  - if the player won the game (all unrevealed fields have mines)
    if (fieldsToReveal == 0 && !isFirstAction) {
        return GameState::FINISHED_WIN;
    }
    // - RUNNING - if the game is not yet finished
    return GameState::RUNNING;
}
