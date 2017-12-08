//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _BASE_NODE_ITERATOR_H_
#define _BASE_NODE_ITERATOR_H_

#include "Abstract_Node.h"
#include "Node.h"
#include "Net.h"

class Base_Node_Iterator {
public:
  virtual ~Base_Node_Iterator() { };
  virtual void begin() = 0;
  virtual void next() = 0;
  virtual bool isEnd() = 0;
  virtual Abstract_Node * getNode() = 0;
protected:
  int position;
  Abstract_Layer * layer;
};

#endif
