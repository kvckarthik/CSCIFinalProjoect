#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Game.h"
using namespace std;

Game::Game() { // initilize game to default settings
 
    _player_count= MAX_PLAYER; 
     for (int i = 0; i < NUM_ADVISOR; ++i) {
            advisor[i] = Advisor(); // Use default constructor for each advisor
        }
}

void Game:: loadEvents (string file, Event event[]){

     ifstream inFile(file);
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file " << endl;
        return;
    }

    string line;
    int index = 0;

    while (getline(inFile, line) && index < NUM_EVENTS) {
        vector <string> tokens;
        stringstream ss(line);
        string token;

        // Split the line by '|'
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }

        // Ensure the line has exactly three parts: id, name, and ability
        if (tokens.size() == 4) {
            string description = tokens[0];  
            int pathType = stoi(tokens[1]); // converts second string to an interger
            int adID = stoi (tokens[2]);
            int prideP = stoi (tokens [3]);
            

            // Create and store the advisor
            event[index] = Event(description, pathType, adID, prideP);
            index++;
        } else {
            cout << "Warning: Skipping invalid line in file: " << endl;
        }
    }

    inFile.close();

    // Confirmation
    cout << "Events loaded successfully!"<< endl;
    
}




void Game::loadAdvisor(string file, Advisor arr[]) {
    ifstream inFile(file);
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file " << endl;
        return;
    }

    string line;
    int index = 0;

    while (getline(inFile, line) && index < NUM_ADVISOR) {
        vector <string> tokens;
        stringstream ss(line);
        string token;

        // Split the line by '|'
        while (getline(ss, token, '|')) {
            tokens.push_back(token);
        }

        // Ensure the line has exactly three parts: id, name, and ability
        if (tokens.size() == 3) {
            int id = stoi(tokens[0]);  // Convert first token to integer
            string name = tokens[1];
            string ability = tokens[2];

            // Create and store the advisor
            arr[index] = Advisor(id, name, ability);
            index++;
        } else {
            cout << "Warning: Skipping invalid line in file: " << endl;
        }
    }

    inFile.close();

    // Confirmation
    cout << "Advisors loaded successfully!"<< endl;
    
}


void Game::chooseAdvisor(int playing) {
    bool check = _player[playing].checkAdvisor();
    if (!check){
    bool validChoice = false;
    int advisorChoice;

    while (!validChoice) {
        cout << "Player " << (playing + 1) << ", choose your advisor: " << endl;

        // Display available advisors
        for (int j = 0; j < NUM_ADVISOR; j++) {
            cout << advisor[j].getID() << ". " << advisor[j].getName() 
                 << " - " << advisor[j].getAbility() << endl;
        }

        cout << "Enter the number corresponding to your choice: ";
        cin >> advisorChoice;

        // Validate choice
        if (advisorChoice >= 1 && advisorChoice <= NUM_ADVISOR) {
            // Check if the advisor is already chosen
            if (!advisor[advisorChoice - 1].isChosen()) {
                _player[playing].setAdvisor(advisor[advisorChoice - 1]);  // Assign advisor to player
                advisor[advisorChoice - 1].setChosen(true);  // Mark the advisor as chosen
                validChoice = true;
            } else {
                cout << "This advisor has already been chosen. Please select a different one.\n";
            }
        } else {
            cout << "Invalid choice. Please enter a valid advisor number.\n";
        }
    }

    // Display the chosen advisor
    cout << "Player " << (playing + 1) << " chose " << _player[playing].getAdvisor().getName()
         << " as their advisor with ability: " 
         << _player[playing].getAdvisor().getAbility() << endl;

    }
    cout<< "You have an advisor"<< endl;
    cout<< " "<< endl;
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

        lions.push_back(Player(name, strength, stamina, wisdom, age, pridePoints));
    }
    file.close();

    int chosen_tracks[MAX_PLAYER]; // Array to store each player's track choice

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

        // Choose the player's path
        cout << "Player " << c + 1 << ", choose your path:" << endl;
        cout << "0: Cub Training 1: Pride Lands" << endl;
        cin >> chosen_tracks[c];

        while (chosen_tracks[c] != 0 && chosen_tracks[c] != 1) {
            cout << "Invalid choice. Please enter 0 for Cub Training or 1 for Pride Lands: ";
            cin >> chosen_tracks[c];
        }

        // Perform action based on the chosen path
        if (chosen_tracks[c] == 0) {
            _player[c].trainCub(_player[c].getStrength(), _player[c].getStamina(), _player[c].getWisdom());
            chooseAdvisor(c);
            _player[c].editAdvisor(true);
 // You may add advisor selection here if needed
        } else {
            _player[c].toPrideLands();
        }

        // Assign the corresponding board for the player
        _board = Board(_player_count, chosen_tracks); // Assign individual board
    }

    cout << "Both players have chosen their lions and selected their paths!" << endl;
}



