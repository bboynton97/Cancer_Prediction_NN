//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _ABSTRACT_BUILDER_H_
#define _ABSTRACT_BUILDER_H_

#include "../layer/Layer.h"
#include "../node/Node.h"
#include "../net/Net.h"

class Abstract_Builder {
public:
  virtual ~Abstract_Builder() { };
  virtual void createLayer(int hm_nodes, int hm_connectionsPerNode) = 0;
  virtual Net * getNet() = 0;
protected:
  Net * net;
};

#endif
