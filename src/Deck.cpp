#include <Deck.h>

using namespace std;

Deck::Deck(): _deck() { }

Deck::Deck(const Deck& other):_deck(){
	Copy(other);
}

Deck& Deck::operator=(const Deck& other){
	if(this==&other)
		return *this;
	Clear();
	Copy(other);
	return *this;
}

void Deck::Clear(){
	int size=_deck.size();
	for(int i=0;i<size;i++){
		delete _deck.top();
		_deck.pop();
	}
}

void Deck::Copy(const Deck& other){
	stack<Card*> sTemp;
	stack<Card*> otherCopy(other._deck);
	int size=otherCopy.size();
	for(int i=0;i<size;i++){
		Card* cardCopy;
		int cardValue=otherCopy.top()->getNumber();
		if(cardValue<0) {
			Figure f;
	        switch(cardValue){
	            case -1: f=Ace; break;
	            case -2: f=King; break;
	            case -3: f=Queen; break;
	            case -4: f=Jack; break;
	        }
	        cardCopy=new FigureCard(otherCopy.top()->getShape(),f);
	    }
	    else
		    cardCopy=new NumericCard(otherCopy.top()->getShape(),cardValue);
		sTemp.push(cardCopy);
		otherCopy.pop();
	}

	for(int i=0;i<size;i++){
		_deck.push(sTemp.top());
		sTemp.pop();
	}
}


Deck::~Deck() { Clear(); }

void Deck::BuildDeck(string sDeck){
	unsigned int i=0;
	int num;
	Shape s;
	Figure f;
	stack<Card*> st;
	while(i<sDeck.length()){
		if(sDeck[i]!=' '){
			if(sDeck[i]=='J'||sDeck[i]=='Q'||sDeck[i]=='K'||sDeck[i]=='A'){
				f=convertToFigure(sDeck[i]);
				i++;
				s=convertToShape(sDeck[i]);
				Card* card=new FigureCard(s,f);
				st.push(card);
			}
			else {
				string sNum="";
				while(sDeck[i]!='C'&&sDeck[i]!='D'&&sDeck[i]!='H'&&sDeck[i]!='S'){
					sNum=sNum+sDeck[i];
					i++;
				}
				s=convertToShape(sDeck[i]);
				num=atoi(sNum.c_str());
				Card* card=new NumericCard(s,num);
				st.push(card);
			}
		}
		i++;
	}
	while(!st.empty()){
		_deck.push(st.top());
		st.pop();
	}
}

Figure Deck::convertToFigure(char c) {
	Figure f;
	switch(c){
		case 'J': f=Jack ; break;
		case 'Q': f=Queen; break;
		case 'K': f=King; break;
		case 'A': f=Ace; break;
	}
	return f;
}

Shape Deck::convertToShape(char c) {
	Shape s;
	switch(c){
		case 'C': s=Club ; break;
		case 'D': s=Diamond; break;
		case 'H': s=Heart; break;
		case 'S': s=Spade; break;
	}
	return s;
}

Card* Deck::fetchCard() {
    Card* poped=_deck.top();
    _deck.pop();
    return poped;
}

int Deck::getNumberOfCards() {
    return _deck.size();
}

bool Deck::DeckIsEmpty(){
	return _deck.empty();
}

string Deck::toString() {
    stack<Card*> deckHelp;
    string s="";
    int size=_deck.size();
    for(int i=0; i<size;i++){
        Card* poped=_deck.top();
        deckHelp.push(poped);
        _deck.pop();
        s=s+poped->toString()+" ";
    }
    for(int i=0; i<size;i++){
        _deck.push(deckHelp.top());
        deckHelp.pop();
    }
    return s;
}
