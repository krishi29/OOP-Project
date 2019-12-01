#define _CRT_SECURE_NO_WARNINGS

#include "PubRecord.h"
#include<cstring>
#include<iostream>
using namespace std;

void sdds::PubRecord::name(const char* name)
{
	if (name != nullptr) {
		this->pubName = new char[strlen(name) + 1];
		strcpy(this->pubName, name);
	}
	
}

const char* sdds::PubRecord::name() const
{
	if (this->pubName != nullptr) {
		char* copy = new char[strlen(pubName) + 1];
		strcpy(copy, this->pubName);
		return copy;
	}
	return nullptr;
	
}

sdds::PubRecord::PubRecord()
{
	this->pubName = nullptr;
	mType = SDDS_CONSOLE;
	shelfNumber = 0;
}

sdds::PubRecord::PubRecord(const PubRecord& pubRecord)
{
	if (pubRecord.name() != nullptr) {
		this->pubName = new char[strlen(pubRecord.name()) + 1];
		strcpy(this->pubName, pubRecord.name());
	}
	else {
		this->pubName = nullptr;
	}

	shelfNumber = pubRecord.shelfNumber;
	mType = pubRecord.mType;
}

sdds::PubRecord::~PubRecord()
{
	delete[] pubName;
}

void sdds::PubRecord::operator=(const PubRecord &pubRecord)
{
	if (pubRecord.name() != nullptr) {
		this->pubName = new char[strlen(pubRecord.name()) + 1];
		strcpy(this->pubName, pubRecord.name());
	}
	shelfNumber = pubRecord.shelfNumber;
	mType = pubRecord.mType;

}

void sdds::PubRecord::mediaType(int m)
{
	mType = m;
}

int sdds::PubRecord::mediaType() const
{
	return mType;
}

int sdds::PubRecord::shelfNo() const
{
	return shelfNumber;
}

int sdds::PubRecord::readShelfNo()
{
	int val;
	bool done = false;
	while (!done) {
		cin >> val;
		if (cin.fail()) {
			cin.clear();
			cout << "Invalid Shelf Number, Enter again: ";
		}
		else {
			if (val < 100 || val > 999) {
				cout << "Invalid Shelf Number, Enter again: ";
			}
			else {
				done = true;
			}
		}
		cin.ignore(1000, '\n');
	}
	shelfNumber = val;
	return val;
}

bool sdds::PubRecord::operator==(char recId)
{
	if (recId == recID()) {
		return true;
	}
	else {
		return false;
	}
}

bool sdds::PubRecord::operator==(const char* className)
{
	if (strstr(this->name(), className) == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

sdds::PubRecord::operator bool()const
{
	return this->pubName != nullptr;
}
