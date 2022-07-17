#include "Menu.h"
#include"Appetiser.h"
#include"MainCourse.h"
#include"Beverage.h"
#include <vector>
#include<fstream>
#include<string>
#include<sstream>

Menu::Menu()
{
}
// reads csv file
Menu::Menu(string filename)
{
	fstream fin;
	fin.open(filename, ios::in);
	vector<string> row;
	string line, word, temp;
	while (getline(fin, line)) {
		row.clear();
		stringstream s(line);
		while (getline(s, word, ',')) {
			if (word != "") {
				row.push_back(word);
			}
		}
		// menu information
		// appetiser details
		string symbol = row[0];
		if (symbol == "a")
		{
			Appetiser a; 
			a.setType(row[0]);
			a.setName(row[1]);
			a.setPrice(stod(row[2]));
			a.setCalories(stoi(row[3]));
			if (row[4] == "y")
			{
				a.setShareable(true);
			}
			else
			{
				a.setShareable(false);
			}
			if (row[5] == "y")
			{
				a.setTowForOne(true);
			}
			else
			{
				a.setTowForOne(false);
			}
			addAppetiser(a);
		}
		// main course details
		else if (symbol == "m")
		{
			MainCourse m;
			m.setType(row[0]);
			m.setName(row[1]);
			m.setPrice(stod(row[2]));
			m.setCalories(stoi(row[3]));
			addMainCourse(m);
		}
		// beverages details
		else if (symbol == "b")
		{
			Beverage b;
			b.setType(row[0]);
			b.setName(row[1]);
			b.setPrice(stod(row[2]));
			b.setCalories(stoi(row[3]));
			b.setVolume(stoi(row[4]));
			b.setAbv(stod(row[5]));
			addBeverage(b);
		}

	}

}
// displays menu
void Menu::toString()
{
	displayList();
}

