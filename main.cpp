#include <iostream>
#include "MinesweeperBoard/MinesweeperBoard.h"

int main(int argc, char const *argv[])
{
  MinesweeperBoard mainBoard(10, 10, GameMode::EASY);
  mainBoard.debug_display();
  return 0;
}
