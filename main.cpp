#include <iostream>
#include <memory>
#include "MSTextController/MSTextController.h"

int main(int argc, char const *argv[])
{
    MinesweeperBoard board(5,5, GameMode::EASY);
    MSBoardTextView view(board);
    MSTextController ctrl(board,view);

    board.revealField(0,0);
    ctrl.play();

  // int enteredValue = 0;
  // int height = 0;
  // int width = 0;
  // GameMode gameMode = GameMode::EASY;
  // do{
  //   std::cout << "---------- MAIN MENU ----------" << '\n';
  //   std::cout << "1.Start new game" << '\n';
  //   std::cout << "9.Quit" << '\n';
  //   std::cout << "[]: ";
  //   std::cin >> enteredValue;
  //   std::cout << "-------------------------------" << '\n';
  //
  //   if (enteredValue == 1) {
  //     std::cout << "It is time to prepare the board: " << '\n';
  //     std::cout << "Enter board width: " << '\n';
  //     std::cout << "[]: ";
  //     std::cin >> width;
  //     std::cout << "Enter board height: " << '\n';
  //     std::cout << "[]: ";
  //     std::cin >> height;
  //     do{
  //       std::cout << "Game Mode:" << '\n';
  //       std::cout << "1.Easy\n2.Normal\n3.Hard" << '\n';
  //       std::cout << "[]: ";
  //       std::cin >> enteredValue;
  //     }while(enteredValue < 1 || enteredValue > 3);
  //     std::cout << "-------------------------------" << '\n';
  //     switch (enteredValue) {
  //       case 1:
  //           gameMode = GameMode::EASY;
  //           break;
  //       case 2:
  //           gameMode = GameMode::NORMAL;
  //           break;
  //       case 3:
  //           gameMode = GameMode::HARD;
  //           break;
  //       default:
  //           break;
  //     }
  //     MinesweeperBoard board(width, height, gameMode);
  //     MSBoardTextView view(board);
  //     MSTextController controller(board, view);
  //     controller.play();
  //   }
  // }while(enteredValue != 9);
  return 0;
}
