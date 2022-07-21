#pragma once
#include<iostream>
#include"String.h"
using namespace std;
class Client
{
public:

	//constructor
	Client(const String& id, const String& name, char sex, int age, char** hobby, int amountOfHobbies);

	//copy constructor
	Client(const Client& other);

	//distructor
	~Client();

	//operators
	friend ostream& operator<<(ostream& out, const Client& client);
	bool operator==(const Client& other)const;

	char** const getHobbies() const;
	const int getCount() const;
	const String getID() const;






private:
	String _id;
	String _name;
	char _sex;
	int _age;
	char** _hobby;
	int _amountOfHobbies;

};