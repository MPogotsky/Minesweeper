#ifndef MINESWEEPERBOARD_H_
#define MINESWEEPERBOARD_H_

#include <iostream>
#include <vector>

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



class MinesweeperBoard {
private:
  int width;
  int height;
  std::vector<std::vector<Field>> board;
public:
  MinesweeperBoard(int width, int height);
  virtual ~MinesweeperBoard();

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  void printRawBoard();

};

#endif  //MINESWEEPERBOARD_H_
