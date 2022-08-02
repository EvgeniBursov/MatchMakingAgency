
#include "String.h"
// fun copy
char* StringCopy(const char* string)
{
	if (!string)
	{
		return NULL;
	}

	int size = strlen(string) + 1;
	char* new_str = new char[size];

	strcpy(new_str, string);
	return new_str;
}

//constructor
String::String(const char* string) : _string(StringCopy(string))
{}

//copy constructor
String::String(const String& other) : _string(StringCopy(other._string))
{}

//distructor
String::~String()
{
	if (NULL != _string)
	{
		delete[] _string;
	}
}

// assignment operator
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[] _string;
		_string = StringCopy(other._string);
	}
	return *this;
}

//equality operator
bool String:: operator==(const String& other)const
{
	if (!_string || !other._string)
	{
		return false;
	}
	if (strcmp(_string, other._string) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//print string
ostream& operator<<(ostream& out, const String& string)
{
	cout << string._string << endl;
	return out;
}



