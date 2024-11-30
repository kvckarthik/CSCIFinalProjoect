#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Advisor.h"
using namespace std;


// Default constructor
Advisor::Advisor(){
    _id = 0;
    _name = "";
    _ability = "";
    _chosen = false;
}

// Parameterized constructor
Advisor::Advisor(int id, string name, string ability) {
    _id = id;
    _name = name;
    _ability = ability;
    _chosen = false;
}

int Advisor::getID() {
    return _id;
}

string Advisor::getName() {
    return _name;
}

string Advisor::getAbility() {
    return _ability;
}

bool Advisor::isChosen() const {
    return _chosen;
}

void Advisor::setChosen(bool chosen) {
    _chosen = chosen;
}

void Advisor::printAdvisor() {
    cout << "Advisor: " << _name << " - " << _ability << endl;
}
