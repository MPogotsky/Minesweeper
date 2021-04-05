#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode gameMode)
  :width(width), height(height), board(width, std::vector<Field>(height)){
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

void MinesweeperBoard::generateMinesOnBoard(int amountOfMines) {
  int randomWidth, randomHeight;
  srand (time(NULL));
  do{
    randomWidth = rand() % height;
    randomHeight = rand() % width;
    if(!board[randomWidth][randomHeight].hasMine){
      board[randomWidth][randomHeight].hasMine = true;
      amountOfMines--;
    }
  }while(amountOfMines > 0);
}

void MinesweeperBoard::debug_display() {
  for(int h = 0; h < height; h++){
    for(int w = 0; w < width; w++){
      std::cout << board[h][w].getField();
    }
    std::cout << '\n';
  }
}
