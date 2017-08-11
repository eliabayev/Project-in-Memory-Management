#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Card {
private:
  Shape _shape;
public:
  Card(Shape shape);
  virtual ~Card();
  Shape getShape() const;
  virtual string toString() = 0;
  virtual int getNumber() = 0;
  virtual int Equals(Card& other) = 0;

};

class FigureCard : public Card {
private:
	Figure _figure;
	int _cardValue;
public:
        FigureCard(Shape shape, Figure figure);
        virtual ~FigureCard();
        virtual string toString() override;
        Figure getFigure() const;
        virtual int getNumber() override;
        virtual int Equals(Card& other) override;
};

class NumericCard : public Card {
private:
	int _number;
public:
        NumericCard(Shape shape, int number);
        virtual ~NumericCard();
        virtual string toString() override;
        string stringNumeric();
        virtual int getNumber() override;
        virtual int Equals(Card& other) override;
};


#endif /* CARD_H_ */
