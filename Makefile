all: bin/main bin/tests

bin/main: obj/main.o obj/node.o obj/graph.o obj/stack.o
	cc obj/main.o obj/node.o obj/graph.o obj/stack.o -o  bin/main

bin/tests: obj/node.o obj/stack.o obj/stack_tests.o obj/common.o
	cc obj/node.o obj/stack.o obj/stack_tests.o obj/common.o -o bin/tests

obj/main.o: main.c
	cc -c main.c -o obj/main.o
	
obj/common.o: tests/common/common.c tests/common/common.h
	cc -c tests/common/common.c -o obj/common.o

obj/stack_tests.o: tests/stack/stack_tests.c tests/stack/stack_tests.h
	cc -c tests/stack/stack_tests.c -o obj/stack_tests.o

obj/stack.o: stack/stack.c stack/stack.h
	cc -c stack/stack.c -o obj/stack.o

obj/node.o: node/node.c node/node.h
	cc -c node/node.c -o obj/node.o

obj/graph.o: graph/graph.c graph/graph.h
	cc -c graph/graph.c -o obj/graph.o

