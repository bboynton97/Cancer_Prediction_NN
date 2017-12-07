//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Preprocessor.h"

//Constructor
Preprocessor::Preprocessor() : dataFile("xor.csv", std::ios::in) { //"breast-cancer-honors.csv", std::ios::in) {

}

Preprocessor::~Preprocessor() {

}

bool Preprocessor::isFinished() {
  return this->dataFile.eof();
}

std::vector<int> * Preprocessor::getNextData() {
    std::string line;
    std::getline(dataFile, line);
    std::stringstream stream(line);

    std::string input;
    stream >> input;
    input = input + ",";

    //Split it into substrings
    std::vector<std::string> inputs_s;
    while (input.find(',') != std::string::npos) { //While there are commas in the string
      std::string sub = input.substr(0, input.find(',')); //Get the first substring
      inputs_s.push_back(sub); //Enqueue that sub
      input.erase(0, input.find(',') + 1); //Erase that sub from the exp string
    }

    //convert those to ints
    std::vector<int> * data = new std::vector<int>();
    for (int i=0; i<inputs_s.size(); i++) {
      data->push_back(std::stoi(inputs_s.at(i)));
    }

    // std::vector<int> features;
    // for (int i=0; i<inputs.size()-1; i++) {
    //   features.push_back(inputs[i]);
    // }
    //
    // std::vector<int> label = inputs[inputs.size()-1];
    //
    // std::vector<std::vector<int>> * data;
    // data->push_back(features);
    // data->push_back(label);

    return data;
}
