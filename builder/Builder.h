//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "../layer/Abstract_Layer.h"
#include "../layer/Layer.h"
#include "../node/Node.h"
#include "../net/Net.h"
#include "../builder/Abstract_Builder.h"

class Builder : public Abstract_Builder {
public:
  Builder();
  virtual ~Builder();
  virtual void createLayer(int hm_nodes, int hm_connectionsPerNode);
  virtual Net * getNet();
};

#endif
