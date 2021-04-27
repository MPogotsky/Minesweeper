#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view)
        : board(&board), view(&view), currentGameState(GameState::RUNNING), secondaryMenuOperation(0), row(0), col(0) {
}

MSTextController::~MSTextController() {
}

void MSTextController::play() {
    std::cout << "Board " << board->getBoardHeight() << "x" << board->getBoardWidth() << '\n';
    do {
        currentGameState = board->getGameState();
        view->display();
        switch (currentGameState) {
            case GameState::RUNNING:
                std::cout << "1.Toggle flag\t2.Reveal field\n9.Back to main menu" << '\n';
                std::cout << "[]: ";
                std::cin >> secondaryMenuOperation;
                std::cout << "-------------------------" << '\n';
                switch (secondaryMenuOperation) {
                    case 1: {
                        std::cout << "Cell(row, col)" << '\n';
                        std::cout << "Row[]: ";
                        std::cin >> row;
                        std::cout << "Col[]: ";
                        std::cin >> col;
                        board->toggleFlag(row, col);
                        break;
                    }
                    case 2: {
                        std::cout << "Cell(row, col)" << '\n';
                        std::cout << "Row[]: ";
                        std::cin >> row;
                        std::cout << "Col[]: ";
                        std::cin >> col;
                        if (!board->isRevealed(row, col)) {
                            board->revealField(row, col);
                        } else {
                            std::cout << "Field is already revealed." << '\n';
                        }
                        break;
                    }
                }
                break;
            case GameState::FINISHED_WIN:
                std::cout << "You won ;)" << '\n';
                break;
            case GameState::FINISHED_LOSS:
                std::cout << "You lost :(" << '\n';
                break;
        }
    } while (secondaryMenuOperation != 9 && currentGameState != GameState::FINISHED_WIN &&
             currentGameState != GameState::FINISHED_LOSS);
}
