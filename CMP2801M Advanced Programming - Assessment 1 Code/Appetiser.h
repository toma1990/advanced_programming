#ifndef APPETISER_H
#define APPETISER_H
#include"Item.h"
using namespace std;
class Appetiser : public Item // class inherits appetiser data from Item class
{
private: // attributes that can only be accessed from this class
	bool shareable;
	bool twoForOne;
public: // attributes that are accessible from outside of the class
	void setShareable(bool flag);
	void setTowForOne(bool flag);
	bool isShareable();
	bool isTwoForOne();
	void toString();
};
#endif // !APPETISER_H