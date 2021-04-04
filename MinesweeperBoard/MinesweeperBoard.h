#ifndef MINESWEEPERBOARD_H_
#define MINESWEEPERBOARD_H_

#include <iostream>

enum class GameMode {
  DEBUG,
  EASY,
  NORMAL,
  HARD
};

enum class GameState {
  RUNNING,
  FINISHED_WIN,
  FINISHED_LOSS
};

struct Field {
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

class MinesweeperBoard {
private:
  Field board[50][50];
  int width;
  int height;
public:
  MinesweeperBoard(int width, int height);
  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;
  virtual ~MinesweeperBoard();
};

#endif  //MINESWEEPERBOARD_H_
