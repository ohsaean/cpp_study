#pragma once
#include <iostream>

using namespace std;

class SpreadsheetCell
{
public:
	SpreadsheetCell();
	~SpreadsheetCell();

	void setValue(double inValue);
	double getValue() const;
	void setString(const std::string& inString);
	const std::string& getString() const; // inspector ?

private:
	std::string doubleToString(double inValue) const;
	double stringToDouble(const std::string& inString) const;
	double mValue;
	std::string mString;
};

