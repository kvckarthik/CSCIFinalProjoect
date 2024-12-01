#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "Player.h"


class Board {
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE]; // A 2D array, each player has their own row of tiles
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    int _player_tracks[2];
    int _pathType;

    void displayTile(int player_index, int pos);
    void initializeTiles(int player_index); // Initializes individual tracks for players
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board(); // Default constructor
    Board(int player_count, int player_tracks[]); // Constructor with player info
    void displayTrack(int player_index);
    void initializeBoard(); // Initializes all boards (tracks) for players
    void displayBoard(); // Displays both boards
    bool movePlayer(int player_index, int roll);
    int getPlayerPosition(int player_index) const;
    char getTileColor(int player_index,int rolledPostion);
    int getPathType (int player_index); // gets the value 0 - cub taining or 1- pridelands, this is helpful for tile events
    
    
};
#endif