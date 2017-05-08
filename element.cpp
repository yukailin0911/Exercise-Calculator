#include "element.h"

bool Element::isOperator() const {
    return _kind != OPERAND;
}

bool Element::isLParenthesis() const {
    return _kind == L_PARENTHESIS;
}

bool Element::isRParenthesis() const {
    return _kind == R_PARENTHESIS;
}

double Operand::value() const {
    return _value;
}

Operator::Operator(const char &c) {
    switch (c) {
	case '(': {
		_priority = HIGHEST;
		_kind = L_PARENTHESIS;
	    } break;

	case ')': {
		_priority = HIGHEST;
		_kind = R_PARENTHESIS;
	    } break;

	case '*': {
		_priority = HIGH;
		_kind = MULTIPLY;
	    } break;

	case '/': {
		_priority = HIGH;
		_kind = DIVIDE;
	    } break;

	case '+': {
		_priority = MEDIUM;
		_kind = ADD;
	    } break;

	case '-': {
		_priority = MEDIUM;
		_kind = SUBSTRACT;
	    } break;
    }
}

Kind Operator::kind() const {
    return _kind;
}

void Operator::setPriority(const OperatorPriority &p) {
    _priority = p;
}

bool Operator::operator>=(const Operator &op) const {
    return _priority >= op._priority;
}

ElementNode* ElementNode::next() const {
    return _next;
}

Element* ElementNode::data() const {
    return _data;
}

void ElementNode::setNext(ElementNode *node) {
    _next = node;
}
