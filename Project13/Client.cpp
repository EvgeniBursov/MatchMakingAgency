#include "Client.h"

char** CreateHobbyListCopy(char** hobby, int amountOfHobbies)
{
	if (!hobby)
	{
		return NULL;
	}
	char** hobbies = new char* [amountOfHobbies];
	
	for (int i = 0; i < amountOfHobbies; i++)//copying hobby arr
	{
		hobbies[i] = hobby[i];
		//hobbies[i] = hobby[i] ? _strdup(hobby[i]) : NULL;
	}
	return hobbies;
}

Client::Client(const String& id, const String& name, char sex, int age, char** hobby, int amountOfHobbies)
	:_id(id),
	_name(name),
	_sex(sex),
	_age(age),
	_amountOfHobbies(amountOfHobbies),
	_hobby(CreateHobbyListCopy(hobby, amountOfHobbies))
{}

//copy constructor
Client::Client(const Client& other)
	:_id(other._id),
	_name(other._name),
	_sex(other._sex),
	_age(other._age),
	_hobby(CreateHobbyListCopy(other._hobby, other._amountOfHobbies))
{}

//distructor
Client::~Client()
{
	for (int i = 0; i < _amountOfHobbies; i++)
	{
		delete _hobby[i];
	}
	delete[]_hobby;
	//if (NULL != _hobby) {
	//	delete[] _hobby;
	//}
}

//print operator
ostream& operator<<(ostream& out, const Client& client)
{
	cout << "The id is: " << client._id << endl;
	cout << "The name is: " << client._name << endl;
	cout << "The sex is: " << client._sex << endl;
	cout << "The age is: " << client._age << endl;
	for (int i = 0; i < client._amountOfHobbies; i++)
	{
		cout << "The hobby number " << i + 1 << ". is: " << *(client._hobby[i]) << endl;
	}
	return out;
}

bool Client:: operator==(const Client& other)const
{
	if (other._sex == _sex) {
		return false;
	}
	int agediff = (other._age - _age);
	if (agediff > 5 || agediff < (-5)) {
		return false;
	}
	for (int i = 0; i < other._amountOfHobbies; i++)
	{
		for (int j = 0; j < _amountOfHobbies; j++)
		{
			if (0 == strcmp(other._hobby[i], _hobby[j]))
			{
				return true;
			}
		}
	}
	return false;

}
