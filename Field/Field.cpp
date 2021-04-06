#include "Field.h"

Field::Field(){
  this->hasMine = false;
  this->hasFlag = false;
  this->isRevealed = false;
}

std::string Field::getRawField() const {
  std::stringstream ss;
  ss << "[";
  if(hasMine){
    ss << "M";
  }else{
    ss << ".";
  }
  if(isRevealed){
    ss << "O";
  }else{
    ss << ".";
  }
  if(hasFlag){
    ss << "F";
  }else{
    ss << ".";
  }
  ss << "]";
  return ss.str();
}

std::string Field::getField() const {
  // if the field is not revealed and has a flag
  if(hasFlag && !isRevealed){
    return "[F]";
  }
  // if the field is revealed and has 0 mines around
  if(!hasMine && isRevealed){
    return "[ ]";
  }
  // if the field is revealed and has mine
  if(hasMine && isRevealed){
    return "[X]";
  }
  
  return "[_]";
}
