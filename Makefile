OBJS_TEST_ELEMENT = testElement.o element.o
OBJS_TEST_MY_STACK = testMyStack.o myStack.o element.o

CFLAGS = -Wall

testElement: ${OBJS_TEST_ELEMENT}
	g++ -o testElement ${OBJS_TEST_ELEMENT}

testMyStack: ${OBJS_TEST_MY_STACK}
	g++ -o testMyStack ${OBJS_TEST_MY_STACK}

clean:
	rm *.o testElement testMyStack
