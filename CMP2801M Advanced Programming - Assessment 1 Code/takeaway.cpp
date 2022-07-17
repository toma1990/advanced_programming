#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	cout << "Welcome to my Takeaway Ordering App! Please type 'help' for any assitance and type 'menu' to get started" ;

	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();
	// takes input from user
	while (userCommand != "exit")
	{

		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0]; // displays menu
		if (command.compare("menu") == 0) {
			cout << "\n";
			menu.toString();
		}
		else if (command.compare("add") == 0) //adds to order
		{
			for (int i = 1; i < parameters.size(); i++)
			{
				if (stoi(parameters[i]) >= 1 && stoi(parameters[i]) <= 3) //adds appetisers
				{
					Appetiser choice;
					menu.getAppetiser(choice, parameters[i]);
					string name = order.addAppetiser(choice);
					cout << name << " added in order!\n";
				}
				else if (stoi(parameters[i]) >= 4 && stoi(parameters[i]) <= 7) //adds main course
				{
					MainCourse choice;
					menu.getMainCourse(choice, parameters[i]);
					string name = order.addMainCourse(choice);
					cout << name << " added in order!\n";
				}
				else if (stoi(parameters[i]) >= 8 && stoi(parameters[i]) <= 12)//adds beverages
				{
					Beverage choice;
					menu.getBeverage(choice, parameters[i]);
					string name = order.addBeverage(choice);
					cout << name << " added in order!\n";
				}

			}
		}
		else if (command.compare("remove") == 0) //removes item from order
		{
			for (int i = 1; i < parameters.size(); i++)
			{
				string name = order.remove(parameters[i]);
				cout << name << " removed from order!\n";
			}
		}
		else if (command.compare("checkout") == 0) //checksout and brings up final total
		{
			char choice;
			order.checkout();
			cout << "Do you want to place your order?\n Type 'y' to confirm, or 'n' to go back and modify it\n";
			cin >> choice;
			if (choice == 'y')
			{
				order.printReceipt(); // saves receipt to debug folder
				cout << "\nreceipt.txt file save in debug folder\n";
			}
			else if (choice == 'n')
			{
				cout << "\nyou can modify your order\n";
			}
			else
			{
				cout << "\nInvalid Input\n";
			}
			cin.ignore();
			cin.clear();
		}
		else if (command.compare("help") == 0) // help menu
		{
			cout << "\nmenu - display the menu to the user \nsort - sort then menu in decending order of price value \nadd[INDEX] - add an item to the order by numeric index in the menu(starting at 1)" <<
				"\nremove[INDEX] - remove item from order by numeric index in the order(starting at 1) \ncheckout - display the items in the user’s order, the price, and discount savings" <<
				"\nhelp - display a help menu for the user with the available options \nexit - terminate the program gracefully\n";
		}
		else if (command.compare("sort") == 0)
		{
			cout << "\n-----Sorted Menu in decending order of price-----\n\n";
			menu.sortMenu();
		}
		parameters.clear();

	}

	cout << "\nPress any key to quit...";
	std::getchar();

}