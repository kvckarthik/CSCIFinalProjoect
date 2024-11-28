#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Game.h"
using namespace std;

Game::Game() {

    _player_count= MAX_PLAYER; // initilize game to default settings
}


void Game::whichCharacter() {
    cout << "PLAYERS CHOOSE YOUR LION!" << endl;

    ifstream file("character.txt");
    vector<Player> lions;  // Use Player type
    string line;

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Read from file and populate lions vector
    while (getline(file, line)) {
        stringstream ss(line);
        string name, temp;
        int age, strength, stamina, wisdom, pridePoints;

        getline(ss, name, '|');
        getline(ss, temp, '|'); age = stoi(temp);
        getline(ss, temp, '|'); strength = stoi(temp);
        getline(ss, temp, '|'); stamina = stoi(temp);
        getline(ss, temp, '|'); wisdom = stoi(temp);
        getline(ss, temp, '|'); pridePoints = stoi(temp);

        lions.push_back(Player(name, strength, stamina, wisdom, age));
    }
    file.close();

    int chosen_tracks[MAX_PLAYER];

    // Players take turns selecting lions
    for (int c = 0; c < _player_count; c++) {
        cout << "Available lions: " << endl;

        // Display available lions
        for (int i = 0; i < lions.size(); i++) {
            cout << i + 1 << ". " << lions[i].getName()
                 << " Age: " << lions[i].getAge()
                 << ", Strength: " << lions[i].getStrength()
                 << ", Stamina: " << lions[i].getStamina()
                 << ", Wisdom: " << lions[i].getWisdom()
                 << ", Pride Points: " << lions[i].getPridePoints() << endl;
            cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        }

        int choice;
        cout << "Player " << c + 1 << ", select your lion by entering the number next to their name: ";
        cin >> choice;

        // Validate choice
        if (choice < 1 || choice > lions.size()) {
            cout << "INVALID CHOICE! Please try again." << endl;
            c--;  // Retry the same player
            continue;
        }

        // Assign selected lion to the current player
        _player[c] = lions[choice - 1];
        cout << "Player " << c + 1 << " chose: " << _player[c].getName() << endl;

        // Display stats of the selected lion
        _player[c].printStats();

        // Remove the selected lion from the available list
        lions.erase(lions.begin() + (choice - 1));

         cout << "Player " << c + 1 << ", choose your path:" << endl;
        cout << "0: Cub Training 1: Pride Lands" << endl;
        cin >> chosen_tracks[c];

          while (chosen_tracks[c] != 0 && chosen_tracks[c] != 1) {
            cout << "Invalid choice. Please enter 0 for Cub Training or 1 for Pride Lands: ";
            cin >> chosen_tracks[c];
        }
        if (chosen_tracks[c] == 0){
                
                _player[c].trainCub(_player[c].getStrength(), _player[c].getStamina(), _player[c].getWisdom());
                //_player[c].chooseAdvisor();

            }else{
                _player[c].toPrideLands();
            }
    }
            

    _board = Board(_player_count, chosen_tracks);
    
    cout << "Both players have chosen their lions and selected there paths!" << endl;
}






void Game::startGame() {
    string enter;
    cout << "Welcome to the Circle of Life!" << endl;
    cout << "Press Enter to continue." << endl;
    getline(cin, enter);

    cout << "Rules of the game:" << endl;
    cout << "You will travel across the African Savannah as a young lion to prove your strength." << endl;
    cout << "Press Enter to continue." << endl;
    getline(cin, enter);

    whichCharacter(); // Allow players to choose characters

    cout << "Let the game begin!" << endl;

    _board.displayBoard();

    takeTurn();
    
}


    void Game::takeTurn(){
        bool gamePlay = true;
        int currentPlayer= 0;

        while (gamePlay){
            cout<< "Player" << (currentPlayer+1)<< "'s turn!" << endl;

        cout << "What would you like to do?" << endl;
        cout << "1. Check Player Progress" << endl;
        cout << "2. Review Character" << endl;
        cout << "3. Check Position" << endl;
        cout << "4. Review Your Advisor" << endl;
        cout << "5. Move Forward" << endl;
        //cout << "6. End Game" << endl;

        int choice;
        cin>> choice;

        switch(choice){
            case 1:
            cout<< "|++++++++++++++++++++++++++++++++|" << endl;
            cout << "  pridePoints: " << _player[currentPlayer].getPridePoints() << endl;
            cout<< "|++++++++++++++++++++++++++++++++|" << endl;
            cout << "  Leadership traits:" << endl;
            cout << "  Strength: " << _player[currentPlayer].getStrength() << endl;
            cout << "  Stamina: " << _player[currentPlayer].getStamina() << endl;
            cout << "  Wisdom: " << _player[currentPlayer].getWisdom() << endl;
            cout<< "|++++++++++++++++++++++++++++++++|" << endl;
            cout<< "" << endl;
            break;

            case 2:
            cout<< "|++++++++++++++++++++++++++++++++|" << endl;
            cout << "Name: " << _player[currentPlayer].getName()<< endl;
            cout << "Age: " << _player[currentPlayer].getAge()<< endl;
            cout<< "|++++++++++++++++++++++++++++++++|" << endl;
            break;

             //case 3:
             //cout<< _board.displayBoard()<< endl;
            // cout<< "Current position" << _player[currentPlayer].getPlayerPosition();
             //break;

            //case 4:
            
         }

        }

    //   this function is used to controll the game and have each player take turns playing
    // in this function the user is able to do 5 main things (this should most likely be done in a switch statment)
    // check the main menu (which will be its own function that I have no created yet)
//    1 . Check Player Progress: Review Pride Point and Leadership Trait stats.
// 2. Review Character: Check your character name and age.
// 3. Check Position: Display board to view current position.
// 4. Review your Advisor: Check who your current advisor is on the game.
// 5. Move Forward: For each player’s turn, access this option to spin the virtual spinner.
// be able to "roll a random number" and move through the boared

// how can I implement a way for each user to switch between playing while the game is going
    }

    void Game:: endgame(){

    }






