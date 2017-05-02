#include <stdio.h>
#include "myQueue.h"
#include "Element.h"

MyQueue::~MyQueue() {
    while(!isEmpty())
	clearFront();
}

bool MyQueue::isEmpty() const {
    return _front == nullptr;
}

Element MyQueue::deQueue() {
    if (isEmpty())
	printf("Queue is empty.\n");
    else {
	Element element = *(_front->data());
	clearFront();

	return element;
    }
}

void MyQueue::enQueue(const Element &element) {
    ElementNode* node = new ElementNode(&element);

    if (isEmpty())
	_front = node;
    else 
	_rear->setNext(node);

    _rear = node;
}

void MyQueue::clearFront() {
    ElementNode *node = _front;
    _front = node->next();
    delete node;
}
