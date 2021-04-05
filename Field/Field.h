#ifndef FIELD_H_
#define FIELD_H_

#include <string>
#include <sstream>

struct Field {
  bool hasMine;
  bool hasFlag;
  bool isRevealed;

  Field(){
    hasMine = false;
    hasFlag = false;
    isRevealed = false;
  }

  std::string getField(){
    if(hasMine == false && hasFlag == true && isRevealed == false){
      return "[..F]";
    }
    if(hasMine == true && hasFlag == false && isRevealed == false){
      return "[M..]";
    }
    return "[...]";
  }
};

#endif //FIELD_H_
