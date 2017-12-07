//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _NODE_H_
#define _NODE_H_

#include "Abstract_Node.h"
#include <iostream>
#include <vector>
#include "Connection.h"
#include <cstdlib>
#include "Abstract_Layer.h"
#include <cmath>
#include <string>
#include <iostream>

class Node : public Abstract_Node {
public:
  Node(int hm_outputs, int index);
  virtual ~Node();
  virtual void feedForward(Abstract_Layer * lastLayer);
  virtual void setOutput(float value);
  virtual float getOutput();
  virtual Connection * getConnectionAt(int index);
  virtual void calculateOutputGradients(float targetVal);
  virtual void calculateHiddenGradients(Abstract_Layer * nextLayer);
  virtual float getGradient();
  virtual void updateInputWeights(Abstract_Layer * previousLayer);
  virtual float activationFunction(float val);
  virtual float activationFunctionDerived(float val);
  virtual int getIndex();
};

#endif
