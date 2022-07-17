#ifndef BEVERAGE_H
#define BEVERAGE_H
#include"Item.h"
using namespace std;
class Beverage : public Item // class inherits beverage data from Item class
{
private:  // attributes that can only be accessed from this class
	int volume;
	double abv;
public: // attributes that are accessible from outside of the class
	void setVolume(int v);
	void setAbv(double Abv);
	int getVolume();
	double getAbv();
	bool isAlcoholic();
	void toString();
};
#endif // !BEVERAGE
