#ifndef GAME_H_
#define GAME_H_

#include <fstream>
#include <Player.h>

using namespace std;

class Game {
private:
	vector<Player *> _players;  //The list of the players
	Deck _deck;                 //The deck of the game
	int _turn;
        int _verbal;
	void Clear();
	void Copy(const Game& other);
public:
	Game(char* configurationFile);
    	virtual ~Game();
	Game(const Game& other);
	Game& operator=(const Game& other);
	vector<string> Readfile(char* configurationFile);
   	 vector<Player *> getPlayers();
    	Deck& getDeck();
    	string stringInt();
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
    	void printNumberOfTurns(); //Print the number of played turns at any given time.
};

#endif
