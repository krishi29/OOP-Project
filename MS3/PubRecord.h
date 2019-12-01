#ifndef NAMESPACE_PUBRECORD_H
#define NAMESPACE_PUBRECORD_H

#include"ReadWriteable.h"
#include<iostream>

#define SDDS_CONSOLE 1
#define SDDS_FILE 2
using namespace sdds;
namespace sdds {

	class PubRecord : public ReadWriteable 
	{

	private:
		char* pubName;
		int shelfNumber;
		int mType;

	protected:
		void name(const char*);
		const char* name()const;

	public:
		virtual char recID()const = 0;
		PubRecord();
		PubRecord(const PubRecord&);
		~PubRecord();
		void operator=(const PubRecord&);
		void mediaType(int);
		int mediaType()const;
		int shelfNo()const;
		int readShelfNo();
		bool operator==(char);
		bool operator==(const char*);
		operator bool()const;
	
	};



}

#endif