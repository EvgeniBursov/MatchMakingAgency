#include "VIPClient.h"
#include <iostream>
#include "MatchmakingAgency.h"

using namespace std;
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
