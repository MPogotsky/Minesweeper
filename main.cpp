#include <iostream>
#include "MSBoardTextView/MSBoardTextView.h"

int main(int argc, char const *argv[])
{

  MinesweeperBoard mainBoard(10, 10, GameMode::HARD);

  mainBoard.revealField(0,0);
  mainBoard.revealField(3,3);
  mainBoard.toggleFlag(6,6);
  mainBoard.toggleFlag(9,9);
  mainBoard.debug_display();


  return 0;
}
