//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#include "Preprocessor.h"

//Constructor
Preprocessor::Preprocessor(std::string filename) {
  this->dataFile.open(filename);
}

Preprocessor::~Preprocessor() {

}

int Preprocessor::getNextInputs(std::vector<float> &inputs)
{
    inputs.clear();

    std::string line;
    std::getline(dataFile, line);
    std::stringstream stream(line);

    std::string label;
    stream >> label;
    if (label.compare("in:") == 0) {
        float oneValue;
        while (stream >> oneValue) {
            inputs.push_back(oneValue);
        }
    }

    return inputs.size();
}
