

#ifndef ADVISOR_H
#define ADVISOR_H
#include <string>
#include <iostream>
using namespace std;

class Advisor{
    private:
        int _id;
        string _name;
        string _ability;
        bool _chosen;

    public:
        Advisor();  // Default constructor
        Advisor(int id, string name, string ability);  // Parameterized constructor
        string getName();
        string getAbility();
        int getID();
        bool isChosen() const;
        void setChosen(bool chosen);
        void printAdvisor();
};

#endif // ADVISOR_H
