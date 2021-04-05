#include <iostream>
#include "MinesweeperBoard/MinesweeperBoard.h"

int main(int argc, char const *argv[])
{
  MinesweeperBoard mainBoard(10, 10, GameMode::EASY);
  mainBoard.debug_display();
  std::cout << '\n' << mainBoard.countMines(5,5) << '\n';
  return 0;
}
