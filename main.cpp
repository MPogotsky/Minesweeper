#include <iostream>
#include "MinesweeperBoard/MinesweeperBoard.h"

void debug_display(MinesweeperBoard &mainBoard) {
  for(int height = 0; height < mainBoard.getBoardHeight(); height++){
    for(int width = 0; width < mainBoard.getBoardWidth(); width++){
      std::cout << "[...]";
    }
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[])
{
  MinesweeperBoard mainBoard(10, 10);
  debug_display(mainBoard);
  return 0;
}
