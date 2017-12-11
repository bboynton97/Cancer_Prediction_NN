//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _LAYER_ITERATOR_H_
#define _LAYER_ITERATOR_H_

#include "../../layer/Abstract_Layer.h"
#include "../../node/Node.h"
#include "../../net/Net.h"
#include "Base_Layer_Iterator.h"

class Net;

class Layer_Iterator : public Base_Layer_Iterator {
public:
  Layer_Iterator(Net & net);
  virtual ~Layer_Iterator();
  virtual void begin();
  virtual void next();
  virtual Abstract_Layer * getLayer();
  virtual Abstract_Layer * getLastLayer();
  virtual bool isEnd();
};

#endif
