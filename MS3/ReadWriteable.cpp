
#include<iostream>
#include"ReadWriteable.h"
using namespace std;
namespace sdds {
	ostream& operator<< (ostream& os, const ReadWriteable& rw) {
		rw.write(os);
		return(os);

	}
	istream& operator>> (istream& is,  ReadWriteable& rw) {
		rw.read(is);
		return is;

	}
}