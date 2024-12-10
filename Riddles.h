#ifndef RIDDLES_H
#define RIDDLES_H

#include <string>
#include <iostream>
using namespace std;

class Riddles{
    private:
    string _riddleQ;
    string _riddleA;
    public:
    Riddles();
    Riddles(string q, string a);
    string getQuetion();
    string getAnswer();
    void setQuetion(string q);
    void setAnswer(string a);

};

#endif