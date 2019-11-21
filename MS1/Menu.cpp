#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
sdds::MenuItem::MenuItem()
{
	description = nullptr;
}
sdds::MenuItem::MenuItem(const char* desc)
{
	if (desc != nullptr) {
		description = new char[strlen(desc) + 1];
		strcpy(description, desc);
	}
	else {
		description = nullptr;
	}
}

sdds::MenuItem::~MenuItem()
{
	delete[] description;
}

sdds::MenuItem::operator bool()
{
	if (description != nullptr && strlen(description) > 0) {
		return true;
	}
	return false;
}

sdds::MenuItem::operator const char* ()
{
	return description;
}

std::ostream& sdds::MenuItem::display(std::ostream& os) const
{
	if (this->description != nullptr) {
		os << description;
	}
	return os;
}

sdds::Menu::Menu()
{
	
}

sdds::Menu::Menu(const char* menuTitle)
{
	titleItem = MenuItem(menuTitle);

}

std::ostream& sdds::Menu::displayTitle(std::ostream& os) const
{
	return this->titleItem.display();
	return os;
}

std::ostream& sdds::Menu::displayMenu(std::ostream& os) const
{
	if (this->titleItem.description != nullptr) {
		displayTitle(os) << ":" << "\n";
	}
	for (int i = 0; i < totalMenuItems; i++) {
		os << "  " << this->allItems[i]->description << "\n";
	}
	os << "  0- Exit";
	os << ">";
	return os;
}

sdds::Menu& sdds::Menu::operator<<(const char* title) 
{
	if (totalMenuItems < MAX_MENU_ITEMS) {
		MenuItem newItem = MenuItem(title);
		*allItems[totalMenuItems] = newItem;
	}
	return *this;
}

unsigned int sdds::Menu::getSelection()
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

unsigned int sdds::Menu::operator~()
{
	return getSelection();
}

sdds::Menu::operator int()
{
	return this->totalMenuItems;
}

sdds::Menu::operator unsigned int()
{
	return this->totalMenuItems;
}

sdds::Menu::operator bool()
{
	return this->totalMenuItems > 0;
}

const char* sdds::Menu::operator[](int idx)const
{
	idx = idx % this->totalMenuItems;
	return (const char*)*allItems[idx];
}

std::ostream& sdds::operator<<(std::ostream& os, Menu& menu)
{
	return menu.displayTitle();
}
