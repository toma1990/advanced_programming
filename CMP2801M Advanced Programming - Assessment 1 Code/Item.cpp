#include "Item.h"

void Item::setType(string t) //assign t to type attribute
{
	Type = t;
}

string Item::getType() //returns value of type attribute
{
	return Type;
}

void Item::setName(string name1) //assign name1 to name attribute
{
	name = name1;
}

void Item::setPrice(double price1) //assign price1 to price attribute
{
	price = price1;
}

void Item::setCalories(int calories1) //assign calories1 to calories attribute
{
	calories = calories1;
}

string Item::getName()  //returns value of name attribute
{
	return name;
}
 
double Item::getPrice() //returns value of price attribute
{
	return price;
}

int Item::getCalories() //returns value of calories attribute
{
	return calories;
}
