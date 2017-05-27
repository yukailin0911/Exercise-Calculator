#include <iostream>
#include <cstddef>
#include <cstring>
#include "calculator.h"
#include "element.h"
#include "myStack.h"
#include "myQueue.h"

using namespace std;

const int STACK_CAPACITY = 20;

Calculator::~Calculator() {
    if (_elementBuf)
	clearBuf();
}

void Calculator::calculate(const char * const expression) {
    MyQueue postfixExpression;
    parse(expression);

    try {
	postfixExpression = postfixConvert(_elementBuf);
	evaluate(postfixExpression);
    } catch (const char * const err) {
	cerr << err << endl;
    }

    clearBuf();
}

void Calculator::parse(const char * const expression) {
    const char *ptrOperator = NULL, *ptrOperand = NULL;
    const char OPERATORS[] = "+-*/()";
    char *copyExpression = new char [strlen(expression) + 1];
    size_t bufIndex = 0;

    setBufSize(expression);
    setElementBuf(_bufSize);

    strcpy(copyExpression, expression);
    ptrOperator = strpbrk(expression, OPERATORS);

    if (ptrOperator == expression) {
	ptrOperator = parseOperators(ptrOperator, bufIndex, OPERATORS);
    }

    ptrOperand = strtok(copyExpression, OPERATORS);
    while (ptrOperand) {
	_elementBuf[bufIndex] = new Operand(atof(ptrOperand));
	++bufIndex;

	if (ptrOperator)
	    ptrOperator = parseOperators(ptrOperator, bufIndex, OPERATORS);

	ptrOperand = strtok(NULL, OPERATORS);
    }

    delete[] copyExpression;
}

MyQueue Calculator::postfixConvert(Element * const * const elementBuf) {
    size_t i(0);
    MyStack stack(STACK_CAPACITY);
    MyQueue queue;

    while (elementBuf[i] && (i < _bufSize)) {
	if (elementBuf[i]->isRParenthesis()) {
	    Element *temp;

	    while (1) {
		temp = stack.pop();
		if (!temp) {
		    throw "Unbalanced Parentheses";
		}else if (temp->isLParenthesis()) {
		    ((Operator *)temp)->setPriority(HIGHEST);
		    break;
		} else {
		    queue.enQueue(temp);
		}
	    }
	} else if (elementBuf[i]->isOperator()) {
	    while ((stack.top()) &&
		    (*(Operator *)stack.top() >= *(Operator *)elementBuf[i]))
		queue.enQueue(stack.pop());

	    if (elementBuf[i]->isLParenthesis())
		((Operator *)elementBuf[i])->setPriority(LOW);
	    stack.push(elementBuf[i]);
	} else {
	    queue.enQueue(elementBuf[i]);
	}

	++i;
    }

    while (!stack.isEmpty()) {
	if (stack.top()->isLParenthesis())
	    throw "Unbalanced Parentheses";

	queue.enQueue(stack.pop());
    }

    return queue;
}

void Calculator::evaluate(MyQueue &queue) {
    MyStack stack(STACK_CAPACITY);
    Element *element;
    Operand *lOperand, *rOperand;
    double tempValue;

    while ((element = queue.deQueue())) {
	if (element->isOperator()) {
	    rOperand = (Operand *)stack.pop();
	    if (!rOperand) throw "Invalid Expression";
	    lOperand = (Operand *)stack.pop();
	    if (!lOperand) throw "Invalid Expression";

	    tempValue = binaryEval((Operator *)element, lOperand, rOperand);
	    lOperand->setValue(tempValue);
	    stack.push(lOperand);
	} else {
	    stack.push(element);
	}
    }

    Element* outcome = stack.pop();
    if (!outcome || !stack.isEmpty())
	throw "Invalid Expression";
    else
	cout << ((Operand *)outcome)->value() << '\n';
}

void Calculator::setBufSize(const char * const expression) {
    const char *pch = NULL;
    const char OPERATORS[] = "+-*/()";
    _bufSize = 0;

    pch = strpbrk(expression, OPERATORS);
    while (pch) {
	_bufSize += 2;
	pch = strpbrk(pch + 1, OPERATORS);
    }

    ++_bufSize;
}

void Calculator::setElementBuf(const size_t &bufSize) {
    if (_elementBuf)
	clearBuf();

    if (bufSize == 0)
	_elementBuf = NULL;
    else {
	_elementBuf = new Element* [bufSize];

	for (int i = 0; i < bufSize; ++i)
	    _elementBuf[i] = NULL;
    }
}

const char* Calculator::parseOperators(const char *ptrOperator,
	size_t &bufIndex, const char *OPERATORS) {
    _elementBuf[bufIndex] = new Operator(*ptrOperator);
    ++bufIndex;

    const char *nextOperator = strpbrk(ptrOperator + 1, OPERATORS);
    while (nextOperator && ((nextOperator - ptrOperator) == 1)) {
	ptrOperator = nextOperator;
	_elementBuf[bufIndex] = new Operator(*ptrOperator);
	++bufIndex;
	nextOperator = strpbrk(ptrOperator + 1, OPERATORS);
    }

    return nextOperator;
}

double Calculator::binaryEval(const Operator * const op,
	const Operand * const e1, const Operand * const e2) const {
    double lVal = e1->value(), rVal = e2->value();

    switch(op->kind()) {
	case ADD:
	    return lVal + rVal;
	case SUBSTRACT:
	    return lVal - rVal;
	case MULTIPLY:
	    return lVal * rVal;
	case DIVIDE: {
	    if (!rVal)
		throw "Invalid Expression";
	    return lVal / rVal;
	}
	default:
	    throw "Invalid Expression";
    }
}

void Calculator::clearBuf() {
    size_t index(0);

    while (_elementBuf[index] && (index < _bufSize)) {
	    delete _elementBuf[index];
	    ++index;
    }

    delete[] _elementBuf;

    _bufSize = 0;
    _elementBuf = NULL;
}
