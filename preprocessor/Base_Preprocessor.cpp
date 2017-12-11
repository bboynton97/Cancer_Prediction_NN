#include "../preprocessor/Base_Preprocessor.h"

Base_Preprocessor::Base_Preprocessor() {
  this->isEnd = false;
}

Base_Preprocessor::~Base_Preprocessor() {

}

void Base_Preprocessor::restart() {
  this->dataFile.clear();
  this->dataFile.seekg(0, std::ios::beg);
  this->line = 0;
  this->isEnd = false;
  this->next();
}

bool Base_Preprocessor::isFinished() {
  return this->isEnd;
}

void Base_Preprocessor::next() { //Get the next line of data and save it
  this->line++;
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

  try { //If it's the end of the feed, it won't be stoi convertable
    int num = std::stoi(inputs_s.at(0));
  } catch (std::invalid_argument) {
    //isEnd = true;
    this->isEnd = true;
  }

  this->nextData.clear();
  if (!isEnd) {
    //convert those to ints
    for (int i=0; i<inputs_s.size(); i++) {
      this->nextData.push_back(std::stoi(inputs_s.at(i)));
    }
  }
}

std::vector<int> Base_Preprocessor::getData() { //return that data
  return this->nextData;
}

int Base_Preprocessor::getLine() {
  return this->line;
}
