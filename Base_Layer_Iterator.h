//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _BASE_LAYER_ITERATOR_H_
#define _BASE_LAYER_ITERATOR_H_

#include "Abstract_Layer.h"
#include "Node.h"
#include "Net.h"

class Net;

class Base_Layer_Iterator {
public:
  virtual ~Base_Layer_Iterator() { };
  virtual void begin() = 0;
  virtual void next() = 0;
  virtual bool isEnd() = 0;
  virtual Abstract_Layer * getLayer() = 0;
  virtual Abstract_Layer * getLastLayer() = 0;
protected:
  int position;
  Net * net;
};

#endif
