#include<iostream>
using namespace std;

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <vector>

class Game{
    private:
     static const int MAX_PLAYER = 2; // two players only
    Player _player[ MAX_PLAYER]; // array that stores type player objects
    int _player_count; // tracks the number of plauer
    Board _board; // intance of board
    void takeTurn (); // handle players turns//void takeTurn(int whosPlaying); // this will allow you to role a dice, check you stats, see what tile you are on... 
    // whos playing 
    //void showBoard();  // diplslay the game board


    public:

    Game(); // default constructorer
    bool whosPlaying();
     void whichCharacter();
    void startGame(); // choose charater, choose what land go to
    void endgame(); // wen last tile, who has most pride points



};
#endif

