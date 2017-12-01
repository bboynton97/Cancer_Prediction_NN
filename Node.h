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

class Node : public Abstract_Node {
public:
  Node();
  ~Node();

private:
  float output;
  std::vector<Connection *> outputWeights;
};

#endif
