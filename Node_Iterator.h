//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _NODE_ITERATOR_H_
#define _NODE_ITERATOR_H_

#include "Abstract_Layer.h"
#include "Node.h"
#include "Net.h"
#include "Base_Node_Iterator.h"

class Node_Iterator : public Base_Node_Iterator {
public:
  Node_Iterator(Abstract_Layer & layer);
  virtual ~Node_Iterator();
  virtual void begin();
  virtual void next();
  virtual Abstract_Node * getNode();
  virtual bool isEnd();
};

#endif
