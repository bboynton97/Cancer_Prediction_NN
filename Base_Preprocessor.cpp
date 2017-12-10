#include "Base_Preprocessor.h"

Base_Preprocessor::Base_Preprocessor() {
  this->isEnd = false;
}

Base_Preprocessor::~Base_Preprocessor() {

}

void Base_Preprocessor::restart() {
  this->dataFile.clear();
  this->dataFile.seekg(0, std::ios::beg);
  this->isEnd = false;
}

bool Base_Preprocessor::isFinished() {
  //return this->dataFile.eof();
  //return !this->dataFile.good();
  //return this->dataFile.bad();
  //return this->dataFile.eof() && !this->dataFile.good() && this->dataFile.bad();
  return this->isEnd;
}

std::vector<int> Base_Preprocessor::getNextData(bool & isEnd) {
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

    try {
      int num = std::stoi(inputs_s.at(0));
    } catch (std::invalid_argument) {
      isEnd = true;
      this->isEnd = true;
    }

    std::vector<int> data;
    if (!isEnd) {
      //convert those to ints
      for (int i=0; i<inputs_s.size(); i++) {
        data.push_back(std::stoi(inputs_s.at(i)));
      }
    }

    return data;
}
