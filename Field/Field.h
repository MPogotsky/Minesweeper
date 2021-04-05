#ifndef FIELD_H_
#define FIELD_H_

#include <string>

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
