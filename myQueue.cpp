#include <stdio.h>
#include <stddef.h>
#include "myQueue.h"
#include "element.h"

MyQueue::~MyQueue() {
    while(!isEmpty())
	deleteFront();
}

bool MyQueue::isEmpty() const {
    return _front == NULL;
}

Element* MyQueue::deQueue() {
    if (isEmpty())
	return NULL;
    else {
	Element *element = _front->data();
	deleteFront();

	return element;
    }
}

void MyQueue::enQueue(Element * const element) {
    ElementNode* node = new ElementNode(element);

    if (isEmpty())
	_front = node;
    else 
	_rear->setNext(node);

    _rear = node;
}

void MyQueue::deleteFront() {
    ElementNode *node = _front;
    _front = node->next();
    delete node;
}
