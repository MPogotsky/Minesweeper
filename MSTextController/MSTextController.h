#ifndef MSTEXTCONTROLLER_H_
#define MSTEXTCONTROLLER_H_

#include "../MSBoardTextView/MSBoardTextView.h"

class MSTextController {
private:
  MinesweeperBoard board;
  MSBoardTextView view;
public:
  MSTextController (MinesweeperBoard &board, MSBoardTextView &view);
  ~MSTextController ();
};

#endif //MSTEXTCONTROLLER_H_
