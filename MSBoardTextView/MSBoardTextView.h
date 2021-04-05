#ifndef MSBOARDTEXTVIEW_H_
#define MSBOARDTEXTVIEW_H_

#include "../MinesweeperBoard/MinesweeperBoard.h"

class MSBoardTextView {
private:
  MinesweeperBoard board;
public:
  MSBoardTextView (MinesweeperBoard &board);
  ~MSBoardTextView ();

  void display();
};

#endif //MSBOARDTEXTVIEW_H_
