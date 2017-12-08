//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "XOR_Preprocessor.h"

//Constructor
XOR_Preprocessor::XOR_Preprocessor() { //}: dataFile("xor.csv", std::ios::in) {
  this->dataFile = std::ifstream("xor.csv", std::ios::in);
}

XOR_Preprocessor::~XOR_Preprocessor() {

}
