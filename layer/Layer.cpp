//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "../layer/Layer.h"

Layer::Layer() { 

}

Layer::~Layer() {
  // Delete all nodes in the layer
  for (int i=0; i<this->nodes.size(); i++) {
   delete this->nodes.at(i);
  }
}

void Layer::addNode(Abstract_Node * node) {
  this->nodes.push_back(node);
}

std::vector<Abstract_Node *> Layer::getLayer() {
  return this->nodes;
}

Abstract_Node * Layer::getNodeAt(int index) {
  return this->nodes.at(index);
}

int Layer::size() {
  return this->nodes.size();
}
