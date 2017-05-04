#include <stdio.h>
#include <assert.h>
#include "myQueue.h"
#include "element.h"

void testIsEmpty();
void testDeQueue();
void testEnQueue();

int main() {
    testIsEmpty();
    testEnQueue();
    testDeQueue();

    printf("===== Passed testMyQueue.\n");

    return 0;
}

void testIsEmpty() {
    MyQueue queue;
    assert(queue.isEmpty());
}

void testDeQueue() {
    MyQueue queue;
    Element *e1= new Operand(1);

    queue.enQueue(e1);
    assert(!queue.isEmpty());

    Element *e2 = queue.deQueue();
    printf("En-queued element is %f.\n", ((Operand *)e1)->value());
    printf("De-queued element is %f.\n", ((Operand *)e2)->value());
    assert(queue.isEmpty());

    delete e1;
}

void testEnQueue() {
    MyQueue queue;
    Element *e = new Operand(1);

    queue.enQueue(e);
    assert(!queue.isEmpty());

    delete e;
}
