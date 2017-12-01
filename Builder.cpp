//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Builder.h"

Builder::Builder() {
  this->net = new Net();
}

Builder::~Builder() {

}

void Builder::createLayer(int hm_nodes) {
  Abstract_Layer * layer = new Layer();
  for (int i=0; i<hm_nodes; i++) {
    Abstract_Node * node = new Node();
    layer->addNode(node);
  }

  net->addLayer(layer);
}

Net * Builder::getNet() {
  return this->net;
}
