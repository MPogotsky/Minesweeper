#ifndef MINESWEEPERBOARD_H_
#define MINESWEEPERBOARD_H_

#include "../Field/Field.h"
#include <iostream>
#include <vector>
#include <ctime>

//enum class with mine percentage depending on game mode
enum class GameMode {
  DEBUG,
  EASY = 10,    //  10% of game fields with mines (random)
  NORMAL = 20,  //  20% of game fields with mines (random)
  HARD = 30     //  30% of game fields with mines (random)
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
  int amountOfMines;
  int minesAround;

  bool isInRange(int col, int raw) const;

public:
  MinesweeperBoard(int width, int height, GameMode gameMode);
  virtual ~MinesweeperBoard();

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  void generateMinesOnBoard(int amountOfMines);
  void debug_display();

};

#endif  //MINESWEEPERBOARD_H_
