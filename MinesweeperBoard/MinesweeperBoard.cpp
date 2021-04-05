#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode gameMode)
:width(width), height(height), board(height, std::vector<Field>(width)), minesAround(0){
  amountOfMines = (height*width)*(static_cast<double>(gameMode)/100);
  generateMinesOnBoard(amountOfMines);
  board[4][4].isRevealed = true;
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

//Checks whether the cell at the position (row, col) is valid or not
bool MinesweeperBoard::isInRange(int row, int col) const {
  if(row >= 0 && row <= width && col >= 0 && col <= height){
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
int MinesweeperBoard::countMines(int row, int col) {
  if(isInRange(row, col) && board[col][row].isRevealed){

    //----------- 1st Neighbour ------------
    if (isInRange(row-1, col))
    {
      if (board[row-1][col].hasMine)
      minesAround++;
    }
    //----------- 2nd Neighbour ------------
    if (isInRange(row+1, col))
    {
      if (board[row+1][col].hasMine)
      minesAround++;
    }
    //----------- 3rd Neighbour ------------
    if (isInRange(row, col+1))
    {
      if (board[row][col+1].hasMine)
      minesAround++;
    }
    //----------- 4th Neighbour ------------
    if (isInRange(row, col-1))
    {
      if (board[row][col-1].hasMine)
      minesAround++;
    }
    //----------- 5th Neighbour ------------
    if (isInRange(row-1, col+1))
    {
      if (board[row-1][col+1].hasMine)
      minesAround++;
    }
    //----------- 6th Neighbour ------------
    if (isInRange(row-1, col-1))
    {
      if (board[row-1][col-1].hasMine)
      minesAround++;
    }
    //----------- 7th Neighbour ------------
    if (isInRange(row+1, col+1))
    {
      if (board[row+1][col+1].hasMine)
      minesAround++;
    }
    //----------- 8th Neighbour ------------
    if (isInRange(row+1, col-1))
    {
      if (board[row+1][col-1].hasMine)
      minesAround++;
    }

  }else{
    return -1;
  }
  return minesAround;
}

//Generates mines on board at random positions
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

//Displays the raw board
void MinesweeperBoard::debug_display() {
  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      std::cout << board[row][col].getField();
    }
    std::cout << '\n';
  }
}
