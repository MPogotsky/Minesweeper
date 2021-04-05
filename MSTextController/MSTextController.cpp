#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view)
:board(board), view(view), secondaryMenuOperation(0){
}

MSTextController::~MSTextController(){
}

void MSTextController::play(){
  std::cout << "Board " << board.getBoardHeight() << "x" << board.getBoardWidth() << '\n';
  view.display();
  // do{
  //   view.display();
  //   std::cout << "1.Toggle flag\t2.Reveal field\n9.Back to main menu" << '\n';
  //   switch (secondaryMenuOperation) {
  //     case 1:
  //
  //   }
  // }while(secondaryMenuOperation != 9 && GameState::RUNNING);
}
