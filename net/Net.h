//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _NET_H_
#define _NET_H_

#include "../layer/Abstract_Layer.h"
#include <iostream>
#include <math.h>
#include "../iterators/node/Base_Node_Iterator.h"
#include "../iterators/node/Node_Iterator.h"
#include "../iterators/layer/Layer_Iterator.h"
#include "../iterators/node/Base_Node_Iterator.h"
#include <memory>

class Net {
public:
  Net();
  ~Net();
  void feedForward(std::vector<float> inputs);
  void backProp(std::vector<int> targets);
  std::vector<float> getResults();
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
