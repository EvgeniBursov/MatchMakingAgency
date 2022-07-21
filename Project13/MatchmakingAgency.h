#include<iostream>
#include"Client.h"
using namespace std;
class MatchmakingAgency
{
	friend ostream& operator<<(ostream& out, const MatchmakingAgency& agency);
public:
	//default constructor
	MatchmakingAgency();

	//distructor
	~MatchmakingAgency();

	//operators
	void operator+=(const Client& other);
	void operator-=(const Client& other);
	void operator-=(const String& id);

public:
	void PrintMatchingClients(String id);
	Client** const getClients() const;
	int const getClientsSize() const;

private:
	Client** _clients;
	int _clientsSize;

private:
	MatchmakingAgency(const MatchmakingAgency&);
	MatchmakingAgency& operator=(const MatchmakingAgency&);

};
