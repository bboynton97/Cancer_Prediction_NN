//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "../preprocessor/XOR_Preprocessor.h"

//Constructor
XOR_Preprocessor::XOR_Preprocessor() { //}: dataFile("xor.csv", std::ios::in) {
  this->dataFile = std::ifstream("dataset/xor.csv", std::ios::in);
}

XOR_Preprocessor::~XOR_Preprocessor() {

}

int XOR_Preprocessor::getInputCount() {
  return 2;
}

int XOR_Preprocessor::largestVal() {
  return 1;
}
