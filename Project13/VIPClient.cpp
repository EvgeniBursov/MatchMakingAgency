
#include "VIPClient.h"
//constructor
VIPClient::VIPClient(const String& id, const String& name, char sex, int age, char** hobby, int count, unsigned inCommonDemand)
	: Client(id, name, sex, age, hobby, count),
	_inCommonDemand(inCommonDemand)
{}

//copy constructor
VIPClient::VIPClient(VIPClient& other)
	: Client(other),
	_inCommonDemand(other._inCommonDemand)
{}
//distructor
VIPClient:: ~VIPClient()
{}

//operators
bool VIPClient::operator==(const VIPClient& other) const
{
	if (this->Client::operator==(other))
	{
		if (_inCommonDemand <= 1) {
			return true;
		}
		int count = 0;
		for (int i = 0; i < other.getCount(); i++)
		{
			for (int j = 0; j < getCount(); j++)
			{
				if (0 == strcmp(other.getHobbies()[i], getHobbies()[j]))
				{
					++count;
					if (count == _inCommonDemand) {
						break;
					}
				}
			}
			if (count == _inCommonDemand)
				break;
		}
		return count == _inCommonDemand;
	}
	return false;
}

