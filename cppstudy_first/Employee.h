#pragma once
#include <string>

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee();
		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); // ������ ä�� �Ǵ� ��ä��
		void fire(); // ������ �ذ�
		void display() const; // �ֿܼ� ������ ���� ���

		// getter, setter

		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool getIsHired() const;
	};
}
