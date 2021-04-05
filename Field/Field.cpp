#include "Field.h"

std::string Field::getField(){
  if(hasMine == true && hasFlag == false && isRevealed == false){
    return "[M..]";
  }
  if(hasMine == false && hasFlag == true && isRevealed == false){
    return "[..F]";
  }
  if(hasMine == false && hasFlag == false && isRevealed == true){
    return "[.O.]";
  }
  if(hasMine == true && hasFlag == true && isRevealed == false){
    return "[M.F]";
  }
  return "[...]";
}
