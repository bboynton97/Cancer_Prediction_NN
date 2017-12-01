//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _PREPROCESSOR_H_
#define _PREPROCESSOR_H_

#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <sstream>

class Preprocessor {
public:
  Preprocessor(std::string filename);
  ~Preprocessor();
  bool isFinished();
  void getData(std::vector<int> &data);
  int getNextInputs(std::vector<float> &inputs);
  int getTargetOutputs(std::vector<float> &targetOutputs);

private:
  std::ifstream dataFile;
};

#endif
