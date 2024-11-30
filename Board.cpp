#include "Board.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Board::Board() {
    _player_count = 0;

    // Initialize player positions and tracks
    for (int i = 0; i < _MAX_PLAYERS; i++) {
        _player_position[i] = 0;
        _player_tracks[i] = 0;
    }

    // Initialize tiles as empty or a default state
    for (int player_index = 0; player_index < _MAX_PLAYERS; player_index++) {
        for (int i = 0; i < _BOARD_SIZE; i++) {
            _tiles[player_index][i].color = ' ';  // Default to an empty tile
        }
    }
}


void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
}





// change this 
void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    int chosen_track = _player_tracks[player_index];

    int total_greens; // the greens change depending on prideland or cub trainihg

    if(chosen_track==0){ // cub training 
        total_greens=30;
    } else if(chosen_track==1){ // pride lands
        total_greens=20;
    }

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < total_greens && (rand() % (total_tiles - i) < total_greens - green_count)) {
            temp.color = 'G';
            green_count++;
        } else
            {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple

            int color_choice = rand() % 100;
            int graveyardChance;
            int heyenaChance;
            int oasisChance;
            int counclingChance;
            int challengingChance;

            if(chosen_track==0){   //cub
                if (i < 26) {
                graveyardChance = 2; // 20% 20
                heyenaChance= 4;  // 20% 40
                counclingChance = 90; // 15% 55
                 oasisChance= 95;  // 25% 80
                challengingChance = 100 ; // 20

                } else {  //second half
                graveyardChance = 20; // 20%
                heyenaChance= 40;  // 20%
                counclingChance = 55; // 15% 
                 oasisChance= 70;  // 15%
                challengingChance = 100 ; // 30


                }
            } else { // pridelands
                if (i < 26) { 
                graveyardChance = 25; //25%
                heyenaChance = 50;  // 25% 
                counclingChance = 70;  // 20% 
                oasisChance= 75;    // 5%
                challengingChance = 100; // 25%  
                } else { //second half

                 graveyardChance = 15; //15%
                heyenaChance = 30;  // 30%
                counclingChance = 50;  // 20% 
                oasisChance= 75;    // 25%
                challengingChance = 100; // 25%  

                }
            }



            if (color_choice< graveyardChance){ //purple

                temp.color = 'R';
            }
            if (color_choice > graveyardChance && color_choice< heyenaChance){ //brown 
                temp.color= 'N';
            }
            if (color_choice > heyenaChance && color_choice< counclingChance){ //pint 
                temp.color = 'P';
            } 
            if (color_choice > counclingChance && color_choice < oasisChance){ //blue
                temp.color = 'B';
            } 
             if (color_choice > oasisChance && color_choice < challengingChance){ //purple
                temp.color = 'U';
            } 

        // Assign the tile to the board for the specified lane
        
    }
    _tiles[player_index][i] = temp;
}
}


// Board::Board()
// {
//     _player_count = 1;

//     // Initialize player position
//     _player_position[0] = 0;

//     // Initialize tiles
//     initializeTiles();
// }



Board::Board(int player_count, int chosen_tracks[])  // [0,0], [0,1]
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
        _player_tracks[i] = chosen_tracks[i]; 
    }

    // Initialize tiles

    initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }

    return false;
}

void Board::displayTile(int player_index, int pos)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
    }

     if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int roll)
{
    // Increment player position
    _player_position[player_index]+=roll;
    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

char Board::getTileColor(int playerIndex, int position){
    if (position >= 0 && position < _BOARD_SIZE) {
        return _tiles[playerIndex][position].color;  // Access the color of the tile
    }
    return ' ';  // Return a default value for invalid positions
}
