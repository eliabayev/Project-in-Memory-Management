#ifndef DECK_H_
#define DECK_H_

#include <stack>
#include <Card.h>
#include <string>

using namespace std;

class Deck {
private:
	stack<Card*> _deck;
	void Clear();
	void Copy(const Deck& other);
public:
	Deck();
	Deck(const Deck& other);
	~Deck();
	Deck& operator=(const Deck& other);
	void BuildDeck(string sDeck);
	Figure convertToFigure(char c);
	Shape convertToShape(char c);
	Card* fetchCard();  
	int getNumberOfCards();
	bool DeckIsEmpty();
	string toString(); 
};



#endif /* DECK_H_ */
