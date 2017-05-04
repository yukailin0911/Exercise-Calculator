#include <stdio.h>
#include <stddef.h>
#include "myStack.h"

MyStack::MyStack(const int &size): _top(-1), _capacity(size) {
    _array = new Element* [_capacity];

    for (int i = 0; i < _capacity; ++i)
	_array[i] = NULL;
}

MyStack::~MyStack() {
    delete[] _array;
}

bool MyStack::isFull() const {
    return _top == (_capacity - 1);
}

bool MyStack::isEmpty() const {
    return _top == -1;
}

Element* MyStack::pop() {
    if (isEmpty())
	return NULL;
    else {
	Element* element = _array[_top];
	_array[_top--] = NULL;

	return element;
    }
}

void MyStack::push(Element *element) {
    if (isFull())
	resize();

    _array[++_top] = element;
}

Element* MyStack::top() const {
    return _array[_top];
}

void MyStack::resize() {
    Element **newArray = new Element* [_capacity * 2];

    for (int i = 0; i < _capacity; ++i)
	newArray[i] = _array[i];

    delete[] _array;
    _array = newArray;
    _capacity *= 2;
}
