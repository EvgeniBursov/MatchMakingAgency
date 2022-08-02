#pragma once
#include "Client.h"


class VIPClient : public Client
{
public:

	//constructor
	VIPClient(const String& id, const String& name, char sex, int age, char** hobby, int amountOfHobbies, unsigned inCommonDemand);

	//copy constructor
	VIPClient(VIPClient& other);

	//distructor
	~VIPClient();

	//operators
	bool operator==(const VIPClient& other)const;

private:
	unsigned _inCommonDemand;
};

