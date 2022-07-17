#ifndef ORDER_H
#define ORDER_H
#include"ItemList.h"
using namespace std;
class Order : public ItemList // class inherits order data from Item class
{
private: // attributes that can only be accessed from this class
	double total;
public: // attributes that are accessible from outside of the class
	double calculateTotal();
	void printReceipt();
	void checkout();
	void toString();
};
#endif // !ORDER_H

