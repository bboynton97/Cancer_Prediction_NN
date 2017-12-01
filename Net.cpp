//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Net.h"

Net::Net() {
  std::cout << "Created net" << std::endl;
}

Net::~Net() {

}

void Net::feedForward(std::vector<float> &inputs) {

}

void Net::backProp(std::vector<float> &targets) {

}

void Net::getResults() {

}

void Net::addLayer(Abstract_Layer * layer) {
  std::cout << "Added layer" << std::endl;
  this->layers.push_back(layer);
}
