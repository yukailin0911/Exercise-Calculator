OBJS_TEST_ELEMENT = testElement.o element.o

CFLAGS = -Weverything

testElement: ${OBJS_TEST_ELEMENT}
	g++ -o testElement ${OBJS_TEST_ELEMENT}

clean:
	rm *.o testElement
