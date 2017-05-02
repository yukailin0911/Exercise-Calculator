#include <stdio.h>
#include <assert.h>
#include "element.h"

void testIsOperator();
void testIsLParenthesis();
void testIsRParenthesis();
void testOperatorOverloading();

int main() {
    testIsOperator();
    testIsLParenthesis();
    testIsRParenthesis();
    testOperatorOverloading();

    printf("Passed testElement!\n");

    return 0;
}

void testIsOperator() {
    Element *e1 = new Operator('*');
    Element *e2 = new Operand(55.5);
    
    assert(e1->isOperator());
    assert(!e2->isOperator());

    delete e1;
    delete e2;
}

void testIsLParenthesis() {
    Element *e = new Operator('(');
    assert(e->isLParenthesis());
    delete e;
}

void testIsRParenthesis() {
    Element *e = new Operator(')');
    assert(e->isRParenthesis());
    delete e;
}

void testOperatorOverloading() {
    Element *e1 = new Operator('(');
    Element *e2 = new Operator('*');
    
    assert(*(Operator *)e1 >= *(Operator *)e2);

    delete e1;
    delete e2;
}
