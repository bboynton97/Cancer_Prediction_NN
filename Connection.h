//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//brboynto

#ifndef _CONNECTION_H_
#define _CONNECTION_H_

class Connection {
public:
  Connection();
  ~Connection();
  float getWeight();
  float getDeltaWeight();
  void setWeight(float weight);
  void setDeltaWeight(float deltaWeight);

private:
  float weight;
  float deltaWeight;
};

#endif
