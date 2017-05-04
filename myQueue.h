#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <stddef.h>

class Element;
class ElementNode;

class MyQueue {
    public:
	MyQueue(): _front(NULL), _rear(NULL) {}
	~MyQueue();
	bool isEmpty() const;
	Element* deQueue();
	void enQueue(Element * const);

    private:
	ElementNode *_front;
	ElementNode *_rear;
	
	void deleteFront();
};

#endif
