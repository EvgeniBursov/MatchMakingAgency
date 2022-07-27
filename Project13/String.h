#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{

public:
	//constructor
	String(const char* string);
	//copy constructor
	String(const String& other);
	//distructor
	~String() { delete[]_string; }
	//operators:
	String& operator=(const String& other);
	bool operator==(const String& other)const;
	friend ostream& operator<<(ostream& out, const String& string);



private:
	char* _string;
};
