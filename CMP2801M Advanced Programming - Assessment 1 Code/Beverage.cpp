#include "Beverage.h"
#include <iostream>
using namespace std;

void Beverage::setVolume(int v) //assign v to volume attribute
{
	volume = v;
}

void Beverage::setAbv(double Abv) //assign abv to Abv attribute
{
	abv = Abv;
}

int Beverage::getVolume() //returns value of volume attribute
{
	return volume;
}

double Beverage::getAbv() //returns value ofAbv attribute
{
	return abv;
}

bool Beverage::isAlcoholic()
{
	if (this->getAbv() > 0) // checks if Abv value is present to determine if alcoholic or not
		return true;
	return false;
}

void Beverage::toString() //converts all data to string format
{
	cout << static_cast<Beverage*>(this)->getName() << ": \x9c" << static_cast<Beverage*>(this)->getPrice() << ", " <<
		static_cast<Beverage*>(this)->getCalories() << " cal (" << static_cast<Beverage*>(this)->getVolume() << "ml";
	if (static_cast<Beverage*>(this)->getAbv() > 0)
	{
		cout << ", " << static_cast<Beverage*>(this)->getAbv() << "% abv)";
	}
	else {
		cout << ")";
	}
}
