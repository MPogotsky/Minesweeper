#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board)
  :board(board){
}

MSBoardTextView::~MSBoardTextView(){
}

void MSBoardTextView::display(){
  for(int row = 0; row < board.getBoardHeight(); row++){
    for(int col = 0; col < board.getBoardWidth(); col++){
      if(board.isRevealed(row, col)){
        std::cout << "[_]" << '\n';
      }
    }
    std::cout << '\n';
  }
}
