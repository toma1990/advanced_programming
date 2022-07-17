#include "MainCourse.h"
#include<iostream>
using namespace std;
void MainCourse::toString()  //converts all data to string format
{
	cout << static_cast<MainCourse*>(this)->getName() << ": \x9c" << static_cast<MainCourse*>(this)->getPrice() << ", " <<
		static_cast<MainCourse*>(this)->getCalories() << " cal";
}
