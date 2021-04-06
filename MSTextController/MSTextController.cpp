#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view)
:board(&board), view(&view), gameState(GameState::RUNNING), secondaryMenuOperation(0), row(0), col(0){
}

MSTextController::~MSTextController(){

}

void MSTextController::play(){

  view->display();
  // std::cout << "Board " << board.getBoardHeight() << "x" << board.getBoardWidth() << '\n';
  // do{
  //   view.display();
  //   std::cout << "1.Toggle flag\t2.Reveal field\n9.Back to main menu" << '\n';
  //   std::cout << "[]: ";
  //   std::cin >> secondaryMenuOperation;
  //   std::cout << "Cell(row, col)" << '\n';
  //   std::cout << "Row[]: ";
  //   std::cin >> row;
  //   std::cout << "Col[]: ";
  //   std::cin >> col;
  //   switch (secondaryMenuOperation) {
  //     case 1:
  //       if(!board.isRevealed(row,col)){
  //         board.toggleFlag(row, col);
  //       }
  //       break;
  //     default:
  //       std::cout << "Ups, try again." << '\n';
  //   }
  // }while(secondaryMenuOperation != 9 && gameState == GameState::RUNNING);
}
