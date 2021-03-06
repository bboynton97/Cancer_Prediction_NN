//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _BASE_PREPROCESSOR_H_
#define _BASE_PREPROCESSOR_H_

#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

//Works as an iterator in how it passes data

class Base_Preprocessor {
public:
  Base_Preprocessor();
  virtual ~Base_Preprocessor();
  bool isFinished();
  void getData(std::vector<int> &data);
  void restart();
  std::vector<int> getData();
  void next();
  virtual int getInputCount() = 0;
  virtual int largestVal() = 0;
  int getLine();


protected:
  std::ifstream dataFile;
  bool isEnd;
  std::vector<int> nextData;
  int line;
};

#endif
