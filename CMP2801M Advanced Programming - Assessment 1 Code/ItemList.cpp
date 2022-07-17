#include "ItemList.h"
#include"Beverage.h"
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
//functions to add items to order
string ItemList::addAppetiser(Appetiser a)
{
	Item* p = NULL;
	p = new Appetiser;
	static_cast<Appetiser*>(p)->setType(a.getType());
	static_cast<Appetiser*>(p)->setName(a.getName());
	static_cast<Appetiser*>(p)->setCalories(a.getCalories());
	static_cast<Appetiser*>(p)->setPrice(a.getPrice());
	static_cast<Appetiser*>(p)->setShareable(a.isShareable());
	static_cast<Appetiser*>(p)->setTowForOne(a.isTwoForOne());
	items.push_back(p);
	return p->getName();
}

string ItemList::addBeverage(Beverage b)
{
	Item* p = NULL;
	p = new Beverage;
	static_cast<Beverage*>(p)->setType(b.getType());
	static_cast<Beverage*>(p)->setName(b.getName());
	static_cast<Beverage*>(p)->setCalories(b.getCalories());
	static_cast<Beverage*>(p)->setPrice(b.getPrice());
	static_cast<Beverage*>(p)->setAbv(b.getAbv());
	static_cast<Beverage*>(p)->setVolume(b.getVolume());
	items.push_back(p);
	return p->getName();
}

string ItemList::addMainCourse(MainCourse m)
{
	Item* p = NULL;
	p = new MainCourse;
	static_cast<MainCourse*>(p)->setType(m.getType());
	static_cast<MainCourse*>(p)->setName(m.getName());
	static_cast<MainCourse*>(p)->setCalories(m.getCalories());
	static_cast<MainCourse*>(p)->setPrice(m.getPrice());

	items.push_back(p);
	return p->getName();
}

void ItemList::getAppetiser(Appetiser& Ap, string num)
{
	Ap.setType(items[stoi(num) - 1]->getType());
	Ap.setName(items[stoi(num) - 1]->getName());
	Ap.setCalories(items[stoi(num) - 1]->getCalories());
	Ap.setPrice(items[stoi(num) - 1]->getPrice());
	Ap.setShareable(static_cast<Appetiser*>(items[stoi(num) - 1])->isShareable());
	Ap.setTowForOne(static_cast<Appetiser*>(items[stoi(num) - 1])->isTwoForOne());
}

void ItemList::getBeverage(Beverage& Bv, string num)
{
	Bv.setType(items[stoi(num) - 1]->getType());
	Bv.setName(items[stoi(num) - 1]->getName());
	Bv.setCalories(items[stoi(num) - 1]->getCalories());
	Bv.setPrice(items[stoi(num) - 1]->getPrice());
	Bv.setAbv(static_cast<Beverage*>(items[stoi(num) - 1])->getAbv());
	Bv.setVolume(static_cast<Beverage*>(items[stoi(num) - 1])->getVolume());
}

void ItemList::getMainCourse(MainCourse& mc, string num)
{
	mc.setType(items[stoi(num) - 1]->getType());
	mc.setName(items[stoi(num) - 1]->getName());
	mc.setCalories(items[stoi(num) - 1]->getCalories());
	mc.setPrice(items[stoi(num) - 1]->getPrice());
}

