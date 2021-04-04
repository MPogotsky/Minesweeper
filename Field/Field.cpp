#include "Field.h"

std::string getField(){
  if(hasMine == false && hasFlag == true && isRevealed == false){
    return "[..F]";
  }
  if(hasMine == true && hasFlag == false && isRevealed == false){
    return "[M..]";
  }
  return "[...]";
}
