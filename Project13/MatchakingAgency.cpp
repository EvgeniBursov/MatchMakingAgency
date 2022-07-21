#include<iostream>
#include "MatchmakingAgency.h"
using namespace std;
//default constructor
MatchmakingAgency::MatchmakingAgency()
	:_clients(NULL),
	_clientsSize(0)
{}
//distructor
MatchmakingAgency::~MatchmakingAgency()
{
	if (NULL != _clients) {
		for (unsigned i = 0; i < _clientsSize; ++i) {
			delete _clients[i];
		}
		delete[] _clients;
	}
}
//operators
ostream& operator<<(ostream& out, const MatchmakingAgency& agency)
{
	for (int i = 0; i < agency._clientsSize; i++)
	{
		cout << "Client number " << i + 1 << ": " << *(agency._clients[i]) << endl;
	}
	return out;
}

void MatchmakingAgency::operator+=(const Client& other)
{
	Client** clientsNew = new Client * [_clientsSize + 1];
	if (this->_clients) {
		memcpy(clientsNew, _clients, (sizeof(Client*) * _clientsSize));
		delete[] _clients;
	}
	clientsNew[_clientsSize] = new Client(other);
	_clients = clientsNew;
	_clientsSize++;
}
void MatchmakingAgency::operator-=(const Client& other)
{
	*this -= other.getID();
}

void MatchmakingAgency::operator-=(const String& id)
{
	for (int i = 0; i < _clientsSize; i++)
	{
		if (_clients[i]->getID() == id)
		{
			delete _clients[i];
			for (int j = i; j < _clientsSize; j++)
			{
				_clients[j] = _clients[j + 1];
			}
			_clients[_clientsSize - 1] = NULL;
			--_clientsSize;
		}
	}
}
void MatchmakingAgency::PrintMatchingClients(String id)
{
	int i;
	for (i = 0; i < _clientsSize; i++)
	{
		if (_clients[i]->getID() == id)
		{
			break;
		}
	}
	if (_clientsSize == i) {
		cout << "Wrong ID" << endl;
		return;
	}
	Client& client = *_clients[i];
	for (int j = 0; j <= _clientsSize; j++)
	{
		if (j == i) {
			// do not compare to himself
			continue;
		}
		if (client == (*(_clients[j])))
		{
			cout << "Matching client:" << *(_clients[j]) << endl;
		}
	}
}

Client** const MatchmakingAgency::getClients() const
{
	return _clients;
}

int const MatchmakingAgency::getClientsSize() const
{
	return _clientsSize;
}
