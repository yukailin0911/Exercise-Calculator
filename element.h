#ifndef MY_ELEMENT_H
#define MY_ELEMENT_H

#include <cstddef>

enum Kind {
    OPERAND,
    ADD,
    SUBSTRACT,
    MULTIPLY,
    DIVIDE,
    L_PARENTHESIS,
    R_PARENTHESIS
};

enum OperatorPriority {
    LOW,
    MEDIUM,
    HIGH,
    HIGHEST
};

class Element {
    public:
	Element() {}
	Element(const Kind &k): _kind(k) {}
	bool isOperator() const;
	bool isLParenthesis() const;
	bool isRParenthesis() const;

    protected:
	Kind _kind;
};

class Operand: public Element {
    public:
	Operand(const double &d): Element(OPERAND), _value(d) {}

	double value() const;

    private:
	double _value;
};

class Operator: public Element {
    public:
	Operator(const char &);

	Kind kind() const;
	void setPriority(const OperatorPriority &);
	bool operator>=(const Operator &) const;

    private:
	OperatorPriority _priority;
};

class ElementNode {
    public:
	ElementNode(Element * const e): _next(NULL), _data(e) {}

	ElementNode* next() const;
	Element* data() const;
	void setNext(ElementNode *);

    private:
	ElementNode *_next;
	Element * const _data;
};

#endif
