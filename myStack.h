#ifndef MY_STACK_H
#define MY_STACK_H

class Element;

class MyStack {
    public:
	MyStack();
	MyStack(const int &);
	~MyStack();

	bool isFull() const;
	bool isEmpty() const;
	Element* pop();
	void push(Element *);
	const Element* const top() const;

    private:
	int _top;
	int _capacity;
	Element **_array;

	void resize();
};

#endif
