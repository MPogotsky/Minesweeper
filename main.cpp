#include <iostream>
#include "MinesweeperBoard/MinesweeperBoard.h"

int main(int argc, char const *argv[])
{
  MinesweeperBoard mainBoard(10, 10, GameMode::HARD);
  mainBoard.debug_display();
  std::cout << "Mines around:" << mainBoard.countMines(4,4) << '\n';
  return 0;
}
