#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
using namespace std;

class Event{
    public:
    string _description;
    int _pathType;
    int _advisorID;
    int _pridePoints;
    
    public:

    Event();
    Event(string d, int pt, int a, int pp );

    string getDescription();
    int getPath();
    int getAdID();
    int getPP();
    string getDes();


    


};

#endif 