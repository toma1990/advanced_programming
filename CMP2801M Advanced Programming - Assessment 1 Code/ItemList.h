#ifndef ITEMLIST_H
#define ITEMLIST_H
#include"Item.h"
#include"Appetiser.h"
#include"Beverage.h"
#include"MainCourse.h"
#include<vector>
using namespace std;
class ItemList
{
private:
	vector<Item*> items; //vector to store all items on menu from item class
	int size = 0;
public:
	string addAppetiser(Appetiser a);
	string addBeverage(Beverage b);
	string addMainCourse(MainCourse m);
	void getAppetiser(Appetiser& Ap, string num);
	void getBeverage(Beverage& Bv, string num);
	void getMainCourse(MainCourse& mc, string num);
	string remove(string num);
	double getTotal(double& savings);
	void receipt();
	void displayList();
	void checkoutList();
	void sortMenu();
	virtual void toString() = 0;
	~ItemList();
};
#endif // !ITEMLIST_H
