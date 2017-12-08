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
#include "Base_Layer_Iterator.h"
#include "Base_Node_Iterator.h"
#include "Layer_Iterator.h"
#include "Node_Iterator.h"

class Net {
public:
  Net();
  ~Net();
  void feedForward(std::vector<int> * inputs);
  void backProp(std::vector<int> * targets);
  std::vector<float> * getResults();
  void addLayer(Abstract_Layer * layer);
  Abstract_Layer * getLayerAt(int index);
  float getAvgError();
  float getError();
  int size();

private:
  std::vector<Abstract_Layer *> layers;
  float avgError;
  float error;
};

#endif