void Game:: triggerEvent(int player_Index, Player player){
    int postion = _board.getPlayerPosition(player_Index);
    char tileColor= _board.getTileColor(player_Index, postion);

        switch (tileColor){
            case 'B':  // Oasis Tile
        cout << "You've landed on an Oasis Tile! You gain extra resources."<<endl;
        _player[player_Index].train(200, 200, 200);
        cout << "You gained an extra turn!" << endl;
        takeTurn();
        cout<< " "<< endl;
        // Perform oasis-specific actions
        break;
    case 'P':  // Counseling Tile
        cout << "Welcome to the Counseling Tile! You gain wisdom and can choose an advisor."<<endl;
         _player[player_Index].train(300, 300, 300);
         chooseAdvisor(player_Index);
         cout<< " "<< endl;
        // Perform counseling-specific actions
        break;
    case 'R':  // Graveyard Tile
        cout << "Oh no, you stumbled into the Graveyard! You lose resources."<<endl;
        cout<< " "<< endl;
        // Perform graveyard-specific actions
        break;
    case 'N':  // Hyenas Tile
        cout << "Watch out, Hyenas are here! You return to your previous position."<<endl;
        cout<< " "<< endl;
        // Perform hyenas-specific actions
        break;
    case 'U':  // Challenge Tile
        cout << "It's a Challenge Tile! Solve a riddle to gain wisdom."<<endl;
        cout<< " "<< endl;
        // Perform challenge-specific actions
        break;
    case 'O':  // End Tile
        cout << "You've reached Pride Rock, the end of the game!"<<endl;
        cout<< " "<< endl;
        // End game or perform final actions
        break;
    case 'Y':  // Start Tile
        cout << "You're at the starting tile. Begin your journey!"<<endl;
        cout<< " "<< endl;
        break;
    case 'G':  // Regular Tile
    int chance;
        chance = (rand()%2)+1; // 50% chance nothing happens
    
        cout << "You're on a Grass land tile. Rolling for random events..."<<endl;

        // calls a function that goes to a random event paramter is player index
        if(chance == 1){
        cout<< "Nothing happened, Enjoy the green grass and blue skys!" << endl;
         }else{

         greenTileEvent(player_Index);
         }


        // Roll for random events, potentially affecting player pride points
        cout<< " "<< endl;

        break;
    default:
        cout << "Unknown tile. Nothing happens." <<endl ;
        break;

        }

}



