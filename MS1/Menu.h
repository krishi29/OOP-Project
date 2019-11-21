#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
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
		operator const char* ();
		std::ostream& display(std::ostream& os = std::cout)const;
	};

	class Menu {
	private:
		MenuItem titleItem;
		MenuItem *allItems[MAX_MENU_ITEMS];
		int totalMenuItems;
	public:
		Menu();
		Menu(const char* menuTitle);
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		std::ostream& displayMenu(std::ostream& os = std::cout)const;
		Menu& operator<<(const char*);
		unsigned int getSelection();
		unsigned int operator~();
		operator int();
		operator unsigned int();
		operator bool();
		const char* operator[](int)const;
		friend std::ostream& operator<<(std::ostream& os, Menu&);
	};

}
#endif