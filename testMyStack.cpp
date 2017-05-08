#include <stdio.h>
#include <assert.h>
#include "myStack.h"
#include "element.h"

#define CAPACITY 3

void testIsFull();
void testIsEmpty();
void testPush();
void testPop();
void testTop();

void printPushed(const Element * const);
void printTop(const Element * const);
void printPopped(const Element * const);

int main() {
    testIsEmpty();
    testTop();
    testPush();
    testPop();
    testIsFull();

    printf("===== Passed testMyStack!\n");
    
    return 0;
}

void testIsFull() {
    MyStack stack(CAPACITY);
    Element **elements = new Element* [CAPACITY];

    for (int i = 0; i < CAPACITY; ++i) {
	elements[i] = new Operand(0);
	stack.push(elements[i]);
    }

    assert(stack.isFull());

    for (int i = 0; i < CAPACITY; ++i)
	delete elements[i];
    delete[] elements;
}

void testIsEmpty() {
    MyStack stack(CAPACITY);
    assert(stack.isEmpty());
}

void testPush() {
    MyStack stack(CAPACITY);
    Element **elements = new Element* [CAPACITY + 1];

    for (int i = 0; i < CAPACITY; ++i) {
	elements[i] = new Operand(i);
	stack.push(elements[i]);
	
	printPushed(elements[i]);
	printTop(stack.top());
    }

    elements[3] = new Operand(3);
    stack.push(elements[3]);
    printPushed(elements[3]);
    printTop(stack.top());
    
    assert(!stack.isFull());

    for (int i = CAPACITY; i > -1; --i)
	delete elements[i];
    delete[] elements;
}

void testPop() {
    MyStack stack(CAPACITY);
    Element *e1 = new Operand(0);

    stack.push(e1);
    assert(!stack.isEmpty());
    Element *e2 = stack.pop();

    printPushed(e1);
    printPopped(e2);
    assert(stack.isEmpty());

    delete e1;
}

void testTop() {
    MyStack stack(CAPACITY);
    Element *e = new Operand(0);

    stack.push(e);
    printPushed(e);
    printTop(stack.top());

    delete e;
}

void printPushed(const Element * const e) {
    printf("Pushed element is %f.\n", ((Operand *)e)->value());
}

void printTop(const Element * const e) {
    printf("Top element is %f.\n", ((Operand *)e)->value());
}

void printPopped(const Element * const e) {
    printf("Popped element is %f.\n", ((Operand *)e)->value());
}
