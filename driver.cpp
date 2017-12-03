//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include <iostream>
#include <vector>
#include "Abstract_Builder.h"
#include "Builder.h"
#include "Net.h"
#include "Preprocessor.h"

#define _LEARNING_RATE_ 0.1
#define _ALPHA_ 0.5

int main (int argc, char * argv [])
{
  std::cout << "Welcome! Please enter the design of your neural network. Ex: '9,5,2'. Each number corresponds to a layer of nodes. The example has three layers with 9 nodes in the first layer, then 5, then 2.\n\nNote: Your design must begin with 9 nodes and end with 2 nodes in order to fit the dataset." << std::endl;

  std::string input;
  std::cout << "> ";
  std::getline(std::cin, input);
  input = input + ",";

  //Split it into substrings
  std::vector<std::string> inputs_s;
  while (input.find(',') != std::string::npos) { //While there are spaces in the string
    std::string sub = input.substr(0, input.find(',')); //Get the first substring
    inputs_s.push_back(sub); //Enqueue that sub
    input.erase(0, input.find(',') + 1); //Erase that sub from the exp string
  }

  //convert those to ints
  std::vector<int> inputs;
  for (int i=0; i<inputs_s.size(); i++) {
    inputs.push_back(std::stoi(inputs_s.at(i)));
  }

  //Use a builder to create the net with these instructions
  Abstract_Builder * builder = new Builder();
  for (int i=0; i<inputs.size(); i++) {
    if (i != inputs.size()-1) {
      builder->createLayer(inputs.at(i), inputs.at(i+1)); //Create a layer with that number of nodes and connections to the next layer
    } else {
      builder->createLayer(inputs.at(i), 0); //Create a layer with that number of nodes and no connections to next layer
    }
  }

  Net * net = builder->getNet();

  std::cout << "How many epochs would you like to train?" << std::endl;
  std::string input2;
  std::cout << "> ";
  std::getline(std::cin, input2);
  int epochs = std::stoi(input2);

  Preprocessor pp;

  for (int i=0; i<epochs; i++) {
    while(!pp.isFinished()) {
      std::vector<int> * data = pp.getNextData();

      std::vector<int> * features;
      for (int i=0; i<data->size()-1; i++) {
        features->push_back(data->at(i));
      }

      std::cout << "Inputs : ";
      for (int i=0; i<features->size(); i++) {
        std::cout << features->at(i) << ", ";
      }
      std::cout << std::endl;

      std::vector<int> * label;
      label->push_back(data->at(data->size()-1));
      delete data;

      net->feedForward(features);
      std::vector<float> * results = net->getResults();

      std::cout << "Output : ";
      for (int i=0; i<results->size(); i++) {
        std::cout << results->at(i) << ", ";
      }
      std::cout << std::endl;

      net->backProp(label);

      std::cout << "Net recent average error: " << net->getAvgError() << std::endl;
    }
  }

  return 0;
}
