#include "Order.h"

double Order::calculateTotal()  //calculates total
{
	double savings = 0;
	return getTotal(savings);
}

void Order::printReceipt() 
{
	toString();
}

void Order::checkout() 
{
	checkoutList();
}

void Order::toString() 
{
	receipt();
}
