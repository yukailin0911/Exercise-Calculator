#include <stdio.h>
#include "myStack.h"

MyStack::MyStack(const int &size): _top(-1), _capacity(size) {
    _array = new Element* [_capacity];

    for (int i = 0; i < _capacity; ++i)
	_array[i] = nullptr;
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

MyStack::Element pop() {
    if (isEmpty())
	printf("Stack is empty. \n");
    else {
	Element element = *_array[_top];
	_array[_top--] = nullptr;

	return element;
    }
}

void MyStack::push(const Element &element) {
    if (isFull())
	resize();

    *_array[++_top] = element;
}

Element& MyStack::top() const {
    return *_array[_top];
}

void MyStack::resize() {
    Element **new_array = new Element* [_capacity * 2];

    for (int i = 0; i < _capacity; ++i)
	new_array[i] = _array[i];

    delete[] _array;
    _array = new_array;
    _capacity *= 2;
}
