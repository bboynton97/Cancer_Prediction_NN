//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Layer.h"

Layer::Layer() {
  std::cout << "Created layer" << std::endl;
}

Layer::~Layer() {
  //TODO: Delete all nodes in the layer
  //for (int i=0; i<this->nodes.size(); i++) {
  //  delete this->nodes.at(i);
  //}
}

void Layer::addNode(Abstract_Node * node) {
  std::cout << "Added node to layer" << std::endl;
  this->nodes.push_back(node);
}

std::vector<Abstract_Node *> Layer::getLayer() {
  return this->nodes;
}

Abstract_Node * Layer::getNodeAt(int index) {
  return this->nodes.at(index);
}
