#ifndef MSTEXTCONTROLLER_H_
#define MSTEXTCONTROLLER_H_

#include "../MSBoardTextView/MSBoardTextView.h"

class MSTextController {
private:
  MinesweeperBoard *board;
  MSBoardTextView *view;
  GameState currentGameState;
  int secondaryMenuOperation;
  int row;
  int col;

public:
  MSTextController (MinesweeperBoard &board, MSBoardTextView &view);
  ~MSTextController ();
  void play();
  int startGame();
  void prepareBoard();
};

#endif //MSTEXTCONTROLLER_H_
