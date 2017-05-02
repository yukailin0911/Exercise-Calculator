#ifndef _MY_QUEUE_H
#define _MY_QUEUE_H

class Element
class ElementNode;

class MyQueue {
    public:
	MyQueue(): _front(nullptr), _rear(nullptr) {}
	~MyQueue();
	bool isEmpty() const;
	Element deQueue();
	void enQueue(const Element &);

    private:
	ElementNode *_front;
	ElementNode *_rear;
	
	void clearFront();
};

#endif
