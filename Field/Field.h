#ifndef FIELD_H_
#define FIELD_H_

#include <string>
#include <sstream>

//Structure representing a single cell on the board
struct Field {
  bool hasMine;
  bool hasFlag;
  bool isRevealed;

  Field();
  std::string getRawField() const;
  std::string getField() const;
  ~Field(){
  }
};

#endif //FIELD_H_
