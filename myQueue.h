#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <cstddef>

class Element;
class ElementNode;

class MyQueue {
    public:
        MyQueue(): _front(NULL), _rear(NULL) {}
        MyQueue(const MyQueue &);
        ~MyQueue();

        bool isEmpty() const;
        Element* deQueue();
        void enQueue(Element * const);
        const ElementNode* front() const;
        MyQueue& operator=(const MyQueue &);

    private:
        ElementNode *_front;
        ElementNode *_rear;

        void clear();
        void deleteFront();
};

#endif
