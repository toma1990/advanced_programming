#ifndef MAINCOURSE_H
#define MAINCOURSE_H
#include"Item.h"
using namespace std;
class MainCourse : public Item // class inherits Main course data from Item class
{
public: // attributes that are accessible from outside of the class
	void toString();
};
#endif // !MAINCOURSE_H
