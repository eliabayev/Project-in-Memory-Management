#ifndef PLAYER_H_
#define PLAYER_H_

#include <Hand.h>

using namespace std;

class Player : public Hand {
private:
	const string _name;
public:
	Player(string name);
	virtual ~Player();
	virtual Player* Strategy(vector<Player *>& players, Deck& deck, int verbal) = 0;
	void Ask(Player* other, int cardValue, Deck& deck, int verbal);
	string getName();  
	virtual int getStrategyNum() = 0;
	int CardValueIHaveMost();
	int CardValueIHaveLeast();
        Player* PlayerWithMostCards(vector<Player *>& players);
	Player* WhoToAsk(vector<Player *>& players, int& whoToAsk);
        string stringInt(int CardValue);
	string toString();
};

class PlayerType1 : public Player {
private:
	int _strategyNum;
public:
	PlayerType1(string name, int strategyNum);
	virtual ~PlayerType1();
	virtual Player* Strategy(vector<Player *>& players, Deck& deck, int verbal) override;
	virtual int getStrategyNum() override;
};

class PlayerType2 : public Player {
private:
	int _strategyNum;
public:
	PlayerType2(string name, int strategyNum);
	virtual ~PlayerType2();
	virtual Player* Strategy(vector<Player *>& players, Deck& deck, int verbal) override;
	virtual int getStrategyNum() override;
};

class PlayerType3 : public Player {
private:
	int _whoNext;
	int _strategyNum;
public:
	PlayerType3(string name, int strategyNum);
	virtual ~PlayerType3();
	virtual Player* Strategy(vector<Player *>& players, Deck& deck, int verbal) override;
        int HighestValueInHand();
        virtual int getStrategyNum() override;
};

class PlayerType4 : public Player {
private:
	int _whoNext;
	int _strategyNum;
public:
	PlayerType4(string name, int strategyNum);
	virtual ~PlayerType4();
	virtual Player* Strategy(vector<Player *>& players, Deck& deck, int verbal) override;
        int LowestValueInHand();
        virtual int getStrategyNum() override;
};

#endif
