#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stddef.h>
#include "myStack.h"
#include "myQueue.h"

class Element;

class Calculator {
    #define STACK_CAPACITY 20

    public:
	Calculator(): _stack(MyStack(STACK_CAPACITY)), _elementBuf(NULL), _bufSize(0) {}
	~Calculator();

	void calculate(const char * const);

    private:
	MyStack _stack;
	MyQueue _queue;
	Element** _elementBuf;
	size_t _bufSize;

	Element** parse(const char * const);
	void postfixConvert(Element * const * const);
	void evaluate(MyQueue &);
	Element* binaryEval(const Operator * const,
		const Operand * const, const Operand * const) const;
	void clearStack();
	void clearQueue();
	void clearBuf();
};

#endif
