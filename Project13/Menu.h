#pragma once
#include "VIPClient.h"
#include "MatchmakingAgency.h"

class Menu
{
public:
	//constructor
	Menu();

private:
	void AddClient();
	void DeleteClient();
	void PrintAllClients();
	void FindMatches();
private:
	MatchmakingAgency _agency;
private:
	Menu(const Menu&);
	Menu& operator=(const Menu&);
};

