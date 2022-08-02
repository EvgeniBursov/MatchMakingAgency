#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
	friend ostream& operator<<(ostream& out, const String& string);

public:
	//constructor
	String(const char* string);
	//copy constructor
	String(const String& other);
	//distructor
	~String();
	//operators:
	String& operator=(const String& other);
	bool operator==(const String& other)const;



private:
	char* _string;
};

