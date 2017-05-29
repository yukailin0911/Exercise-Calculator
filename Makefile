OBJS_CALCULATOR = main.o calculator.o myStack.o myQueue.o element.o

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

clean:
	rm *.o calculator 
