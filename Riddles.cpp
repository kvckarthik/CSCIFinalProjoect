#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Riddles.h"
using namespace std;

Riddles::Riddles(){
    _riddleQ = "";
    _riddleA = "";
}

Riddles:: Riddles(string quetion, string answer){
    _riddleQ= quetion;
    _riddleA= answer;
}

string Riddles:: getQuetion(){
    return _riddleQ;
}

string Riddles:: getAnswer(){
    return _riddleA;
}

void Riddles:: setQuetion(string quetion){
    _riddleQ = quetion;
}

void Riddles:: setAnswer (string answer){
    _riddleA = answer;
}