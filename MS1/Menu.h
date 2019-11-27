#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

using namespace std;
namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem {

	private:
		char* description;
		friend class Menu;
		
	public:
		MenuItem();
		MenuItem(const char*);
		~MenuItem();
		operator bool();
		operator const char* ()const;
		std::ostream& display(ostream& os = cout)const;
	};

	class Menu {
	private:
		MenuItem titleItem;
		MenuItem allItems[MAX_MENU_ITEMS];
		int totalMenuItems;
	public:
		Menu();
		Menu(const char* menuTitle);
		ostream& displayTitle(ostream& os = cout)const;
		ostream& displayMenu(ostream& os = cout)const;
		Menu& operator<<(const char*);
		unsigned int getSelection();
		unsigned int operator~();
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator[](int)const;
		friend ostream& operator<<(ostream& os, Menu& menu);
	};

}
#endif // !NAMESPACE_MENU_H