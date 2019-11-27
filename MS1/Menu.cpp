#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

namespace sdds
{

	MenuItem::MenuItem()
	{
		description = nullptr;
	}
	MenuItem::MenuItem(const char* desc)
	{
		if (desc != nullptr) {
			int strlen2 = strlen(desc) + 1;
			description = new char[strlen2];
			strcpy(description, desc);
		}
		else {
			description = nullptr;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] description;
	}

	MenuItem::operator bool()
	{
		if (description != nullptr && strlen(description) > 0) {
			return true;
		}
		return false;
	}

	MenuItem::operator const char* ()const
	{
		return this->description;
	}

	std::ostream& MenuItem::display(std::ostream& os) const
	{
		if (this->description != nullptr) {
			os << description;
		}
		return os;
	}

	Menu::Menu()
	{
		titleItem.description = nullptr;
		totalMenuItems = 0;
	}

	Menu::Menu(const char* menuTitle)
	{
		titleItem.description = new char[strlen(menuTitle) + 1];
		strcpy(titleItem.description, menuTitle);
		totalMenuItems = 0;
	}

	std::ostream& Menu::displayTitle(std::ostream& os) const
	{
		return this->titleItem.display();
		return os;
	}

	std::ostream& Menu::displayMenu(std::ostream& os) const
	{
		if (this->titleItem.description != nullptr) {
			displayTitle(os) << ":" << "\n";
		}
		for (int i = 0; i < totalMenuItems; i++) {
			os << " " << i + 1 << "- " << this->allItems[i].description << "\n";
		}
		os << " 0- Exit" << endl;
		os << "> ";
		return os;

	}

	Menu& Menu::operator<<(const char* title)
	{
		if ((unsigned)totalMenuItems < MAX_MENU_ITEMS) {
			MenuItem* newItem = new MenuItem(title);
			this->allItems[totalMenuItems] = *newItem;
			totalMenuItems++;
		}
		return *this;

	}

	unsigned int Menu::getSelection()
	{
		displayMenu(cout);
		int val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Selection, try again: ";
			}
			else {
				if (val < 0 || val > totalMenuItems) {
					cout << "Invalid Selection, try again: ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;

	}

	unsigned int Menu::operator~()
	{
		return getSelection();
	}

	Menu::operator int()
	{
		return this->totalMenuItems;
	}

	Menu::operator unsigned int()
	{
		return this->totalMenuItems;
	}

	Menu::operator bool()
	{
		return this->totalMenuItems > 0;
	}

	const char* Menu::operator[](int idx)const
	{
		idx = idx % this->totalMenuItems;
		const MenuItem* item = this->allItems + idx;
		return *item;
	}

	ostream& operator<<(ostream& os, Menu& menu)
	{
		return menu.displayTitle();
	}
}
