#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Hand.h"
#include "../include/Player.h"
#include "../include/Game.h"
#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main(int argc, char *argv[]){

/*
     Card* c11=new NumericCard(Club, 1);
     Card* c12=new NumericCard(Diamond, 1);
     Card* c13=new NumericCard(Heart, 1);
     Card* c14=new FigureCard(Diamond, Queen);
     Card* c15=new NumericCard(Spade, 1);
     Card* c16=new NumericCard(Club, 2);
     Card* c17=new NumericCard(Diamond, 2);
     Card* c18=new NumericCard(Heart, 2);
     Card* c19=new NumericCard(Spade, 2);
      
     Player eli("Eli");
     
     eli.addCard(*c11);
     eli.addCard(*c12);
     eli.addCard(*c13);
     eli.addCard(*c14);
     eli.addCard(*c15);
     eli.addCard(*c16);
     eli.addCard(*c17);
     eli.addCard(*c18);
     eli.addCard(*c19);
     
     cout << eli.toString() << endl;
    */


      char* file=argv[1];
      Game* g=new Game(file);
      Deck& d(g->getDeck());
      vector<Player *> p=g->getPlayers();
         
      cout << d.toString() << endl;
      
      g->init();
      g->play();

     
     
     
     
//
/*
    cout << (c11->Equals(*c12)) << endl;

    if((c11->Equals(*c12))>0)
        cout << c12->toString() << endl;
    else
        cout << c11->toString() << endl;
        */
//      Card* c17=new NumericCard(Spade, 2);
//      Card* c18=new NumericCard(Diamond, 3);
//      Card* c19=new NumericCard(Club, 4);
//      Card* c20=new NumericCard(Heart, 5);

//     stack<Card*>* check= new stack<Card*>;
/*
     check->push(c11);
      check->push(c12);
      check->push(c13);
      check->push(c14);
      check->push(c15);
      check->push(c16);*/
//      check->push(c17);
//      check->push(c18);
//      check->push(c19);
//      check->push(c20);

//     Deck* d=new Deck(*check);
//
//
//     cout << d->toString() << endl;
//      cout << d->getNumberOfCards() << endl;
//      Card* f1=d->fetchCard();
//      cout << (*f1).toString() << endl;
//      cout << d->getNumberOfCards() << endl;
//      cout << d->toString() << endl;
//      cout << (*(d->fetchCard())).toString() << endl;
//      cout << (*(d->fetchCard())).toString() << endl;
//      cout << d->getNumberOfCards() << endl;
//      cout << d->toString() << endl;

//      list<Card*>* l=new list<Card*>;

//    Hand* h=new Hand();

//    h->addCard(*c11);
//    h->addCard(*c12);
//    h->addCard(*c13);
//    h->addCard(*c14);
//    h->addCard(*c15);
//     h->addCard(*c16);
/*
    if(h->searchForCard(*c16))
        cout << "t" << endl;
    else
        cout << "f" << endl;
    */
//   cout << h->getNumberOfCards() << endl;
//    cout << h->toString() << endl;
//     h->addCard(*c17);
//     h->addCard(*c18);
//     h->addCard(*c19);
//     h->addCard(*c20);

//     cout << h->toString() << endl;
//
//     h->removeCard(*c11);
//
//     cout << h->toString() << endl;
//
//     h->removeCard(*c12);
//     h->removeCard(*c13);
//     h->removeCard(*c14);
//     h->removeCard(*c15);
//     h->removeCard(*c16);
//     cout << h->getNumberOfCards() << endl;
//     cout << h->toString() << endl;

//      delete(c17);
//      delete(c18);
//      delete(c19);
//      delete(c20);
//      delete(d);
//      delete(h);

//      PlayerType1* Eli=new PlayerType1("Eli");
//      Eli->addCard(*c11);
//      Eli->addCard(*c12);
//      Eli->addCard(*c13);
//      Eli->addCard(*c14);
//      Eli->addCard(*c15);
//
//      Eli->addCard(*c16);
//      Eli->addCard(*c17);
//      Eli->addCard(*c18);
//      Eli->addCard(*c19);
//
//     cout << Eli->cardValueIHaveMost() << endl;

    return 0;
};
