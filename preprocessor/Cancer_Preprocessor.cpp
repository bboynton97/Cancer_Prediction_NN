//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "../preprocessor/Cancer_Preprocessor.h"

//Constructor
Cancer_Preprocessor::Cancer_Preprocessor() { //}: dataFile("breast-cancer-honors.csv", std::ios::in) {
  this->dataFile = std::ifstream("dataset/breast-cancer-honors.csv", std::ios::in);
}

Cancer_Preprocessor::~Cancer_Preprocessor() {

}

int Cancer_Preprocessor::getInputCount() {
  return 9;
}

int Cancer_Preprocessor::largestVal() {
  return 9;
}
