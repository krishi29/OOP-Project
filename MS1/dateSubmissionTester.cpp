// Final Project Milestone 1 
// Date Tester program
// File	submissionTester.cpp
// Version 1.0
// Date	2011/11/11
// Author	Fardad Soleimanloo
// Description
// This programs test the student coding to complete of the Date class
//
// When testing before submission: DO NOT MODIFY THIS FILE IN ANY WAY
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2011/11/11		       Preliminary release
/////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "Date.h"
using namespace sdds;

// A fool proof Date entry from console 
Date getDate();
void dateTester(const Date& A, const Date& B);
int main() {
   Date
      D1,   // daysSince0001_1_1 to be recieved from console
      D2(2019, 11, 11);

   cout << "Current Date: " << D1 << endl;
   cout << D1 - D2 << " days since ms1 was published" << endl;
   cout << "Enter abc<ENTER>: ";
   cin >> D1;
   cout << D1 << endl;
   cout << "Enter 1000/1/1: ";
   cin >> D1;
   cout << D1 << endl;
   cout << "Enter 2000/13/1: ";
   cin >> D1;
   cout << D1 << endl;
   cout << "Enter 2000/1/0: ";
   cin >> D1;
   cout << D1 << endl;
   cout << "Enter 2019/11/11: ";
   cin >> D1;
   dateTester(D2, D1);
   cout << "Enter 2019/12/11: ";
   cin >> D1;
   dateTester(D2, D1);
   cout << "Enter 2019/10/11: ";
   cin >> D1;
   dateTester(D2, D1);
   return 0;
}

Date getDate() {
   Date D;
   do {
      cin >> D;      // get D from console
   } while (!D && cout << D.dateStatus() << ", Please try again > ");  // if D is invalid, print error message and loop
   return D;
}
void dateTester(const Date& A, const Date& B) {
   cout << "Days between the two dates: " << B - A << endl;
   cout << "All the following statements must be correct: " << endl;
   if (B > A) {
      cout << B << " > " << A << endl;
   }
   else {
      cout << B << " <= " << A << endl;
   }
   if (B < A) {
      cout << B << " < " << A << endl;
   }
   else {
      cout << B << " >= " << A << endl;
   }
   if (B <= A) {
      cout << B << " <= " << A << endl;
   }
   else {
      cout << B << " > " << A << endl;
   }
   if (B >= A) {
      cout << B << " >= " << A << endl;
   }
   else {
      cout << B << " < " << A << endl;
   }
   if (B == A) {
      cout << B << " == " << A << endl;
   }
   else {
      cout << B << " != " << A << endl;
   }
   if (B != A) {
      cout << B << " != " << A << endl;
   }
   else {
      cout << B << " == " << A << endl;
   }

}