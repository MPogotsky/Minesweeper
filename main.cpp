#include <iostream>
#include "MinesweeperBoard/MinesweeperBoard.h"

int main(int argc, char const *argv[])
{
  MinesweeperBoard mainBoard(4, 4);
  mainBoard.debug_display();
  return 0;
}
