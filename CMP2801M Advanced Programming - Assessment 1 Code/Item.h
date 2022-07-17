#ifndef ITEM_H
#define ITEM_H
#include<string>
using namespace std;
class Item
	//stores menu items information
{
private: // attributes that can only be accessed from this class
	string Type;
	string name;
	double price;
	int calories;
public: // attributes that are accessible from outside of the class
	void setType(string t);
	string getType();
	void setName(string name1);
	void setPrice(double price1);
	void setCalories(int calories1);
	string getName();
	double getPrice();
	int getCalories();
	virtual void toString() = 0;
};
#endif // !ITEM_H
