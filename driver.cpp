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

int main (int argc, char * argv [])
{
  std::srand((unsigned)time(0));

  std::cout << "Welcome! Please enter the design of your neural network. Ex: '9,5,1'. Each number corresponds to a layer of nodes. The example has three layers with 9 nodes in the first layer, then 5, then 1.\n\nNote: Your design must begin with 9 nodes and end with 2 nodes in order to fit the dataset." << std::endl;

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

  if (inputs.back() != 1) {
    throw std::out_of_range("Last layer must have a size of 1 node");
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

  //TODO: Maybe use the iterator pattern here
  //int line = 0;
  for (int e=0; e<epochs; e++) {
    std::cout << "\n***********\n" << "* Epoch " << e+1 << " *\n" << "***********\n" << std::endl;
    Preprocessor pp;
    //while(!pp.isFinished()) {
    for (int line = 0; line<699; line++) {
    //for (int line = 0; line<700; line++) {

      std::vector<int> * data = pp.getNextData();

      std::vector<int> * features = new std::vector<int>();;
      for (int i=0; i<data->size()-1; i++) {
        features->push_back(data->at(i));
      }

      //Print the dataset inputs
      //std::cout << "Inputs : ";
      //for (int i=0; i<features->size(); i++) {
      //  std::cout << features->at(i) << ", ";
      //}
      //std::cout << std::endl;

      std::vector<int> * label = new std::vector<int>();
      label->push_back(data->at(data->size()-1));

      delete data;

      net->feedForward(features);

      std::vector<float> * results = net->getResults();

      //Print the output the NN got
      // std::cout << "Output : ";
      // for (int i=0; i<results->size(); i++) {
      //   std::cout << results->at(i) << ", ";
      // }
      // std::cout << std::endl;

      //std::cout << "~~ Iteration: " << line << " ~~ " << std::endl;

      net->backProp(label);

      //std::cout << "--> Last accuracy: " << 1-net->getError() << std::endl;

      if (line % 100 == 0 && line >= 100) { //Print stats about every 100 rows trained
        std::cout << "~~ Iteration: " << line << " ~~ " << std::endl;
        //std::cout << "  > Outputs: " << results->at(0) << std::endl;
        //std::cout << "  > Target: " << label->at(0) << std::endl;

        //std::cout << "--> Last accuracy: " << 1-net->getError() << std::endl;
        //std::cout << "*-> Last error: " << net->getError() << std::endl;

        std::cout << "--> Past 100 rows average error: " << net->getAvgError() << std::endl;
        std::cout << "--> Past 100 rows average accuracy: " << 1-net->getAvgError() << "\n\n" << std::endl;
      }
    }
  }

  std::cout << "\n\n--------------------------------" << std::endl;
  std::cout << "       Training Finished        " << std::endl;
  std::cout << "--------------------------------" << std::endl;

  std::string inference_s;

  while (inference_s != "QUIT") {
    std::cout << "\nInput inferencing data" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, inference_s);

    if (inference_s == "QUIT") {
      break;
    }

    inference_s = inference_s + ",";

    std::vector<std::string> inference_s_v = std::vector<std::string>();
    while (inference_s.find(',') != std::string::npos) { //While there are spaces in the string
      std::string sub = inference_s.substr(0, inference_s.find(',')); //Get the first substring
      inference_s_v.push_back(sub); //Enqueue that sub
      inference_s.erase(0, inference_s.find(',') + 1); //Erase that sub from the exp string
    }

    //convert those to ints
    std::vector<int> * inference = new std::vector<int>();
    for (int i=0; i<inference_s_v.size(); i++) {
      inference->push_back(std::stoi(inference_s_v.at(i)));
    }

    net->feedForward(inference);
    //delete inference;

    std::vector<float> * results = net->getResults();

    //Print the output the NN got
    std::cout << "Output : ";
    for (int i=0; i<results->size(); i++) {
      if (i != results->size()-1) {
        std::cout << results->at(i) << ", ";
      }
      std::cout << results->at(i) << std::endl;
    }
    //delete results;
    std::cout << std::endl;

    //delete results;
    //delete inference;
  }

  //delete net;

  return 0;
}