void Game::startGame() {
    cout<< "LOADING DATA..."<< endl;
    cout<< "Lions loaded successfully!"<<endl;
    loadAdvisor ("advisor.txt", advisor);
    loadEvents ("events.txt", event);
    cout << "-------------------------------------------"<<endl;
    cout<< ""<< endl;

    
    string enter;
    cout << "Welcome to the Circle of Life!" << endl;
    cout << "Press Enter to continue." << endl;
    getline(cin, enter);

    cout << "Rules of the game:" << endl;
    cout << "You will travel across the African Savannah as a young lion to prove your strength." << endl;
    cout << "Press Enter to continue." << endl;
    getline(cin, enter);

    // Call whichCharacter to let players choose their characters
    whichCharacter();


    cout << "Let the game begin!" << endl;
    
    // Display the board for each player
   
        _board.displayBoard();  // Display each player's board
    

    // Begin game loop where each player takes turns
    
            takeTurn();  // Assuming takeTurn takes an index of the player
    }





 void Game::takeTurn(){
        srand(time(nullptr));
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
        int playerPosition;
        char tileType;
        bool advisorCheck;
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

             case 3:
                
                _board.displayBoard();
                playerPosition = _board.getPlayerPosition(currentPlayer);

                cout<< "Player "<<(currentPlayer+1)<< "'s Current position " << playerPosition+1 <<endl;

                tileType= _board.getTileColor(currentPlayer, playerPosition);

                cout << "Tile type: " << tileType << endl;

            break;

            case 4:
                 advisorCheck = _player[currentPlayer].checkAdvisor();

                 if (!advisorCheck){
                        cout<< "You don't have an advisor"<< endl;
                        cout << "** You can aquire one if you land on a councling tile **"<< endl;
                        
                 }
                
                cout<< "Your advisor is";
                _player[currentPlayer].printAdvisor();
                cout<< " "<< endl;

            break;

        case 5:
            int roll;
            roll = (rand()%6)+1;
            cout<< "Player" << (currentPlayer+1) <<": rolled a " << roll<< "!"<<endl;

            // implement the call to trigger event

            if(_board.movePlayer(currentPlayer, roll)){
                cout<< "Player " << (currentPlayer+1) << "reached the end" << endl;
                gamePlay=false;
            }else{
                 triggerEvent(currentPlayer, _player[currentPlayer]);
                currentPlayer=(currentPlayer+1) % 2;
            }
            break;

            default:
            cout<< "invalid Choice" << endl;
            break;
            
         }

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

 // event is a struct that will be implemented into greenTileEVent   


void Game:: greenTileEvent(int player_index){

    cout<< "AN EVENT WAS TRIGGERED!" << endl;
    srand(time(nullptr));
    int ppathType= _board.getPathType(player_index); // the player path type
    int pAdvisorID = _player[player_index].getAdvisor().getID(); // the players chosen advisor

    int eventIndex = rand() % NUM_EVENTS;

    cout << "ETEST VENT INDEX" << eventIndex << endl;

    Event selectedEvent = event[eventIndex];

    int eventPathType = selectedEvent.getPath();  // Get event's path type
    int eventAdvisorID = selectedEvent.getAdID(); 
    int eventPridePoints = selectedEvent.getPP();
    string eventDescription =  selectedEvent.getDes();

    if(eventPathType == 2 || eventPathType == ppathType){
        if (eventAdvisorID != pAdvisorID && eventAdvisorID != 0){
            cout << "OH NO! " << eventDescription << endl;
            cout<< "You lossed " << eventPridePoints << " Pride Points.5" << endl;
            _player[player_index].prideChange(eventPridePoints);
        } else if (eventAdvisorID == pAdvisorID && pAdvisorID !=0){
            cout << eventDescription << endl;
            cout << "Your Advisor";
            _player[player_index].printAdvisor();
            cout<< " saved you!"<< endl;
        }
            else{
                cout << "YOUR SAFE!"<< endl;
            }

    
        } 
    }

// the events is an array and a randome muber generator randevents = (rand()%6)+1; will choose the event

    // the values of pathType and advisorID will be compared to the playerspth type and playeradvisor
    // this is the tricky part however
    // if the generator selects this Desert storm sweeps through the territory|2|4|-500 and the player has 4 then nothing happens
    // but if the player does not have and advisor Extra energy from bountiful season|1|0|800 player pAdvisorID=0; then they gain points
    // so if theres a number that not 0 associated to the adviosr ID and the player has that ID then nothing happens else they loose pridepoints
    // if the player doesnt have a advisorID and the random geneator prompts and event that has 0 as an advisorID then they will gain pridepoints
    // how do i correctly implment this complex idea, 
    // in the event.h im thinking of adding these functions
    //int geteventID()
    //int getEventPath()
    // and for pride points that will be implmented into the player function as it changes the players pirdepoint stats


    //compare the players path type and adviosrID to the random path type and advisor ID to see if event happens



    void Game:: endgame(){

    }






