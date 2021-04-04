#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height)
  :width(width), height(height){
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
