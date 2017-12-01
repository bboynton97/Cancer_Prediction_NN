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
    builder->createLayer(inputs.at(i)); //Create a layer with that number of nodes
  }

  Net * net = builder->getNet();

  return 0;
}
