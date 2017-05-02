#ifndef _MY_STACK_H
#define _MY_STACK_H

#include "Element.h"

class MyStack {
    public:
	MyStack(const int &);
	~MyStack();

	bool isFull() const;
	bool isEmpty() const;
	Element pop();
	void push(const Element &);
	Element& top() const;

    private:
	int _top;
	int _capacity;
	Element **_array;

	void resize();
}

#endif
