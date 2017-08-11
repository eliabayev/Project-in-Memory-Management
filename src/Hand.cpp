#include <Hand.h>

using namespace std;

Hand::Hand():_hand(){}

Hand::Hand(const Hand& other):_hand(){
        list<Card*> otherCopy(other._hand);
	Copy(otherCopy);
}

Hand& Hand::operator=(const Hand& other){
	if(this==&other)
		return *this;
	Clear();
        list<Card*> otherCopy(other._hand);
	Copy(otherCopy);
	return *this;
}


void Hand::Clear(){
	list<Card*>::iterator it=_hand.begin();
	while(it!=_hand.end()){
		delete(*it);
		it++;
	}
}

void Hand::Copy(list<Card*> otherCopy){
	list<Card*>::iterator it=otherCopy.begin();
	while(it!=otherCopy.end()){
		Card* cardCopy;
		int cardValue=(**it).getNumber();
		if(cardValue<0) {
			Figure f;
	        switch(cardValue){
	            case -1: f=Ace; break;
	            case -2: f=King; break;
	            case -3: f=Queen; break;
	            case -4: f=Jack; break;
	        }
	        cardCopy=new FigureCard((**it).getShape(),f);
	    }
	    else
		    cardCopy=new NumericCard((**it).getShape(),cardValue);
		_hand.push_back(cardCopy);
		it++;
	}
}


Hand::~Hand() { Clear(); }

list<Card*> Hand::getHand() const{
    return _hand;
}

void Hand::setHand(list<Card*> other){
    Copy(other);
}

bool Hand::addCard(Card &card){
        Card* cp=&card;
        if(_hand.size()==0)
            _hand.push_back(cp);
        else{
            int count=0;
            int cardValue=card.getNumber();
            list<Card*>::iterator it=_hand.begin();
            while((it!=_hand.end())&&(((**it).Equals(card))>0))
                    it++;
            if(it==_hand.end())
                _hand.push_back(cp);
            else
                _hand.insert(it,cp);
            it=_hand.begin();
            while((it!=_hand.end())&&count<4){
            	if(cardValue==(**it).getNumber())
            		count++;
            	it++;
            }
            if(count==4){
            	vector<Card*> vecRemove;
            	int c=4;
            	it=_hand.begin();
            	while((it!=_hand.end())&&c>0){
            		if(cardValue==(**it).getNumber()){
            			vecRemove.push_back(*it);
            			c--;
            		}
            		it++;
            	}
				int vecSize=vecRemove.size();
            	for(int i=0;i<vecSize;i++){
            		removeCard(*vecRemove[i]);
                        delete(vecRemove[i]);
                }
                    
                
            }
        }
        return true;
	}

bool Hand::removeCard(Card &card){
	if(searchForCard(card)){
                Card* cp=Find(card);
                _hand.remove(cp);
		return true;
	}
	return false;

}

vector<Card*> Hand::RemoveByValue(int cardValue){
	vector<Card*> vecRemove;
	list<Card*>::iterator it=_hand.begin();
	while(it!=_hand.end()){
		if((**it).getNumber()==cardValue)
			vecRemove.push_back(*it);
		it++;
	}
	return vecRemove;
}

bool Hand::searchForCard(Card &card){
	list<Card*>::iterator it=_hand.begin();
	while((it!=_hand.end())&&(((**it).Equals(card))!=0))
            it++;
	if(it!=_hand.end())
            return true;
	return false;
}

Card* Hand::Find(Card &card){
	list<Card*>::iterator it=_hand.begin();
	while(((**it).Equals(card))!=0)
            it++;
        return (*it);
}

int Hand::getNumberOfCards(){
	return _hand.size();
}

string Hand::toString(){
	string s="";
	list<Card*>::iterator it;
	for(it=_hand.begin();it!=_hand.end();it++){
		s=s+(**it).toString()+" ";
	}
	return s;
}
