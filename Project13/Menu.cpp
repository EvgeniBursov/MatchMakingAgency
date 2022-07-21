#include "Menu.h"
#include "String.h"
using namespace std;

void PrintOptions() {
	cout << "====================================================" << endl;
	cout << "1) Add new client to the database" << endl;
	cout << "2) Remove an existing client from the database" << endl;
	cout << "3) Print all clients" << endl;
	cout << "4) Print all matches for a client" << endl;
	cout << "5) Quit the program" << endl;
	cout << "====================================================" << endl;

}
Menu::Menu()
{
	bool run = true;
	int option;
	while (run) {
		PrintOptions();
		cin >> option;
		switch (option) {
		case 1:
			AddClient();
			break;
		case 2:
			DeleteClient();
			break;
		case 3:
			PrintAllClients();
			break;
		case 4:
			FindMatches();
			break;
		case 5:
			run = false;
			break;
		default:
			cout << "Wrong option. Try again." << endl;
		}
	}
}
void Menu::DeleteClient() {
	char buffer[50];
	cout << "Enter the client ID:" << endl;
	cin >> buffer;
	String id(buffer);
	_agency -= id;
	cout << "The client deleted." << endl;
}

void Menu::AddClient()
{
	char id[50];
	char name[50];
	char sex;
	int age, amountOfHobbies;
	char** hobbies;

	cout << "Please enter all the needed detailed in order to add a new client to the database:" << endl;

	cout << "Please enter the ID:" << endl;
	cin >> id;

	cout << "Please enter the name:" << endl;
	cin >> name;

	cout << "Please enter the sex (m/f):" << endl;
	cin >> sex;

	cout << "Please enter the age:" << endl;
	cin >> age;

	cout << "Please enter the amount of hobbies:" << endl;
	cin >> amountOfHobbies;

	hobbies = new char* [amountOfHobbies];
	for (int i = 0; i < amountOfHobbies; i++)
	{
		char buffer[50];
		cout << "Enter the hobby number " << i + 1 << endl;
		cin >> buffer;
		hobbies[i] = _strdup(buffer);
	}
	Client* newClient = new Client(id, name, sex, age, hobbies, amountOfHobbies);
	_agency += (*newClient);

}
void Menu::PrintAllClients()
{
	for (int i = 0; i < _agency.getClientsSize(); i++)
	{
		cout << "Client number " << i + 1 << ":" << endl;
		cout << *(_agency.getClients()[i]) << endl;
	}
}
void Menu::FindMatches()
{
	char buffer[50];
	cout << "Enter the client ID:" << endl;
	cin >> buffer;
	String id(buffer);
	_agency.PrintMatchingClients(id);
}