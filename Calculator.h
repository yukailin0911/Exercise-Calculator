#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "myStack.h"
#include "myQueue.h"

class Element;

class Calculator {
    #define STACK_CAPACITY 20

    public:
	Calculator(): _stack(MyStack(STACK_CAPACITY)), _elementBuf(nullptr), _bufSize(0) {}
	~Calculator();

	void calculate(const char * const);

    private:
	MyStack _stack;
	MyQueue _queue;
	Element* _elementBuf;
	size_t _bufSize;

	Element* parse(const char * const);
	void postfixConvert(Element * const);
	void evaluate(MyQueue &);
	Element binaryEval(const Element &, const Element &, const Element &) const;
	void clearBuf();
};

#endif
