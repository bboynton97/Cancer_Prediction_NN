#include "Node_Iterator.h"

Node_Iterator::Node_Iterator(Abstract_Layer & layer) {
  this->layer = &layer;
}

Node_Iterator::~Node_Iterator() {

}

void Node_Iterator::begin() {
  this->position = 0;
}

void Node_Iterator::next() {
  this->position++;
}

Abstract_Node * Node_Iterator::getNode() {
  return this->layer->getNodeAt(this->position);
}

bool Node_Iterator::isEnd() {
  return this->position >= this->layer->size()-1;
}
