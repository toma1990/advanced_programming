#ifndef MENU_H
#define MENU_H
#include"ItemList.h"
using namespace std;
class Menu : public ItemList // class inherits data from ItemList class to fill menu class
{
public: // attributes that are accessible from outside of the class
	Menu();
	Menu(string filename);
	void toString();
};
#endif // !MENU_H
