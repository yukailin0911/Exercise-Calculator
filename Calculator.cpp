#include <iostream>
#include <cstring>
#include "calculator.h"
#include "element.h"

using namespace std;

Calculator::~Calculator() {
    clearBuf();
}

void Calculator::calculate(const char * const expression) {
    _elementBuf = parse(expression);

    try {
	postfixConvert(_elementBuf);
	evaluate(_queue);
    } catch (const char * const err) {
	cerr << err << endl;
    }

    clearStack();
    clearQueue();
    clearBuf();
}

Element** Calculator::parse(const char * const expression) {
    _bufSize = strlen(expression);
    Element **buf = new Element* [_bufSize];
    
    for (int i = 0; i < _bufSize; ++i) {
	if ((expression[i] >= 48) && (expression[i] <= 57))
	    buf[i] = new Operand(atof(expression + i));
	else
	    buf[i] = new Operator(expression[i]);
    }

    return buf;
}

void Calculator::postfixConvert(Element * const * const elementBuf) {
    for (int i = 0; i < _bufSize; ++i) {
	if (elementBuf[i]->isRParenthesis()) {
	    while (1) {
		if (_stack.isEmpty())
		    throw "Unbalanced Parentheses";

		Element *element = _stack.pop();
		if (element->isLParenthesis()) {
		    ((Operator *)element)->setPriority(HIGHEST);
		    break;
		} else
		    _queue.enQueue(element);
	    }
	} else if (elementBuf[i]->isOperator()) {
	    while ((!_stack.isEmpty()) &&
		    (*(Operator *)_stack.top() >= *(Operator *)elementBuf[i]))
		_queue.enQueue(_stack.pop());

	    if (elementBuf[i]->isLParenthesis())
		((Operator *)elementBuf[i])->setPriority(LOW);
	    _stack.push(elementBuf[i]);
	} else {
	    _queue.enQueue(elementBuf[i]);
	}
    }

    while (!_stack.isEmpty()) {
	if (_stack.top()->isLParenthesis())
	    throw "Unbalanced Parentheses";

	_queue.enQueue(_stack.pop());
    }
}

void Calculator::evaluate(MyQueue &queue) {
    Element *element;
    Operand *e[2];
    double value;

    if (queue.isEmpty())
	throw "Invalid Expression";

    while (!queue.isEmpty()) {
	element = queue.deQueue();

	if (element->isOperator()) {
	    for (int i = 1; i > -1; --i) {
		if (_stack.isEmpty())
			throw "Invalid Expression";
		e[i] = (Operand *)_stack.pop();
	    }

	    value = binaryEval((Operator *)element, e[0], e[1]);
	    e[0]->setValue(value);
	    _stack.push(e[0]);
	} else {
	    _stack.push(element);
	}
    }

    Element* outcome = _stack.pop();
    if (_stack.isEmpty())
	cout << ((Operand *)outcome)->value() << '\n';
    else 
	throw "Invalid Expression";
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
	case DIVIDE:
	    return lVal / rVal;
	default:
	    throw "Invalid Expression";
    }
}

void Calculator::clearStack() {
    while(!_stack.isEmpty())
	_stack.pop();
}

void Calculator::clearQueue() {
    while(!_queue.isEmpty())
	_queue.deQueue();
}

void Calculator::clearBuf() {
    for (int i = 0; i < _bufSize; ++i)
	delete _elementBuf[i];
    delete[] _elementBuf;
}
