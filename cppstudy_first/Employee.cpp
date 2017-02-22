#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {
	Employee::Employee()
		: mFirstName("")
		, mLastName("")
		, mEmployeeNumber(-1)
		, mSalary(kDefaultStartingSalary)
		, mHired(false)
	{

	}

	void Employee::promote(int raiseAmount) {
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount) {
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire() {
		mHired = true;
	}

	void Employee::fire() {
		mHired = false;
	}

	void Employee::display() const {
		cout << "" << endl;
	}
}