OBJS_CALCULATOR = main.o calculator.o myStack.o myQueue.o element.o
OBJS_TEST_ELEMENT = testElement.o element.o
OBJS_TEST_MY_STACK = testMyStack.o myStack.o element.o
OBJS_TEST_MY_QUEUE = testMyQueue.o myQueue.o element.o

CFLAGS = -Wall

calculator: ${OBJS_CALCULATOR}
	g++ -o calculator ${OBJS_CALCULATOR}

debug:
	g++ -g -c element.cpp
	g++ -g -c myQueue.cpp
	g++ -g -c myStack.cpp
	g++ -g -c calculator.cpp
	g++ -g -c main.cpp
	g++ -g ${OBJS_CALCULATOR} -o calculator

testElement: ${OBJS_TEST_ELEMENT}
	g++ -o testElement ${OBJS_TEST_ELEMENT}

testMyStack: ${OBJS_TEST_MY_STACK}
	g++ -o testMyStack ${OBJS_TEST_MY_STACK}

testMyQueue: ${OBJS_TEST_MY_QUEUE}
	g++ -o testMyQueue ${OBJS_TEST_MY_QUEUE}

clean:
	rm *.o calculator testElement testMyStack testMyQueue
