#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Player.h"
#include "Board.h"
#include "Advisor.h"
using namespace std;

Player::Player()
{
    _name = "";
    _strength = 0;
    _stamina = 0;
    _wisdom = 0;
    _pride_points = 0;  // Initialize pride_points
    _age = 0;
    Advisor _advisor;
    
    
}

Player::Player(string name, int strength, int stamina, int wisdom, int age, int pridePoints)
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

    _pride_points = pridePoints;  // Initialize pride_points
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

// string Player::getAdvisor(){
//     return _advisorName;
// }

// int Player:: getBoost(){
// return _advisorBoost;
// }

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

void Player:: prideChange(int pridePoints){
    _pride_points+= pridePoints;
     cout<< "YOUR NEW STATS!"<< endl;
     printStats();
    cout<< " "<< endl;

}


void Player::trainCub(int strength, int stamina, int wisdom) {
    // Increase stats when training
    cout<< "You have entered Cub training"<< endl;
    _strength += 500;
    _stamina += 500 ;
    _wisdom += 1000;
    _pride_points -= 5000;  // Decrease pride_points (check if this is intentional)
    cout<< "YOUR NEW STATS!"<< endl;
    printStats();
    cout<< " "<< endl;

}

void Player:: train(int strength, int stamina, int wisdom){
     _strength += strength;
    _stamina += stamina ;
    _wisdom += wisdom;
    cout<< "YOUR NEW STATS!"<< endl;
    printStats();
    cout << " "<< endl;

}

void Player::toPrideLands() {
    // Journey to Pride Lands reduces stats and gains pride_points
    cout<< "You have entered the Pride Lands"<< endl;
     cout<< " "<< endl;
    _pride_points += 5000;  // Gain pride points
    _strength += 200;  // gains strength
    _wisdom += 200;  // gains wisdom
    _stamina += 200;  // gains stamina
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

Advisor Player::getAdvisor() {
    return _advisor;  // Returns a copy of the assigned advisor
}

void Player::setAdvisor( Advisor advisor) {
    _advisor = advisor;  // Set the Advisor object by copying it into the Player's _advisor field
}

void Player::chooseAdvisor(int player) {
    // Set the advisor for the player
    setAdvisor(_advisor);  // Reuse the setAdvisor method from earlier to assign the advisor
    
}

void Player::printAdvisor() {
    // Get the advisor object for this player
     Advisor advisor = getAdvisor();  //have a getter like this

    // Print the advisor's information
    cout << "Your advisor is: " << advisor.getName() << endl;
    cout << "Advisor's ability: " << advisor.getAbility() << endl;
}

bool Player:: checkAdvisor(){
    return _hasAdvisor;
}

void Player:: editAdvisor(bool hasAdvisor){
    _hasAdvisor = hasAdvisor;
}


