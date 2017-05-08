#include <iostream>
#include "calculator.h"

using namespace std;

#define BUF_SIZE 40

int main() {
    Calculator myCal = Calculator();
    char expression[BUF_SIZE];

    while (1) {
	cout << "Enter an arithmetic expression: \n";
	cin.getline(expression, BUF_SIZE, '\n');
	myCal.calculate(expression);
    }

    return 0;
}
