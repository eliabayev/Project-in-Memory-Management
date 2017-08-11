#include <Player.h>

Player::Player(string name):Hand(),_name(name) { }

Player::~Player() { }

string Player::getName(){
	return _name;
}

string Player::toString(){
	string s="";
	s=getName()+": "+Hand::toString();
	return s;
}

Player* Player::PlayerWithMostCards(vector<Player *>& players){
	unsigned int i=0;
	int temp, max;
	Player* playerMost;
	if(getName()==players[i]->getName())
		i++;
	max=players[i]->getNumberOfCards();
	playerMost=players[i];
	i++;
	while(i<players.size()){
		if(getName()!=players[i]->getName()){
			temp=players[i]->getNumberOfCards();
			if(temp>=max){
				max=temp;
				playerMost=players[i];
			}
		}
		i++;
	}
	return playerMost;
}

int Player::CardValueIHaveMost(){
    list<Card*> _hand=getHand();
    list<Card*>::iterator it=_hand.begin();
    int max=(**it).getNumber();
    int maxCounter=1;
    it++;
    while((it!=_hand.end())&&(**it).getNumber()==max){
    	maxCounter++;
    	it++;
    }
    while(it!=_hand.end()){
        int temp=(**it).getNumber();
        int tempCounter=1;
        it++;
        while((it!=_hand.end())&&(**it).getNumber()==temp){
            tempCounter++;
            it++;
        }
        if(tempCounter>=maxCounter){
            max=temp;
            maxCounter=tempCounter;
        }
    }
    return max;
}

int Player::CardValueIHaveLeast(){
    list<Card*> _hand=getHand();
    list<Card*>::iterator it=_hand.begin();
    int min=(**it).getNumber();
    int minCounter=1;
    it++;
    while((it!=_hand.end())&&(**it).getNumber()==min){
	minCounter++;
	it++;
    }
    while(it!=_hand.end()){
        int temp=(**it).getNumber();
        int tempCounter=1;
        it++;
        while((it!=_hand.end())&&(**it).getNumber()==temp){
            tempCounter++;
            it++;
        }
        if(tempCounter<minCounter){
            min=temp;
            minCounter=tempCounter;
        }
    }
    return min;
}

Player* Player::WhoToAsk(vector<Player *>& players, int& whoNext){
        int size=players.size();
        if(whoNext>=size)
                whoNext=0;
	if(getName()==players[whoNext]->getName())
		whoNext++;
        if(whoNext>=size)
                whoNext=0;


	return players[whoNext];
}

void Player::Ask(Player* other, int cardValue, Deck& deck, int verbal){
	vector<Card*> vecRemove=other->RemoveByValue(cardValue);
	int removed=vecRemove.size();
	if((removed==0)&&(!deck.DeckIsEmpty())){
		addCard(*deck.fetchCard());
                        
	}
	else{
		for(int i=0;i<removed;i++){
                        other->removeCard(*vecRemove[i]);
			addCard(*vecRemove[i]);                                                                            


		}

		if(other->getNumberOfCards()!=0)
			for(int i=0;i<removed;i++)
				if(!deck.DeckIsEmpty())
					other->addCard(*deck.fetchCard());
	}
	if(verbal==1){
            if(cardValue<0) {
                string sFigure="";
                switch(cardValue){
                    case -1: sFigure="A"; break;
                    case -2: sFigure="K"; break;
                    case -3: sFigure="Q"; break;
                    case -4: sFigure="J"; break;
                }
            cout << getName() << " asked " << other->getName() << " for the value " << sFigure << endl;
            }
            else {
                string sNum=stringInt(cardValue);
            cout << getName() << " asked " << other->getName() << " for the value " << sNum << endl;
            }
        }
}

PlayerType1::PlayerType1(string name, int strategyNum):Player(name), _strategyNum(strategyNum) { }

PlayerType1::~PlayerType1() { }

Player* PlayerType1::Strategy(vector<Player *>& players, Deck& deck, int verbal) {
	int cardMost=CardValueIHaveMost();
	Player* playerMost=PlayerWithMostCards(players);
	Ask(playerMost, cardMost, deck, verbal);
	return playerMost;
}

int PlayerType1::getStrategyNum(){
	return _strategyNum;
}

PlayerType2::PlayerType2(string name, int strategyNum):Player(name), _strategyNum(strategyNum) { }

PlayerType2::~PlayerType2() { }

Player* PlayerType2::Strategy(vector<Player *>& players, Deck& deck, int verbal) {

	int cardLeast=CardValueIHaveLeast();
	Player* playerMost=PlayerWithMostCards(players);
	Ask(playerMost, cardLeast, deck, verbal);
	return playerMost;
}

int PlayerType2::getStrategyNum(){
	return _strategyNum;
}

PlayerType3::PlayerType3(string name, int strategyNum):Player(name), _whoNext(0), _strategyNum(strategyNum) { }

PlayerType3::~PlayerType3() { }

Player* PlayerType3::Strategy(vector<Player *>& players, Deck& deck, int verbal) {
	int cardHigh=HighestValueInHand();
	Player* playerToAsk=WhoToAsk(players, _whoNext);
	_whoNext++;
	Ask(playerToAsk, cardHigh, deck, verbal);
	return playerToAsk;
}

int PlayerType3::HighestValueInHand() {
    return getHand().back()->getNumber();
}

int PlayerType3::getStrategyNum(){
	return _strategyNum;
}

PlayerType4::PlayerType4(string name, int strategyNum):Player(name), _whoNext(0), _strategyNum(strategyNum) { }

PlayerType4::~PlayerType4() { }

Player* PlayerType4::Strategy(vector<Player *>& players, Deck& deck, int verbal) {
	int cardLow=LowestValueInHand();
	Player* playerToAsk=WhoToAsk(players, _whoNext);
	_whoNext++;
	Ask(playerToAsk, cardLow, deck, verbal);
	return playerToAsk;
}

int PlayerType4::LowestValueInHand() {
    return getHand().front()->getNumber();
}

int PlayerType4::getStrategyNum(){
	return _strategyNum;
}

string Player::stringInt(int cardValue) {
	stringstream s;
	s<<cardValue;
	return s.str();
}


