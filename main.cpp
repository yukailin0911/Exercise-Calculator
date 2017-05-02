#include <iostream>
#include "Calculator.h"

using namespace std;

#define BUF_SIZE 40

int main(int argc, char *argv[]) {
    Calculator myCal = Calculator();
    char* expression;

    while (1) {
	cout << "Enter an arithmetic expression: \n";
	cin.getline(expression, BUFF_SIZE, '\n');
	myCal.calculate(expression);
    }

    return 0;
}
