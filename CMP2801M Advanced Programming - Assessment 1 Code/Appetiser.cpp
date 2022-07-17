#include "Appetiser.h"
#include<iostream>
using namespace std;

void Appetiser::setShareable(bool flag) //assigns value of whether appetiser is shareable or not
{
	shareable = flag;
}

void Appetiser::setTowForOne(bool flag) //assigns value of whether appetiser is 2-4-1 or not
{
	twoForOne = flag;
}

bool Appetiser::isShareable() //returns value of whether appetiser is shareable or not
{
	return shareable;
}

bool Appetiser::isTwoForOne() //returns value of whether appetiser is 2-4-1 or not
{
	return twoForOne;
}

void Appetiser::toString() //converts all data to string format
{
	cout << static_cast<Appetiser*>(this)->getName() << ": \x9c" << static_cast<Appetiser*>(this)->getPrice() << ", " <<
		static_cast<Appetiser*>(this)->getCalories() << " cal (";
	if (static_cast<Appetiser*>(this)->isShareable() == true)
		cout << "shareable)";
	else if (static_cast<Appetiser*>(this)->isTwoForOne() == true)
		cout << "2-4-1)";
}
