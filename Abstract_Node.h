//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _ABSTRACT_NODE_H_
#define _ABSTRACT_NODE_H_

//#include "Abstract_Layer.h"
#include "Connection.h"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>

class Abstract_Layer;

class Abstract_Node {
public:
  virtual ~Abstract_Node() { };
  virtual void feedForward(Abstract_Layer * lastLayer) = 0;
  virtual void setOutput(float value) = 0;
  virtual float getOutput() = 0;
  virtual Connection * getConnectionAt(int index) = 0;
  virtual void calculateOutputGradients(float targetVal) = 0;
  virtual void calculateHiddenGradients(Abstract_Layer * nextLayer) = 0;
  virtual float getGradient() = 0;
  virtual void updateInputWeights(Abstract_Layer * previousLayer) = 0;
  virtual float activationFunction(float val) = 0;
  virtual float activationFunctionDerived(float val) = 0;
  virtual int getIndex() = 0;

protected:
  int index;
  float hm_outputs;
  float outputValue;
  std::vector<Connection *> outputConnections;
  float gradient;
};

#endif
