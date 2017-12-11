//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "../net/Net.h"

Net::Net() {

}

Net::~Net() {
  for (int i=0; i<this->layers.size(); i++) { //Delete all layers that belong to the net
    delete this->layers.at(i);
  }
}

void Net::feedForward(std::vector<float> inputs) { //This is what turns the inputs into a prediction

  // std::vector<float> inputs; //Convert everything to a float
  // for (int i=0; i<inputs_i.size(); i++) {
  //   inputs.push_back((int)inputs_i.at(i));
  // }

  //Give the input neurons initial input values
  for (int i=0; i<inputs.size(); i++) {
    this->layers[0]->getNodeAt(i)->setOutput(inputs[i]);
  }

  //Propegate data through each layer then each node using iterators
  Base_Layer_Iterator * layerIterator = new Layer_Iterator(*this);

  for (layerIterator->begin(); !layerIterator->isEnd(); layerIterator->next()) {
    Base_Node_Iterator * nodeIterator = new Node_Iterator(*layerIterator->getLayer());
    for (nodeIterator->begin(); !nodeIterator->isEnd(); nodeIterator->next()) {
      nodeIterator->getNode()->feedForward(layerIterator->getLastLayer());
    }
    delete nodeIterator;
  }

  delete layerIterator;
}

void Net::backProp(std::vector<int> targets_i) { //This is what adjusts values in the NN to better fit it to the data

  std::vector<float> targets = std::vector<float>();
  for (int i=0; i<targets_i.size(); i++) {
    targets.push_back((int)targets_i.at(i));
  }

  // Loss function
  // We need to see how far we are off from the intended value and adjust the net to fit that
  // Using Root Mean Square loss function

  Abstract_Layer * lastLayer = this->layers.back();
  this->error = 0.0;

  //Loop through all nodes in the last layer
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

std::vector<float> Net::getResults() {
  std::vector<float> results;
	for (int i = 0; i < this->layers.back()->size() - 1; i++) {
		results.push_back(this->layers.back()->getNodeAt(i)->getOutput());
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

Abstract_Layer * Net::getLayerAt(int index) {
  return this->layers.at(index);
}

int Net::size() {
  return this->layers.size();
}
