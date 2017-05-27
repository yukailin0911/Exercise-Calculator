#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cstddef>

class Element;
class Operator;
class Operand;
class MyQueue;

class Calculator {
    public:
	Calculator(): _elementBuf(NULL), _bufSize(0) {}
	~Calculator();

	void calculate(const char * const);

    private:
	Element** _elementBuf;
	size_t _bufSize;

	void parse(const char * const);
	MyQueue postfixConvert(Element * const * const);
	void evaluate(MyQueue &);
	void setBufSize(const char * const);
	void setElementBuf(const size_t &);
	const char* parseOperators(const char *, size_t &, const char *);
	double binaryEval(const Operator * const,
		const Operand * const, const Operand * const) const;
	void clearBuf();
};

#endif
