#include<iostream>
using namespace std;

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <vector>
#include "Advisor.h"
#include "Event.h"
#include "Riddles.h"

class Game{
    private:
     static const int MAX_PLAYER = 2; // two players only
    Player _player[ MAX_PLAYER]; // array that stores type player objects
    int _player_count; // tracks the number of plauer
    Board _board; // intance of board
    Event _event;
    void takeTurn (int); // handle players turns//void takeTurn; // this will allow you to role a dice, check you stats, see what tile you are on... 
   static const int NUM_ADVISOR = 5; // there are a total of 5 advisor to choose from
   Advisor advisor[NUM_ADVISOR];  // an array of advisors - used to store each advisor

    static const int NUM_EVENTS = 50;
    Event event [NUM_EVENTS];
    
    // for riddles
    static const int NUM_RIDDLES = 29;
    Riddles riddles [NUM_RIDDLES];

    


    public:

    Game(); // default constructorer
     void whichCharacter(); // this function is used to have each player select there attributes for there lion
    void startGame(); // start game, calls which character, and take turn
    void endgame(int player_index); // wen last tile, who has most pride point
    void loadAdvisor(string file, Advisor arr[]);
    void loadEvents (string file, Event arr[]);
    void loadRiddles (string file, Riddles arr[]);
    void chooseAdvisor (int player_index); // int playing is the index for whos playing, player one or player two
    bool triggerEvent(int player_index, Player player);

    void greenTileEvent (int player_index);
    void riddleTiles (int player_index);








};
#endif

