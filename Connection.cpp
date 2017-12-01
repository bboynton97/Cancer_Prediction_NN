//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Connection.h"

Connection::Connection() {

}

Connection::~Connection() {

}

float Connection::getWeight() {
  return this->weight;
}

float Connection::getDeltaWeight() {
  return this->deltaWeight;
}

void Connection::setWeight(float weight) {
  this->weight = weight;
}

void Connection::setDeltaWeight(float deltaWeight){
  this->deltaWeight = deltaWeight;
}
