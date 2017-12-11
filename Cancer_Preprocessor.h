//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _CANCER_PREPROCESSOR_H_
#define _CANCER_PREPROCESSOR_H_

#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "Base_Preprocessor.h"

class Cancer_Preprocessor : public Base_Preprocessor {
public:
  Cancer_Preprocessor();
  ~Cancer_Preprocessor();
  virtual int getInputCount();
};

#endif
