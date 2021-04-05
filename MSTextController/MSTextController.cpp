#include "MSTextController.h"

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view)
:board(board), view(view){
  std::cout << "MSTextController created!" << '\n';
}

MSTextController::~MSTextController(){
}
