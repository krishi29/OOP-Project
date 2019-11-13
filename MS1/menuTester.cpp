#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
using namespace sdds;
int main() {
   Menu m1("Lunch Menu"), m2;
   if (!m2) {
      cout << "The " << m2 << " menu is empty" << endl;
   }
   m1 << "Omelet" << "Tuna Sandwich" << "California Rolls";
   m2 << "Run the test again.";
   unsigned int s;
   if (m1) {
      cout << "The " << m1 << " is not empty and has " << unsigned int(m1) << " menu items." << endl;
   }
   do {
      s = m1.getSelection();
      cout << "you chose " << s << endl;
   } while (~m2 != 0);
   return 0;
}
