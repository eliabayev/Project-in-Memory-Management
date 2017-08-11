#include "Card.h"

using namespace std;

Card::Card(Shape shape):_shape(shape) { }

Card::~Card() { }

Shape Card::getShape() const {return _shape;}

FigureCard::FigureCard(Shape shape, Figure figure):Card(shape), _figure(figure), _cardValue(0) {
	switch(_figure){
		case Jack: _cardValue=-4; break;
		case Queen: _cardValue=-3; break;
		case King: _cardValue=-2; break;
		case Ace: _cardValue=-1; break;
	}
}

FigureCard::~FigureCard() { }

Figure FigureCard::getFigure() const {
	return _figure;
}

int FigureCard::getNumber() {
	return _cardValue;
}

string FigureCard::toString() {
    Shape fShape=getShape();
    if(_figure==Jack){
        if(fShape==Club)
            return "JC";
        else if(fShape==Diamond)
            return "JD";
        else if(fShape==Heart)
            return "JH";
        else if(fShape==Spade)
            return "JS";
    }
    else if(_figure==Queen){
        if(fShape==Club)
            return "QC";
        else if(fShape==Diamond)
            return "QD";
        else if(fShape==Heart)
            return "QH";
        else if(fShape==Spade)
            return "QS";
    }
    else if(_figure==King){
        if(fShape==Club)
            return "KC";
        else if(fShape==Diamond)
            return "KD";
        else if(fShape==Heart)
            return "KH";
        else if(fShape==Spade)
            return "KS";
    }
    else if(_figure==Ace){
        if(fShape==Club)
            return "AC";
        else if(fShape==Diamond)
            return "AD";
        else if(fShape==Heart)
            return "AH";
        else if(fShape==Spade)
            return "AS";
    }
    return "";

}

int FigureCard::Equals(Card& other) {
	string myString= this->toString();
	string otherString= other.toString();
	char myShape=myString.at(myString.size()-1);
	char otherShape=otherString.at(otherString.size()-1);
	if(this==&other)
		return 0;
	else if(other.getNumber()>0)
		return -1;
	else if(getNumber()<other.getNumber())
		return 1;
	else if(getNumber()>other.getNumber())
		return -1;
	else if((getNumber()==other.getNumber())&&(myShape<otherShape))
		return 1;
	else if((getNumber()==other.getNumber())&&(myShape>otherShape))
		return -1;
	return 0;
}

NumericCard::NumericCard(Shape shape, int number):Card(shape), _number(number) { }

NumericCard::~NumericCard() { }

int NumericCard::getNumber() {
	return _number;
}

string NumericCard::stringNumeric() {
	stringstream s;
	s<<_number;
	return s.str();
}

int NumericCard::Equals(Card& other) {
	string myString= this->toString();
	string otherString= other.toString();
	char myShape=myString.at(myString.size()-1);
	char otherShape=otherString.at(otherString.size()-1);
	if(this==&other)
		return 0;
	else if(other.getNumber()<0)
		return 1;
	else if(getNumber()<other.getNumber())
		return 1;
	else if(getNumber()>other.getNumber())
		return -1;
	else if((getNumber()==other.getNumber())&&(myShape<otherShape))
		return 1;
	else if((getNumber()==other.getNumber())&&(myShape>otherShape))
		return -1;
	return 0;
}

string NumericCard::toString() {
    Shape nShape=getShape();
    string s=stringNumeric();
    if(nShape==Club)
        return s+"C";
    else if(nShape==Diamond)
        return s+"D";
    else if(nShape==Heart)
        return s+"H";
    else if(nShape==Spade)
        return s+"S";
    return "";
}
