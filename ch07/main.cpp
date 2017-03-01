#include <iostream>
#include <memory>
#include <string>
#include "SpreadsheetCell.h"

using namespace std;


int main() {
	auto myCellp = make_unique<SpreadsheetCell>();
	myCellp->setValue(3.7);
	cout << "cell 1: " << myCellp->getValue() << " " << myCellp->getString() << endl;
	return 0;
}