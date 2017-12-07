//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Node.h"

Node::Node(int hm_connections, int index) { //: outputValue (0.0) {
  this->index = index;
  this->hm_outputs = hm_connections;

  //this->outputValue = 0; //Set initial output

  //std::srand((unsigned)time(0));
  for (int i=0; i<hm_connections; i++) {
    Connection * connection = new Connection();

    int random_integer = std::rand() % 100;
    float random_float = (float)random_integer / 100;

    //std::cout << "Node initialized with " << random_float << std::endl;

    connection->setWeight(random_float);
    this->outputConnections.push_back(connection);
  }
}

Node::~Node() {
  //Delete all connections
  for (int i=0; i<this->outputConnections.size(); i++) {
   delete this->outputConnections.at(i);
  }
}

void Node::feedForward(Abstract_Layer * lastLayer) {
  // This is a simple (deep) neural network, so we're only going to use a simple activation function.
  // The math behind this is simple (this is what I do for my job, albeit using libraries)
  // The output value is equal to the summation of each input multiplied by it's weight.
  //
  // Normally, that would be multiplied by a bias here too, but for the sake of simplicity (and because this is
  // being written from scratch and not with a library), I'm not going to add the bias.

  //std::cout<<"Old output: " << this->getOutput()<<std::endl;

  float summation = 0.0;
  for (int i=0; i<lastLayer->size(); i++) {
    float input = lastLayer->getNodeAt(i)->getOutput(); //This node's current bias
    float weight = lastLayer->getNodeAt(i)->getConnectionAt(this->index)->getWeight(); //Get the weight from that node to this node

     // if (i == 0) {
     //  std::cout<<"- Node index: " << lastLayer->getNodeAt(i)->getIndex() <<std::endl;
     //   std::cout<<"Input : " << input <<std::endl;
     //   std::cout<<"Weight: " << weight <<std::endl;
     // }

    summation += (input * weight);
  }

  //std::cout<<"Calculated new value: " << summation <<std::endl;

  //std::cout<<"Setting output after activation function: "<<this->activationFunction(summation)<<std::endl;

  this->outputValue = this->activationFunction(summation);
}

void Node::setOutput(float value) {
  this->outputValue = value;
}

float Node::getOutput() {
  return this->outputValue;
}

Connection * Node::getConnectionAt(int index) {
  return this->outputConnections[index];
}

float Node::activationFunction(float val) {
  // This is what turns the output into something readable. Ideally, we would use a softmax activation function
  // because that would give us values that add up to 1 (showing the confidence level as well as the result)
  // but for the sake of time, we will use tanh() because it forces the values to be between -1 and 1.

  return tanh(val); //See how easy that is?

  // Softmax, while definitely the most popular activation function today, would require a bit more math.
  // Something like: result[node] = e^node_val / summation(e^node_vals)
  // Which would require a decent bit of restructuring

  //TODO: Add softmax if time permits
}

float Node::activationFunctionDerived(float val) {
  return (1 - (tanh(val) * tanh(val))); //Derivitive of tanh
  //Btw, neural networks are the only code I've written that actually use even a minute portion of the math classes they make us take.
}

void Node::calculateOutputGradients(float targetVal) {
  float delta = targetVal - this->outputValue;
  this->gradient = delta * this->activationFunctionDerived(this->outputValue);
}

void Node::calculateHiddenGradients(Abstract_Layer * nextLayer) {
  float summation = 0.0;

	for (int i = 0; i < nextLayer->size() - 1; i++)
	{
		summation += this->outputConnections[i]->getWeight() * nextLayer->getNodeAt(i)->getGradient();
	}

  this->gradient = summation * this->activationFunctionDerived(this->outputValue);
}

float Node::getGradient() {
  return this->gradient;
}

void Node::updateInputWeights(Abstract_Layer * previousLayer) {
  // Adjust the weights in the connections between this layer and the one before it

  float _LEARNING_RATE_ = 0.15;
  float _ALPHA_ = 0.5;

  for (int i = 0; i < previousLayer->size(); i++) {
		Abstract_Node * node = previousLayer->getNodeAt(i);
		float oldDeltaWeight = node->getConnectionAt(this->index)->getDeltaWeight();

    // Learning Rate: How much should each example in the dataset effect the NN? Too high and every row will completely retrain the NN. Too low and the NN won't learn much from each example.

    // Alpha: How much of the old Delta do we want to keep? We don't want to completely get rid of past data, but if we want to get more accurate, then we have to throw away some of it.

		float newDeltaWeight = (_LEARNING_RATE_ * node->getOutput() * this->gradient) + (_ALPHA_ * oldDeltaWeight);

		node->getConnectionAt(this->index)->setDeltaWeight(newDeltaWeight);
    node->getConnectionAt(this->index)->setWeight(node->getConnectionAt(this->index)->getWeight() + newDeltaWeight);
	}
}

int Node::getIndex() {
  return this->index;
}
