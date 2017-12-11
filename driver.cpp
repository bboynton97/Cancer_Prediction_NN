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
#include "Base_Preprocessor.h"
#include "XOR_Preprocessor.h"
#include "Cancer_Preprocessor.h"
#include <memory>
#include "brandon_print.h"

int main (int argc, char * argv [])
{
  std::srand((unsigned)time(0)); //Set random seed value right away so it's out of the way

  std::string dataset_s;
  Brandon_Print brandon = Brandon_Print(); //checkout this class... you're in for a treat
  brandon.brandon_printf("\n\n---------------------------------------------\n\nWould you like the XOR dataset (1) or the Breast Cancer dataset (2)?\n> ");

  std::getline(std::cin, dataset_s);

  Base_Preprocessor * pp;

  int dataset = 0;
  try {
    dataset = std::stoi(dataset_s);
  } catch (std::invalid_argument) { } //Gets handled below

  if (dataset == 1) { //In this project, each dataset has it's own preprocessor to get the data
    pp = new XOR_Preprocessor(); //Assign XOR_Preprocessor pointer to Base_Preprocessor
    std::cout << "Please enter the design of your neural network. Ex: '2,2,1'. Each number corresponds to a layer of nodes. The example has three layers with 2 nodes in the first layer, then 2, then 1.\n\nNote: Your design must begin with 2 nodes and end with 1 node in order to fit the dataset." << std::endl;
  } else if (dataset == 2) {
    pp = new Cancer_Preprocessor(); //Assign Cancer_Preprocessor pointer to Base_Preprocessor
    std::cout << "Please enter the design of your neural network. Ex: '9,5,1'. Each number corresponds to a layer of nodes. The example has three layers with 9 nodes in the first layer, then 5, then 1.\n\nNote: Your design must begin with 9 nodes and end with 1 node in order to fit the dataset." << std::endl;
  } else {
    std::cout << "That is not a valid input. Defaulting to XOR." << '\n';
    std::cout << "Please enter the design of your neural network. Ex: '9,5,1'. Each number corresponds to a layer of nodes. The example has three layers with 9 nodes in the first layer, then 5, then 1.\n\nNote: Your design must begin with 9 nodes and end with 1 node in order to fit the dataset." << std::endl;
    pp = new XOR_Preprocessor();
  }


  std::string input;  //Get the model data for the shape of the NN
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
  try {
    for (int i=0; i<inputs_s.size(); i++) {
      int val = std::stoi(inputs_s.at(i));
      if (val > 10) {
        std::cout << "In this use-case, a layer of more than 10 nodes is not practical. Setting value to 10." << '\n';
        val = 10;
      }
      inputs.push_back(val);
    }
  } catch (std::invalid_argument) {
    std::cout << "Invalid input. Defaulting." << '\n';
    inputs.push_back(0);
  }

  //User input validation
  int inCount = pp->getInputCount();
  if (inputs.at(0) != inCount) {
    std::cout << "** Your network must start with a layer of " << inCount << " nodes. Your net has been modified to fit that." << '\n';
    inputs.at(0) = inCount;
  }

  if (inputs.size() < 3) {
    int hiddenCount = (int)(inCount/2) + 1;
    std::cout << "** Your network must have at least 3 layers. Defaulting to " << inCount << "," << hiddenCount << ",1" << '\n';
    inputs.clear();
    inputs.push_back(inCount);
    inputs.push_back(hiddenCount);
    inputs.push_back(1);
  }

  if (inputs.back() != 1) { //In case the user doesn't listen to the instructions
    std::cout << "** Last layer must have a size of 1 node. Your net has been modified to fit that." << '\n';
    inputs.back() = 1;
  }

  //Use a builder to create the net with these instructions
  std::shared_ptr<Abstract_Builder> builder (new Builder());
  for (int i=0; i<inputs.size(); i++) {
    if (i != inputs.size()-1) {
      builder->createLayer(inputs.at(i), inputs.at(i+1)); //Create a layer with that number of nodes and connections to the next layer
    } else { //For last layer
      builder->createLayer(inputs.at(i), 0); //Create a layer with that number of nodes and no connections to next layer
    }
  }

  std::shared_ptr<Net> net (builder->getNet()); //Get net from builder

  std::cout << "How many epochs would you like to train?" << std::endl;
  std::string input2;
  std::cout << "> ";
  std::getline(std::cin, input2);

  int epochs = 1;
  try {
    epochs = std::stoi(input2);
  } catch (std::invalid_argument) {
    std::cout << "Invalid input. Defaulting to 1 epoch." << '\n';
  }

  // For the number of epochs (full runthrough of the dataset)
  for (int e=0; e<epochs; e++) {
    std::cout << "\n***********\n" << "* Epoch " << e+1 << " *\n" << "***********\n" << std::endl;
    //pp->restart(); // Restart the preprocessor (almost works as iterator)
    //int line = 0;

    //while(!pp->isFinished()) { //While the file hasn't ended
      //line++;
    for (pp->restart(); !pp->isFinished(); pp->next()) {
      bool isEnd = false; // Apparently eof isn't a great way to check for end of file, so doing it here too
      int line = pp->getLine();
      std::vector<int> data = pp->getData();//isEnd); //Get each row of data

      //if (!isEnd) { //If it's not the last datapoint
        std::vector<float> features; // Get the features (inputs)
        for (int i=0; i<data.size()-1; i++) {
          features.push_back(data.at(i) / pp->largestVal()); //Make that a ratio of possible vals
        }

        std::vector<int> label = std::vector<int>();
        label.push_back(data.at(data.size()-1)); // Get the label (correct answer from inputs)

        net->feedForward(features); //Feed the features into the NN
        //std::vector<float> results = net->getResults(); //We can get the results if we want to see them here
        net->backProp(label); //Send in the real value and have backpropegation train the NN to be a better fit
      //}

      if (line % 100 == 0 && line >= 100) { //Print stats about every 100 rows trained
        std::cout << "~~ Iteration: " << line << " ~~ " << std::endl;
        std::cout << "--> Past 100 rows average error: " << net->getAvgError() << std::endl;
        std::cout << "--> Past 100 rows average accuracy: " << 1-net->getAvgError() << "\n\n" << std::endl;
      }
    }
  }



  std::cout << "\n\n--------------------------------" << std::endl;
  std::cout << "       Training Finished        " << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << "\nEnter QUIT when finished inferencing." << '\n';

  // Time to inference! There is where you get to send new data in to see what the NN predicts
  std::string inference_s;

  while (inference_s != "QUIT") {
    std::cout << "\nInput inferencing data" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, inference_s);

    if (inference_s == "QUIT") {
      break;
    }

    //Convert the input string into a readable integer vector
    inference_s = inference_s + ",";
    std::vector<std::string> inference_s_v = std::vector<std::string>();
    while (inference_s.find(',') != std::string::npos) { //While there are spaces in the string
      std::string sub = inference_s.substr(0, inference_s.find(',')); //Get the first substring
      inference_s_v.push_back(sub); //Enqueue that sub
      inference_s.erase(0, inference_s.find(',') + 1); //Erase that sub from the exp string
    }

    //convert those to ints
    std::vector<float> inference;
    try {
      for (int i=0; i<inference_s_v.size(); i++) {
        inference.push_back(std::stoi(inference_s_v.at(i)) / pp->largestVal()); //Make that a ration of vals
      }
    } catch (std::invalid_argument) {
      std::cout << "Invalid input." << '\n';
    }

    if (inference.size() > 0) {
      std::cout << '\n';

      net->feedForward(inference); //Feed the data forward

      std::vector<float> results = net->getResults(); //Get the result

      //Print the output the NN got
      std::cout << "Output : ";
      for (int i=0; i<results.size(); i++) {
        if (i != results.size()-1) {
          std::cout << results.at(i) << ", ";
        }
        std::cout << results.at(i) << std::endl;
      }
      std::cout << std::endl;
    }
  }
  delete pp;
  return 0;
}
