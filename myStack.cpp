#include <cstdio>
#include <cstddef>
#include <cstring>
#include "myStack.h"
#include "element.h"

MyStack::MyStack(): _top(-1), _capacity(1) {
    _array = new Element* [_capacity];
    _array[0] = NULL;
}

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

const Element* const MyStack::top() const {
    if (isEmpty())
        return NULL;
    else
        return _array[_top];
}

void MyStack::resize() {
    Element **newArray = new Element* [_capacity * 2];

    memcpy(newArray, _array, _capacity * sizeof(Element*));

    delete[] _array;
    _array = newArray;
    _capacity *= 2;
}
