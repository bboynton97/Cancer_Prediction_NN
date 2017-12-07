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

void Builder::createLayer(int hm_nodes, int hm_connectionsPerNode) {
  Abstract_Layer * layer = new Layer();
  for (int i=0; i<hm_nodes +1; i++) { //All inputs plus a bias node
    Abstract_Node * node = new Node(hm_connectionsPerNode, i);
    layer->addNode(node);
  }

  //Create bias node
  layer->getNodeAt(layer->size()-1)->setOutput(1.0); //Give it a static output of 1

  net->addLayer(layer);
}

Net * Builder::getNet() {
  return this->net;
}
