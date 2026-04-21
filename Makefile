all: Maps/bin/main Tests/bin/main

Maps/bin/main: Maps/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o
	cc -v Maps/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o -o  Maps/bin/main

Maps/obj/main.o: Maps/main.c
	cc -v -c Maps/main.c -o Maps/obj/main.o


Tests/bin/main:	Tests/obj/common.o Tests/obj/stack_tests.o Tests/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o
	cc -v Tests/obj/main.o Tests/obj/stack_tests.o Tests/obj/common.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o -o  Tests/bin/main

Tests/obj/main.o: Tests/main.c
	cc -v -c Tests/main.c -o Tests/obj/main.o

Tests/obj/common.o: Tests/common/common.c Tests/common/common.h
	cc -v -c Tests/common/common.c -o Tests/obj/common.o

Tests/obj/stack_tests.o: Tests/stack_tests/stack_tests.c Tests/stack_tests/stack_tests.h
	cc -v -c Tests/stack_tests/stack_tests.c -o Tests/obj/stack_tests.o

Maps/obj/stack.o: Maps/stack/stack.c Maps/stack/stack.h
	cc -v -c Maps/stack/stack.c -o Maps/obj/stack.o

Maps/obj/node.o: Maps/node/node.c Maps/node/node.h
	cc -v -c Maps/node/node.c -o Maps/obj/node.o

Maps/obj/graph.o: Maps/graph/graph.c Maps/graph/graph.h
	cc -v -c Maps/graph/graph.c -o Maps/obj/graph.o

