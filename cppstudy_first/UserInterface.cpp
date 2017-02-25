#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

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
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------------" << endl;
	cout << "1) hire " << endl;
	cout << "2) fire " << endl;
	cout << "3) promote " << endl;
	cout << "4) list all " << endl;
	cout << "5) list current " << endl;
	cout << "6) list former " << endl;
	cout << "0) quit " << endl;
	cout << endl;
	cout << "---> ";
	cin >> selection;
	return selection;
}

void doHire(Database & db)
{
	string firstName;
	string lastName;
	cout << "first name ? ";
	cin >> firstName;
	cout << "last name ? ";
	cin >> lastName;

	try {
		db.addEmployee(firstName, lastName);
	}
	catch (const std::exception& exception) {
		cerr << "unable to add new employee : " << exception.what() << endl;
	}
}

void doFire(Database & db)
{
	int employeeNum;
	cout << "Employee number ? ";
	cin >> employeeNum;
	try {
		Employee emp = db.getEmployee(employeeNum);
		emp.fire();
		cout << "Employee " << employeeNum << " terminated." << endl;
	}
	catch (const std::exception& exception) {
		cerr << "unable to terminated employee : " << exception.what() << endl;
	}
}

void doPromote(Database & db)
{
	int employeeNum;
	int raiseAmount;
	cout << "Employee number ? ";
	cin >> employeeNum;
	cout << "how much of a raise ";
	cin >> raiseAmount;

	try {
		Employee emp = db.getEmployee(employeeNum);
		emp.promote(raiseAmount);
	}
	catch (const std::exception& exception) {
		cerr << "unable to promote employee : " << exception.what() << endl;
	}
}

void doDemote(Database & db)
{
	int employeeNum;
	int demeritAmount;
	cout << "Employee number? ";
	cin >> employeeNum;
	cout << "how much of a demerit? ";
	cin >> demeritAmount;

	try {
		Employee emp = db.getEmployee(employeeNum);
		emp.demote(demeritAmount);
	}
	catch (const std::exception& exception) {
		cerr << "unable to demote employee : " << exception.what() << endl;
	}
}
