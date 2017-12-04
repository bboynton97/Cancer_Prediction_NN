//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _NET_H_
#define _NET_H_

#include "Abstract_Layer.h"
#include <iostream>
#include<math.h>

class Net {
public:
  Net();
  ~Net();
  void feedForward(std::vector<int> * inputs);
  void backProp(std::vector<int> * targets);
  std::vector<float> * getResults();
  void addLayer(Abstract_Layer * layer);
  float getAvgError();
  float getError();

private:
  std::vector<Abstract_Layer *> layers;
  float avgError;
  float error;
};

#endif
