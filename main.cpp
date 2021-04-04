#include <iostream>
#include "MinesweeperBoard/MinesweeperBoard.h"

void debug_display(MinesweeperBoard &mainBoard) {
  mainBoard.printRawBoard();
}

int main(int argc, char const *argv[])
{
  MinesweeperBoard mainBoard(4, 4);
  debug_display(mainBoard);
  return 0;
}
