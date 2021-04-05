#include <iostream>
#include "MSTextController/MSTextController.h"

int main(int argc, char const *argv[])
{

  MinesweeperBoard board(10, 10, GameMode::EASY);

  board.revealField(0,0);
  board.revealField(1,1);
  board.revealField(3,3);
  board.revealField(2,3);
  board.revealField(5,3);
  board.toggleFlag(6,6);
  board.toggleFlag(9,9);

  MSBoardTextView view(board);
  view.display();

  MSTextController controller(board, view);

  return 0;
}
