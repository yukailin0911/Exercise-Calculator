#include <iostream>
#include <cstring>
#include "Calculator.h"
#include "Element.h"

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

    clearBuf();
}

Element* Calculator::parse(const char * const expression) {
    _bufSize = strlen(expression);
    Element *buf = new Element [_bufSize];
    
    for (int i = 0; i < _bufSize; ++i)
	buf[i] = Element(expression[i]);

    return buf;
}

void Calculator::postfixConvert(Element * const elementBuf) {
    for (int i = 0; i < _bufSize; ++i) {
	if (elementBuf[i].isRParenthesis()) {
	    while (1) {
		if (_stack.isEmpty())
		    throw "Unbalanced Parentheses";

		Element element = _stack.pop();
		if (element.isLParenthesis()) {
		    element.setPriority(HIGHEST);
		    break;
		} else
		    _queue.enQueue(element)
	    }
	} else if (elementBuf[i].isOperator()) {
	    while ((!_stack.isEmpty()) && (_stack.top() >= elementBuf[i]))
		_queue.enQueue(_stack.pop());

	    if (elementBuf[i].isLParenthesis())
		elementBuf[i].setPriority(LOW);
	    _stack.push(elementBuf[i]);
	} else {
	    _queue.enQueue(elementBuf[i]);
	}
    }

    while (!_stack.isEmpty()) {
	if (_stack.top().isLParenthesis())
	    throw "Unbalanced Parentheses";

	_queue.enQueue(_stack.pop());
    }
}

void Calculator::evaluate(MyQueue &queue) {
    while (!queue.isEmpty()) {
	Element element = queue.deQueue();

	if (element.isOperator()) {
	    Element e[2];

	    for (int i = 1; i > -1; --i) {
		if (_stack.isEmpty())
			throw "Invalid Expression";
		e[i] = _stack.pop();
	    }

	    _stack.push(binaryEval(element, e[0], e[1]));
	} else {
	    _stack.push(element);
	}
    }

    Element outcome = _stack.pop();
    if (_stack.isEmpty())
	cout << outcome.value() << '\n';
    else 
	throw "Invalid Expression";
}

Element Calculator::binaryEval(const Element &op, const Element &e1, const Element &e2) const {
    double lVal = e1.value(), rVal = e2.value();

    switch(int(op.value())) {
	case 43:
	    return Element(lVal + rVal);
	case 45:
	    return Element(lVal - rVal);
	case 42:
	    return Element(lVal * rVal);
	case 47:
	    return Element(lVal / rVal);
    }
}

void Calculator::clearBuf() {
    delete[] _elementBuf;
}
