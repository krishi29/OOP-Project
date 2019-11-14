 // Final Project Milestone 1 
// Menu Module
// File	menuTester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/14		       Preliminary release
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Menu.h"
#include "Utils.h"


using namespace std;
using namespace sdds;
const char instructionMessages[10][81] = {
   ">>>>>Enter 0 and then 0 again",
   ">>>>>Enter 1",
   ">>>>>Enter 1 again",
   ">>>>>Enter 2",
   ">>>>>Enter 1",
   ">>>>>Enter 3",
   ">>>>>Enter 4 and then 3",
   ">>>>>Enter -1 and then 3",
   ">>>>>Enter abc and then 1",
   ">>>>>Enter 0 and then 0 again"
};

void showOrder(const unsigned int* cnt, const Menu& M);
int main() {
   unsigned int selections[3] = { 0 };
   unsigned int s;
   int mesIndex;
   Menu m1("Lunch Menu"), m2;
   if (!m2) {
      cout << "The " << m2 << " menu is empty" << endl;
   }
   else {
      cout << "Wrong output, your bool cast is done incorrenctly!";
   }
   m1 << "Omelet" << "Tuna Sandwich" << "California Roll";
   m2 << "Order more";
   if (m1) {
      cout << "The " << m1 << " is not empty and has " << (unsigned int)(m1) << " menu items." << endl;
   }
   else {
      cout << "Wrong output, your bool cast is done incorrenctly!";
   }
   for (mesIndex = 0; mesIndex < 10; mesIndex++) {
      if (mesIndex == 0) cout << instructionMessages[mesIndex] <<  endl;
      do {
         if (mesIndex > 0) cout <<  instructionMessages[mesIndex++] <<  endl;
         s = m1.getSelection();
         if (s) {
            selections[s - 1]++;
            cout << "you chose " << m1[s - 1] << endl;
         }
      } while (s != 0 || ~m2 != 0);
      showOrder(selections, m1);
   }
   return 0;
}
void showOrder(const unsigned int* cnt, const Menu& M) {
   bool orderedSomthing = false;
   cout << "Your orders: " << endl;
   for (int i = 0; i < 3; i++) {
      if (cnt[i]) {
         orderedSomthing = true;
         cout << cnt[i] << " " << M[i] << (cnt[i]>1?"s":"") << endl;
      }
   }
   if (!orderedSomthing) cout << "You didn't order anything!" << endl;
}
