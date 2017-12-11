// Honor Pledge:
//
// I pledge that I need and am incapable
// of giving any help on this assignment.
//
// brboynto

#ifndef _BRANDON_PRINT_H_
#define _BRANDON_PRINT_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

//The best garbage code that I could write

class Brandon_Print {
public:
  Brandon_Print() {
    brandon2 = new std::vector<std::string>();
  }
  virtual ~Brandon_Print() {
    delete brandon2;
  }
  void brandon_printf(std::string brandon) {
    this->brandon2->push_back(brandon);
    std::printf("%s",brandon2->back().c_str());
  }

protected:
  std::vector<std::string> * brandon2;
};

#endif
