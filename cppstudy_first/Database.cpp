
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {
	Database::Database() : mNextEmployeeNumber(kFirstEmployeeNumber)
	{
	}


	Database::~Database()
	{
	}
	Employee & Database::addEmployee(const std::string & firstName, const std::string & lastName)
	{
		// TODO: 여기에 반환 구문을 삽입합니다.
		Employee theEmployee;
		theEmployee.setFirstName(firstName);
		theEmployee.setLastName(lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1]; // 제일 마지막?
	}
	Employee & Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw runtime_error("No employee found");
	}
	Employee & Database::getEmployee(const std::string & firstName, const std::string & lastName)
	{
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName && employee.getLastName() == lastName) { // 연산자 오버로딩 되어있나??
				return employee;
			}
		}
		throw runtime_error("No employee found");
	}
	void Database::displayAll() const
	{
		for (const auto& employee : mEmployees) {
			employee.display();
		}
	}
	void Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.getIsHired()) {
				employee.display();
			}
		}
	}
	void Database::displayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (!employee.getIsHired()) {
				employee.display();
			}
		}
	}
}