#include "Base_Preprocessor.h"

Base_Preprocessor::Base_Preprocessor() {

}

Base_Preprocessor::~Base_Preprocessor() {
  
}

bool Base_Preprocessor::isFinished() {
  return this->dataFile.eof();
}

std::vector<int> * Base_Preprocessor::getNextData() {
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

    return data;
}
