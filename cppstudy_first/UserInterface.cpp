#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
int doHire(Database& db);
int doFire(Database& db);
int doPromote(Database& db);
int doDemote(Database& db);

int main() {
	Database employeeDB;
	bool done = false;

	for (; !done ;) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Uknown Command." << endl;
			break;
		}
	}

	return 0;
}

int displayMenu()
{
	return 0;
}

int doHire(Database & db)
{
	return 0;
}

int doFire(Database & db)
{
	return 0;
}

int doPromote(Database & db)
{
	return 0;
}

int doDemote(Database & db)
{
	return 0;
}
