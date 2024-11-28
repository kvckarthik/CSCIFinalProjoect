// #include<iostream>
// using namespace std;

// #ifndef PLAYER_H
// #define PLAYER_H

// class Player{
//     private:
//         string _name;
//         int _stamina;
//         int _wisdom;
//         int _pride_points;
//         int _age;
//     public:
//     //constructors
//         Player();
//         Player(string name, int strength, int stamina, int wisdom);
//         //setters
//         string getName();
//         int getStrength();
//         int getStamina();
//         int getWisdom();
//         int getPridePoints();
//         int getAge();
//         //getters
//         void setName(string name); 
//         void setStrength(int strength); 
//         void setStamina(int stamina); 
//         void setWisdom(int wisdom);
//         void setPridePoints(int pride_points);  
//         void setAge(int age);
//         //other
//         void trainCub(int strength, int stamina, int wisdom);
//         void toPrideLands();
//         void printStats(); 


// };

// #endif


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class Player {
private:
    string _name;
    int _stamina;
    int _wisdom;
    int _pride_points;
    int _strength;  // Added strength (missing in your initial code)
    int _age;
    //string _advisorName;
    int _advisorBoost;


public:
    // Constructors
    Player();  // Default constructor
    Player(string name, int strength, int stamina, int wisdom, int age);

    // Getters
    string getName();
    int getStrength();
    int getStamina();
    int getWisdom();
    int getPridePoints();
    int getAge();
    // string getAdvisor();
    // int getBoost();
    

    // Setters
    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);
    // void assignAdvisor(string advisorName, int advisorBoost);

    // Other Methods
    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();
    //void chooseAdvisor():
};

#endif


