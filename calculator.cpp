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
    _elementBuf = parse(expression);

    try {
	postfixExpression = postfixConvert(_elementBuf);
	evaluate(postfixExpression);
    } catch (const char * const err) {
	cerr << err << endl;
    }

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

MyQueue Calculator::postfixConvert(Element * const * const elementBuf) {
    MyStack stack(STACK_CAPACITY);
    MyQueue queue;

    for (int i = 0; i < _bufSize; ++i) {
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
