//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _NET_H_
#define _NET_H_

#include "Abstract_Layer.h"

class Net {
public:
  Net();
  ~Net();
  void feedForward(std::vector<float> &inputs);
  void backProp(std::vector<float> &targets);
  void getResults();//results);
  void addLayer(Abstract_Layer & layer);

private:
  std::vector<Abstract_Layer> layers;
};

#endif
