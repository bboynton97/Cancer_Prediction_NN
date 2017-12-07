//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Net.h"

Net::Net() {

}

Net::~Net() {
  for (int i=0; i<this->layers.size(); i++) {
    delete this->layers.at(i);
  }
}

void Net::feedForward(std::vector<int> * inputs_i) {

  std::vector<float> inputs;// = std::vector<float> ();
  for (int i=0; i<inputs_i->size(); i++) {
    inputs.push_back((int)inputs_i->at(i));
  }

  delete inputs_i;

  //Give the input neurons initial input values

  for (int i=0; i<inputs.size(); i++) {
    this->layers[0]->getNodeAt(i)->setOutput(inputs[i]);
  }

  //Propegate data through each layer then each node
  //TODO: Add Iterator pattern here.

  for (int layerCount=1; layerCount<this->layers.size(); layerCount++) { // for every layer in net
    //std::cout<<"Should feed forward " << this->layers.size()-1 << " times" << std::endl;
    //std::cout<<"--FEEDING FORWARD ON LAYER-- " << layerCount << std::endl;
    for (int nodeCount=0; nodeCount<this->layers[layerCount]->size() - 1; nodeCount++) { //for every node in layer
      //std::cout<<"--FEEDING FORWARD ON NODE--"<<std::endl;
      this->layers[layerCount]->getNodeAt(nodeCount)->feedForward(this->layers[layerCount-1]); //Feed forward at node
    }
  }
}

void Net::backProp(std::vector<int> * targets_i) { //TODO: See if we can implement iterator or visitor pattern here

  std::vector<float> targets = std::vector<float>();
  for (int i=0; i<targets_i->size(); i++) {
    targets.push_back((int)targets_i->at(i));
  }
  delete targets_i;

  // Loss function
  // We need to see how far we are off from the intended value and adjust the net to fit that
  // Using Root Mean Square loss function

  Abstract_Layer * lastLayer = this->layers.back();
  this->error = 0.0;

  //for (int i=0; i<lastLayer->size(); i++) { //Loop through all nodes in the last layer
  for (int i=0; i<lastLayer->size()-1; i++) {
    float delta = targets.at(i) - lastLayer->getNodeAt(i)->getOutput(); //Get how far we were off for this node
    this->error += (delta * delta); //Add the square of that to error
  }

  this->error = this->error / (lastLayer->size() - 1); //Divide that by n-1
  this->error = sqrt(this->error); //Square root of that is RMS error

  //Get the gradients for the final layer
  for (int i=0; i<lastLayer->size(); i++) {
    lastLayer->getNodeAt(i)->calculateOutputGradients(targets[i]);
  }

  //Get the hidden layer's gradients
  for (int i = this->layers.size() - 2; i > 0; i--) { //All layers but first and last, going backwards (i.e. back propegation)
    Abstract_Layer * hiddenLayer = this->layers[i];
    Abstract_Layer * nextLayer = this->layers[i+1];

    for (int p = 0; p < hiddenLayer->size(); p++) {
      hiddenLayer->getNodeAt(p)->calculateHiddenGradients(nextLayer);
    }
  }

  // Update the connection weights so it can be more accurate next time it feeds Forward
  for (int i = this->layers.size() - 1; i > 0; i--) { // Loop through backwards again
		Abstract_Layer * layer = this->layers[i];
		Abstract_Layer * prevLayer = this->layers[i-1];

		for (int p = 0; p < layer->size() - 1; p++) { //Loop through it's nodes
			layer->getNodeAt(p)->updateInputWeights(prevLayer);
		}
	}

  this->avgError = (this->avgError * 100 + this->error) / (101); //Get the error over the past 10 rows
}

std::vector<float> * Net::getResults() {
  std::vector<float> * results = new std::vector<float>();

	for (int i = 0; i < this->layers.back()->size() - 1; i++) {
		results->push_back(this->layers.back()->getNodeAt(i)->getOutput());
	}

  return results;
}

void Net::addLayer(Abstract_Layer * layer) {
  this->layers.push_back(layer);
}

float Net::getAvgError() {
  return this->avgError;
}

float Net::getError() {
  return this->error;
}