string ItemList::remove(string num)
{
	string name = items[stoi(num) - 1]->getName();
	items.erase(items.begin() + (stoi(num) - 1));
	return name;
}
// calculates if any savings need to be applied
double ItemList::getTotal(double& savings)
{
	double total = 0;
	double price = -1;
	double cheapest = -1;
	int flag = 1, flag2 = 0;
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->getType() == "a")
		{
			if (static_cast<Appetiser*>(items[i])->isTwoForOne() == true) //checks if 2-4-1
			{
				if (items[i]->getPrice() == price)
				{
					flag++;
					if (flag % 2 == 0) {
						savings += price;
					}
				}
				price = items[i]->getPrice(); // if 2-4-1 exists for an item, works out cheapest and subtracts from price
				if (cheapest == -1)
				{
					cheapest = items[i]->getPrice();
				}
				if (items[i]->getPrice() > cheapest)
				{
					cheapest = -2;
				}
			}
		}
		total += items[i]->getPrice(); 
	}
	if (cheapest > 0 && flag == 1)
	{
		savings = cheapest;
	}
	return total - savings;
}
//displays order and final total 
void ItemList::receipt()
{// creates receipt file to write too
	fstream fin;
	fin.open("receipt.txt.", ios::in | ios::out | ios::trunc);
	int count = 1;
	fin << "\n===== Checkout =====\n\n";
	for (int i = 0; i < items.size(); i++) {  //display details of appetisers ordered
		if (items[i]->getType() == "a")
		{
			fin << "(" << count << ") " << static_cast<Appetiser*>(items[i])->getName() << ": £" << static_cast<Appetiser*>(items[i])->getPrice() << ", " <<
				static_cast<Appetiser*>(items[i])->getCalories() << " cal (";
			if (static_cast<Appetiser*>(items[i])->isShareable() == true)
				fin << "shareable)";
			else if (static_cast<Appetiser*>(items[i])->isTwoForOne() == true)
				fin << "2-4-1)";
			count++;
			fin << "\n";
		}
	}
	for (int i = 0; i < items.size(); i++) { //display details of main courses ordered
		if (items[i]->getType() == "m")
		{
			fin << "(" << count << ") " << static_cast<MainCourse*>(items[i])->getName() << ": £" << static_cast<MainCourse*>(items[i])->getPrice() << ", " <<
				static_cast<MainCourse*>(items[i])->getCalories() << " cal";
			count++;
			fin << "\n";
		}
	}
	for (int i = 0; i < items.size(); i++) { //display details of beverages ordered
		if (items[i]->getType() == "b")
		{
			fin << "(" << count << ") " << static_cast<Beverage*>(items[i])->getName() << ": £" << static_cast<Beverage*>(items[i])->getPrice() << ", " <<
				static_cast<Beverage*>(items[i])->getCalories() << " cal (" << static_cast<Beverage*>(items[i])->getVolume() << "ml";
			if (static_cast<Beverage*>(items[i])->getAbv() > 0)
			{
				fin << ", " << static_cast<Beverage*>(items[i])->getAbv() << "% abv)";
			}
			else {
				fin << ")";
			}
			count++;
		}
	} //display details of everything ordered including savings with 2-4-1
	fin << "\n\n-----------------------\n\n";
	double savings = 0;
	double total = getTotal(savings);
	if (savings != 0)
	{
		fin << "2-4-1 discount applied! Savings: £" << savings << "\n";
	}
	fin << "Total: £" << total;
	fin << "\n";
	fin.close();

}
//displays menu information
void ItemList::displayList()
{
	int count = 1;
	cout << "----------------------Appetisers-----------------------\n";
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "a")
		{
			cout << "(" << count << ") " << static_cast<Appetiser*>(items[i])->getName() << ": \x9c" << static_cast<Appetiser*>(items[i])->getPrice() << ", " <<
				static_cast<Appetiser*>(items[i])->getCalories() << " cal (";
			if (static_cast<Appetiser*>(items[i])->isShareable() == true)
				cout << "shareable)";
			else if (static_cast<Appetiser*>(items[i])->isTwoForOne() == true)
				cout << "2-4-1)";
			count++;
			cout << "\n";
		}
	}
	cout << "----------------------Main dishes-----------------------\n";
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "m")
		{
			cout << "(" << count << ") " << static_cast<MainCourse*>(items[i])->getName() << ": \x9c" << static_cast<MainCourse*>(items[i])->getPrice() << ", " <<
				static_cast<MainCourse*>(items[i])->getCalories() << " cal";
			count++;
			cout << "\n";
		}
	}
	cout << "----------------------Beverages-----------------------\n";
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "b")
		{
			cout << "(" << count << ") " << static_cast<Beverage*>(items[i])->getName() << ": \x9c" << static_cast<Beverage*>(items[i])->getPrice() << ", " <<
				static_cast<Beverage*>(items[i])->getCalories() << " cal (" << static_cast<Beverage*>(items[i])->getVolume() << "ml";
			if (static_cast<Beverage*>(items[i])->getAbv() > 0)
			{
				cout << ", " << static_cast<Beverage*>(items[i])->getAbv() << "% abv)";
			}
			else {
				cout << ")";
			}
			count++;
			cout << "\n";
		}
	}
}
//displays checkout list
void ItemList::checkoutList()
{
	int count = 1;
	cout << "\n===== Checkout =====\n\n";
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "a")
		{
			cout << "(" << count << ") ";
			static_cast<Appetiser*>(items[i])->toString();
			count++;
			cout << "\n";
		}
	}
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "m")
		{
			cout << "(" << count << ") ";
			static_cast<MainCourse*>(items[i])->toString();
			count++;
			cout << "\n";
		}
	}
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "b")
		{
			cout << "(" << count << ") ";
			static_cast<Beverage*>(items[i])->toString();
			count++;
		}
	}
	cout << "\n\n-----------------------\n\n";
	double savings = 0;
	double total = getTotal(savings);
	if (savings != 0)
	{
		cout << "2-4-1 discount applied! Savings: \x9c" << savings << "\n";
	}
	cout << "Total: \x9c" << total;
	cout << "\n";
}
//sorts menu into correct order
void ItemList::sortMenu()
{
	int count = 1;
	for (int i = 1; i < items.size(); i++)
	{
		if (items[i]->getPrice() < items[i - 1]->getPrice())
		{
			swap(items[i], items[i - 1]);
		}
	}
	for (int i = 0; i < items.size(); i++) {
		if (items[i]->getType() == "a")
		{
			cout << "(" << count << ") ";
			static_cast<Appetiser*>(items[i])->toString();
			count++;
			cout << "\n";
		}
		else if (items[i]->getType() == "m")
		{
			cout << "(" << count << ") ";
			static_cast<MainCourse*>(items[i])->toString();
			count++;
			cout << "\n";
		}
		else if (items[i]->getType() == "b")
		{
			cout << "(" << count << ") ";
			static_cast<Beverage*>(items[i])->toString();
			count++;
			cout << "\n";
		}
	}

}
//once order is complete and reciept printed, deletes order for next order
ItemList::~ItemList()
{
	while (!items.empty()) {
		Item* item = items.back();
		items.pop_back();
		delete item;
	}
	items.clear();
	items.~vector();
}
