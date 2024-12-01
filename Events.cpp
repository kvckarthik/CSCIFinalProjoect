#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Event.h"
using namespace std;

Event::Event(){
     _description = " ";
     _pathType = 0;
    _advisorID = 0 ;
    _pridePoints = 0;

}

Event:: Event(string description, int pathType, int advisorId, int pridePoints ){
    _description = description;
     _pathType = pathType;
    _advisorID = advisorId;
    _pridePoints = pridePoints;
}

int Event:: getPath(){
    return _pathType;
}

int Event:: getAdID(){
    return _advisorID;
}

int Event:: getPP(){
    return _pridePoints;

}

string Event:: getDes(){
    return _description;
}