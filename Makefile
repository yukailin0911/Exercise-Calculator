OBJS_TEST_ELEMENT = testElement.o element.o
OBJS_TEST_MY_STACK = testMyStack.o myStack.o element.o
OBJS_TEST_MY_QUEUE = testMyQueue.o myQueue.o element.o

CFLAGS = -Wall

testElement: ${OBJS_TEST_ELEMENT}
	g++ -o testElement ${OBJS_TEST_ELEMENT}

testMyStack: ${OBJS_TEST_MY_STACK}
	g++ -o testMyStack ${OBJS_TEST_MY_STACK}

testMyQueue: ${OBJS_TEST_MY_QUEUE}
	g++ -o testMyQueue ${OBJS_TEST_MY_QUEUE}

clean:
	rm *.o testElement testMyStack testMyQueue
