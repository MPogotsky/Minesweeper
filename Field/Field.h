#ifndef FIELD_H_
#define FIELD_H_

#include <string>

//Structure representing a single cell on the board
struct Field {
  bool hasMine;
  bool hasFlag;
  bool isRevealed;

  Field()
    :hasMine(false), hasFlag(false), isRevealed(false){
  }
  std::string getField();
  ~Field(){
  }
};

#endif //FIELD_H_
