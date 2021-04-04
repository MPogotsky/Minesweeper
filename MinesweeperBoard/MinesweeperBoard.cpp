#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height)
  :width(width), height(height), board(width, std::vector<Field>(height)){
    board[0][0].hasMine = true;
    board[1][1].hasMine = true;
    board[2][2].hasFlag = true;
}

MinesweeperBoard::~MinesweeperBoard(){

}

int MinesweeperBoard::getBoardWidth() const {
  return width;
}

int MinesweeperBoard::getBoardHeight() const {
  return height;
}

// int MinesweeperBoard::getMineCount() const {
//   return
// }

void  MinesweeperBoard::debug_display() {
  for(int h = 0; h < height; h++){
    for(int w = 0; w < width; w++){
      std::cout << board[h][w].getField();
    }
    std::cout << '\n';
  }
}
