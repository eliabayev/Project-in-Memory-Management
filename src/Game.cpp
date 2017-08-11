#include <Game.h>

Game::Game(char* configurationFile):_players(),_deck(), _turn(0), _verbal(1) {
	vector<string> lines;
	lines=Readfile(configurationFile);
        _verbal=atoi(lines[0].c_str());
	_deck.BuildDeck(lines[2]);
	unsigned int i=3;
	string sName="";
	while(i<lines.size()){
		int j=0;
		while(lines[i][j]!=' '){
			sName=sName+lines[i][j];
			j++;
		}
		char c=lines[i][j+1];
		if(c=='1'){
			Player* p=new PlayerType1(sName, 1);
			_players.push_back(p);
		}
		else if(c=='2'){
			Player* p=new PlayerType2(sName, 2);
			_players.push_back(p);
		}
		else if(c=='3'){
			Player* p=new PlayerType3(sName, 3);
			_players.push_back(p);
		}
		else if(c=='4'){
			Player* p=new PlayerType4(sName, 4);
			_players.push_back(p);
		}
		i++;
        sName="";
	}

}

Game::Game(const Game& other):_players(),_deck(other._deck), _turn(other._turn), _verbal(other._verbal) {
	Copy(other);
}

Game& Game::operator=(const Game& other){
	if(this==&other)
		return *this;
	Clear();
	_deck=other._deck;
	_turn=other._turn;
        _verbal=other._verbal;
	Copy(other);
	return *this;
}

 void Game::Clear(){
 	vector<Player*>::iterator it=_players.begin();
 	while(it!=_players.end()){
 		delete(*it);
 		it++;
 	}
 }

void Game::Copy(const Game& other){
	vector<Player*> otherCopy(other._players);
	vector<Player*>::iterator it=otherCopy.begin();
	while(it!=otherCopy.end()){
		Player* playerCopy;
		int strategyNum=(**it).getStrategyNum();
		string sName=(**it).getName();
		if(strategyNum==1){
			playerCopy=new PlayerType1(sName, 1);
                        playerCopy->setHand((**it).getHand());
                }
		else if(strategyNum==2){
			playerCopy=new PlayerType2(sName, 2);
                        playerCopy->setHand((**it).getHand());
                }
		else if(strategyNum==3){
			playerCopy=new PlayerType3(sName, 3);
                        playerCopy->setHand((**it).getHand());
                }
		else if(strategyNum==4){
			playerCopy=new PlayerType4(sName, 4);
                        playerCopy->setHand((**it).getHand());
                }
		_players.push_back(playerCopy);
                it++;
	}
}

Game::~Game() { Clear(); }

vector<Player *> Game::getPlayers(){
    return _players;
}

Deck& Game::getDeck(){
    return _deck;
}

vector<string> Game::Readfile(char* configurationFile) {
	ifstream file;
	file.open(configurationFile);
	vector<string> lines;
	string currentLine;
	while(getline(file,currentLine)){
		if(!currentLine.empty() && currentLine[0]!='#' && currentLine[0]!=' ')
			lines.push_back(currentLine);
	}
	return lines;
}

void Game::init(){
	for(unsigned int i=0;i<_players.size();i++){
		for(unsigned int j=0; j<7;j++)
			_players[i]->addCard((*_deck.fetchCard()));

	}
}

void Game::play(){
	bool gameEnds=false;
	while(!gameEnds){
		unsigned int i=0;
		while(!gameEnds&&(i<_players.size())){
                    _turn++;
                    if(_verbal==1){
                        string s=stringInt();
                        cout << "Turn "<< s << endl;
                        printState();
                    }
			Player* maybeWinner=_players[i]->Strategy(_players, _deck, _verbal);
			if((_players[i]->getNumberOfCards()==0)||(maybeWinner->getNumberOfCards()==0))
				gameEnds=true;
                        i++;
                        
                    if(_verbal==1)
                        cout << " " << endl;
		}
	}
}

void Game::printState(){
	cout << "Deck: " << _deck.toString() << endl;
	vector<Player *>::iterator it;
	for(it=_players.begin();it!=_players.end();it++){
		cout<< (**it).toString() << endl;
	}
}

void Game::printWinner(){
	string winner1="";
	string winner2="";
	unsigned int i;
	bool win1=false;
	bool win2=false;
	for(i=0;!win1;i++)
		if(_players[i]->getNumberOfCards()==0){
			winner1=_players[i]->getName();
			win1=true;
		}
	for(unsigned int j=i+1;!win2&&(j<_players.size());j++)
		if(_players[j]->getNumberOfCards()==0){
			winner2=_players[j]->getName();
			win2=true;
		}
	if(win2)
		cout << "***** The winners are: " << winner1 << " and " << winner2 << " *****" << endl;
	else
		cout << "***** The Winner is: " << winner1 << " *****" << endl;
}

string Game::stringInt() {
	stringstream s;
	s<<_turn;
	return s.str();
}

void Game::printNumberOfTurns(){
        cout << "Number of turns: " << _turn << endl;
}
