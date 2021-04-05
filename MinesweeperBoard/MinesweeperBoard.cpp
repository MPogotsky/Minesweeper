#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode gameMode)
  :width(width), height(height), board(height, std::vector<Field>(width)){
    amountOfMines = (height*width)/static_cast<int>(gameMode);
    generateMinesOnBoard(amountOfMines);
}

MinesweeperBoard::~MinesweeperBoard(){
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

bool MinesweeperBoard::isInRange(int row, int col) const {
  if(row >= 0 && row <= width && col >= 0 && col <= height){
    return true;
  }
  return false;
}

// int countMines(int col, int row) const {
//   if(isInRange(col, raw)){
//
//     if(board[col][row].isRevealed){
//
//     }else{
//       return -1;
//     }
//
//   }else{
//     return -1;
//   }
// }

void MinesweeperBoard::generateMinesOnBoard(int amountOfMines) {
  int randomHeight, randomWidth;
  srand (time(NULL));
  do{
    randomHeight = rand() % height;
    randomWidth = rand() % width;
    if(!board[randomHeight][randomWidth].hasMine){
      board[randomHeight][randomWidth].hasMine = true;
      amountOfMines--;
    }
  }while(amountOfMines > 0);
}

void MinesweeperBoard::debug_display() {
  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      std::cout << board[row][col].getField();
    }
    std::cout << '\n';
  }
}
