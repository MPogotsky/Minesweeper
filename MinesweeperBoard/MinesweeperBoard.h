#ifndef MINESWEEPERBOARD_H_
#define MINESWEEPERBOARD_H_

#include "../Field/Field.h"
#include <iostream>
#include <vector>
#include <ctime>

//Enum class with mine percentage depending on the game mode
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
  int width; //Width of the game field(board)
  int height; //Height of the game field(board)
  std::vector<std::vector<Field>> board;
  int amountOfMines; //Amount of mines to be placed on a board
  bool isFirstAction;

  bool isInRange(int col, int raw) const;

public:
  MinesweeperBoard(int width, int height, GameMode gameMode);
  virtual ~MinesweeperBoard();

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  void debug_display();
  void generateMinesOnBoard(int amountOfMines);
  int countMines(int row, int col) const;
  bool hasFlag(int row, int col) const;
  void toggleFlag(int row, int col);
  void revealField(int row, int col);
  bool isRevealed(int row, int col) const;
  GameState getGameState() const;
  std::string getFieldForPlayer(int row, int col) const;

};

#endif  //MINESWEEPERBOARD_H_
