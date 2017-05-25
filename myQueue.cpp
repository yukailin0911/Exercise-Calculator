#include <stdio.h>
#include <cstddef>
#include "myQueue.h"
#include "element.h"

MyQueue::MyQueue(const MyQueue &queue): _front(NULL), _rear(NULL) {
    const ElementNode* temp = queue.front();

    while (temp) {
	enQueue(temp->data());
	temp = temp->next();
    }
}

MyQueue::~MyQueue() {
    clear();
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

const ElementNode* MyQueue::front() const {
    return _front;
}

MyQueue& MyQueue::operator=(const MyQueue &queue) {
    if (this != &queue)
	clear();

    const ElementNode *temp = queue.front();
    while (temp) {
	enQueue(temp->data());
	temp = temp->next();
    }

    return *this;
}

void MyQueue::clear() {
    while (!isEmpty())
	deleteFront();
}

void MyQueue::deleteFront() {
    ElementNode *node = _front;
    _front = node->next();
    delete node;
}
