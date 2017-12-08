#include "Layer_Iterator.h"

Layer_Iterator::Layer_Iterator(Net & net) {
  this->net = &net;
}

Layer_Iterator::~Layer_Iterator() {

}

void Layer_Iterator::begin() {
  this->position = 1;
}

void Layer_Iterator::next() {
  this->position++;
}

Abstract_Layer * Layer_Iterator::getLayer() {
  return this->net->getLayerAt(this->position);
}

Abstract_Layer * Layer_Iterator::getLastLayer() {
  return this->net->getLayerAt(this->position-1);
}

bool Layer_Iterator::isEnd() {
  return this->position >= this->net->size();
}
