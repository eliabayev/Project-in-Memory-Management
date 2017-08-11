#ifndef HAND_H_
#define HAND_H_

#include <Deck.h>
#include <list>
#include <vector>


using namespace std;

class Hand {
private:
	list<Card*> _hand;
	void Clear();
	void Copy(list<Card*> otherCopy);
public:
	Hand();
        virtual ~Hand();
    	Hand(const Hand& other);
    	Hand& operator=(const Hand& other);
        list<Card*> getHand() const;
        void setHand(list<Card*> other);
        vector<Card*> RemoveByValue(int cardValue);
	bool addCard(Card &card);
	bool removeCard(Card &card);
        bool searchForCard(Card &card);
        Card* Find(Card &card);
	int getNumberOfCards();
	string toString();
};

#endif /* HAND_H_ */
