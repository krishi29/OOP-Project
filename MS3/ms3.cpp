/***********************************************************************
// OOP244 Project Milestone 3
// File	ms3.cpp
// Version 1.2
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019/11/19      intial release
// Fardad          2019/11/21      Added Date.h
// Fardad          2019/11/25      Set inital object to Console line(69)
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "PubRecord.h"
#include "colors.h"
using namespace std;
using namespace sdds;


class Newspaper :public PubRecord {
   Date m_date;
public:
   Newspaper() {};
   Newspaper(const Newspaper& N) :PubRecord(N), m_date(N.m_date) {};
   char recID()const {
      return 'N';
   }
   Newspaper& operator=(const Date& d) {
      m_date = d;
      return *this;
   }
   Newspaper& operator=(const char* thename) {
      name(thename);
      return *this;
   }
   std::istream& read(std::istream& is = std::cin) {
      char thename[51];
      cout << "Name: ";
      is.getline(thename, 50, '\n');
      cout << "Date: ";
      return is >> m_date;
   }
   std::ostream& write(std::ostream& os = std::cout)const {
      if (mediaType() == SDDS_CONSOLE) {
         os << "Name: " << name() << endl << "Shelf no: " << shelfNo() << endl << "Date: " << m_date;
      }
      else {
         os << recID() << name() << "," << shelfNo() << "," << m_date ;
      }
      return os;
   }
};



void print(Newspaper np);
void printg(const Newspaper& np);
void output(const char* value);
void message(const char* value);

int main() {
   cout << col_red << "PubRecord Tester...." << col_end << endl;
   Newspaper p;
   Newspaper s;
   message("Printing empty PubRecord: (all prints are using copy constructor!)");
   p.mediaType(SDDS_CONSOLE);
   print(p);
   message("Printing PubRecord");
   p = "OOP244 Daily";
   p = Date(2019, 11, 20);
   print(p);
   message("Chage print format to SDDS_FILE and print:");
   p.mediaType(SDDS_FILE);
   print(p);
   message("Testing date entry (and Back to SDDS_CONSOLE print):");
   cout << "Enter "<< col_cyan << "\"Seneca Daily\"" << col_end << " and then "<< col_cyan << "2019/12/12" << col_end << endl;
   cin >> p;
   p.mediaType(SDDS_CONSOLE);
   print(p);
   message("As of now printing directly with cout (no Copy Constructor):");
   printg(p);
   message("Setting shelf number:");
   cout << "Enter " << col_cyan << "24 " << col_end << "then " << col_cyan << "2444" << col_end << " and then " << col_cyan << "244" << col_end << endl;
   cout << "Enter Shelf number: ";
   p.readShelfNo();
   printg(p);
   message("PubRecord, operator=(const PupRecord&):");
   s = p;
   printg(s);
   message("PubRecord, operator==(const char*)");
   if (s == "Daily") {
      cout << "Operator== works correctly" << endl;
   }
   else {
      cout << col_red << "Operator== does not work correctly" << endl;
   }
   message("PubRecord, operator==(char)");
   if (s == 'N'){ 
      cout << "Operator== works correctly" << endl;
   }
   else {
      cout << col_red << "Operator== does not work correctly" << endl;
   }
   return 0;
}



void print(Newspaper np) {
   cout << col_green;
   if (!np) {
      cout << "Newspaper is not set!" << endl;
   }
   else {
      cout << np << endl;
   }
   cout << col_end;
}

void printg(const Newspaper& np) {
   cout << col_green;
   if (!np) {
      cout << "Newspaper is not set!" << endl;
   }
   else {
      cout << np << endl;
   }
   cout << col_end;
}

void output(const char* value) {
   cout << endl << col_green << value << col_green << endl;
}
void message(const char* value) {
   cout << endl << col_yellow << value << col_end << endl;
}