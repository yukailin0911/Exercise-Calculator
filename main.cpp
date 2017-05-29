#include <iostream>
#include "calculator.h"

using namespace std;

const size_t BUF_SIZE = 101;

int main() {
    Calculator myCal = Calculator();
    char expression[BUF_SIZE];

    while (1) {
        cout << "===== Press Ctrl+C to exit. =====\n";
        cout << "Valid input characters: 0123456789()=-*/\n";
        cout << "Enter an arithmetic expression within "
             << BUF_SIZE - 1 << " characters: \n";

        cin.getline(expression, BUF_SIZE - 1, '\n');
        myCal.calculate(expression);
    }

    return 0;
}
