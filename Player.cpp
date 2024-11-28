// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <string>
// #include "Player.h"
// using namespace std;

// Player::Player()
// {
//     _name=""
//     _strength= 0;
//     _stamina = 0;
//     _wisdom =0;
//     _pride_points;
//     _age=0;
// }

// Player:: Player(string name, int strength, int stamina, int wisdom){
//     _name= name;
//     if(strength < 100 || strength >1000){
//         _strength=100;
//     }else{
//         _strength= strength;
//     }

//     if(stamina < 100 || stamina >1000){
//         _stamina=100;
//     }else{
//         _stamina= stamina;
//     }

//     if(wisdom < 100 || wisdom >1000){
//         _wisdom=100;
//     }else{
//         _wisdom= wisdom;
//     }

//     _pride_points =0;
//     _age=1;


            
//     }

// string Player:: getName(){
// return _name;
// }

// int Player:: getStrength(){
//    return _strength;
// }

// int Player:: getStamina(){
//    return _stamina;
// }

// int Player :: getWisdome(){
// return _wisdom;
// }

// int Player :: getPridePoints(){
//     return _pride_points;
// }

// int Player :: getAge() {
//     return _age;
// }

// void Player:: setName(string name){
//     _name = name;
// } 

// void Player :: setStrength(int strength){
//     _strength= strength;
// }

// void Player :: setStamina(int stamina){
//     _stamina = stamina;
// }

// void Player:: setWisdom(int wisdom){
//     _wisdom= wisdom;
// }

// void Player:: setPridePoints(int pride_points){
//     _pride_points= pride_points;
// }

// void Player :: setAge(int age){
//     _age= age;
// }

// void Player:: trainCub(int strength, int stamina, int wisdom){
//     _strength+= strength;
//     _stamina += stamina;
//     _wisdom += wisdom;
//     _pride +=-50000;
// }

// void Player:: toPrideLands(){
//     _pride+= 5000;
//     _strength+= -2000;
//     _widsom+= -2000;
//     _stamina += -1000;
// }

// void Player:: printStats(){
// cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
//     cout<< _name << "," << "age: " << _age << endl;
//     cout<< "Strength: " << _strength << endl;
//     cout<< "Stamina: " << _stamina << endl;
//     cout<< "Wisdom: " << _wisdom << endl;
//     cout << "Pride Points: " << _pride_points<< endl;
//  cout<< "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;


// }







#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Player.h"
using namespace std;

Player::Player()
{
    _name = "";
    _strength = 0;
    _stamina = 0;
    _wisdom = 0;
    _pride_points = 0;  // Initialize pride_points
    _age = 0;
}

Player::Player(string name, int strength, int stamina, int wisdom, int age)
{
    _name = name;
    
    // Bounds check for strength, stamina, wisdom
    if (strength < 100 || strength > 1000) {
        _strength = 100;  // Default to 100 if out of range
    } else {
        _strength = strength;
    }

    if (stamina < 100 || stamina > 1000) {
        _stamina = 100;  // Default to 100 if out of range
    } else {
        _stamina = stamina;
    }

    if (wisdom < 100 || wisdom > 1000) {
        _wisdom = 100;  // Default to 100 if out of range
    } else {
        _wisdom = wisdom;
    }

    _pride_points = 0;  // Initialize pride_points
    _age = age;
}

string Player::getName() {
    return _name;
}

int Player::getStrength() {
    return _strength;
}

int Player::getStamina() {
    return _stamina;
}

int Player::getWisdom() {
    return _wisdom;
}

int Player::getPridePoints() {
    return _pride_points;
}

int Player::getAge() {
    return _age;
}

string Player::getAdvisor(){
    return _advisorName;
}

int Player:: getBoost();
retrun _advisorBoost;

void Player::setName(string name) {
    _name = name;
}

void Player::setStrength(int strength) {
    _strength = strength;
}

void Player::setStamina(int stamina) {
    _stamina = stamina;
}

void Player::setWisdom(int wisdom) {
    _wisdom = wisdom;
}

void Player::setPridePoints(int pride_points) {
    _pride_points = pride_points;
}

void Player::setAge(int age) {
    _age = age;
}

void Player:: assignAdvisor(advisorName, boost){
     _advisorName = advisorName;
     _advisorBoost = boost;
     cout<< _name << " advisor is "<< _advisorName <<endl; 
}

void Player::trainCub(int strength, int stamina, int wisdom) {
    // Increase stats when training
    cout<< "You have entered Cub training"<< endl;
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
    _pride_points -= 5000;  // Decrease pride_points (check if this is intentional)
    cout<< "YOUR NEW STATS!"<< endl;
    printStats();
    cout<< " "<< endl;

}

void Player::toPrideLands() {
    // Journey to Pride Lands reduces stats and gains pride_points
    cout<< "You have entered the Pride Lands"<< endl;
     cout<< " "<< endl;
    _pride_points += 5000;  // Gain pride points
    _strength -= 2000;  // Reduce strength
    _wisdom -= 2000;  // Reduce wisdom
    _stamina -= 1000;  // Reduce stamina
    cout<< "YOUR NEW STATS!"<< endl;
     printStats();
    cout<< " "<< endl;
}


void Player::printStats() {
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << _name << "," << " age: " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout<< " "<< endl;
}


void Player::chooseAdvisor() {
    vector<Player> advisors = {
        {"Wise Owl", "A sage who imparts wisdom.", "Wisdom", 5},
        {"Strong Buffalo", "A mighty protector.", "Strength", 5},
        {"Agile Cheetah", "Quick and nimble.", "Stamina", 5},
        {"Kind Meerkat", "Inspires loyalty and pride.", "Pride Points", 10}
    };

    cout << "Welcome to Cub Training! Choose your advisor: ";
    for (int i = 0; i < advisors.size(); i++) {
        cout << i + 1 << ". ";
        advisors[i].printInfo();
    }

    int choice;
    cin >> choice;

    if (choice >= 1 && choice <= advisors.size()) {
        assignAdvisor(advisors[choice - 1]);  // Assign the chosen advisor
    } else {
        cout << "Invalid choice. Try again.\n";
        chooseAdvisor();  // Retry until valid choice
    }
}



