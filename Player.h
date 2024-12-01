#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Board.h"
#include "Advisor.h"
using namespace std;

class Player {
private:
    string _name;
    int _stamina;
    int _wisdom;
    int _pride_points;
    int _strength;  // Added strength (missing in your initial code)
    int _age;
    
    Advisor _advisor;
    bool _hasAdvisor = false;
   


public:
    // Constructors
    Player();  // Default constructor
    Player(string name, int strength, int stamina, int wisdom, int age, int pridePoints);

    // Getters
    string getName();
    int getStrength();
    int getStamina();
    int getWisdom();
    int getPridePoints();
    int getAge();
    bool checkAdvisor();
  
    

    // Setters
    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);
    void editAdvisor(bool hasAdvisor);
    void  prideChange (int pridePoints);
    // void assignAdvisor(string advisorName, int advisorBoost);

    // Other Methods
    void trainCub(int strength, int stamina, int wisdom);
    void train(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();
    //void chooseAdvisor():

    Advisor getAdvisor();

    void setAdvisor ( Advisor advisor);

     void chooseAdvisor(int);

     void printAdvisor();


    
};

#endif


