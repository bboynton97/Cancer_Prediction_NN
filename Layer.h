//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _LAYER_H_
#define _LAYER_H_

#include "Abstract_Layer.h"
#include <iostream>

class Layer : public Abstract_Layer {
public:
  Layer();
  virtual ~Layer();
  virtual void addNode(Abstract_Node * node);
  virtual std::vector<Abstract_Node *> getLayer();
  virtual Abstract_Node * getNodeAt(int index);
};

#endif
