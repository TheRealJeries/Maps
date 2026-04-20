all: bin/main bin/tests

Maps/bin/main: Maps/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o
	cc Maps/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o -o  Maps/bin/main

Maps/bin/tests: Maps/obj/node.o Maps/obj/stack.o Maps/obj/stack_tests.o Maps/obj/common.o
	cc Maps/obj/node.o Maps/obj/stack.o Maps/obj/stack_tests.o Maps/obj/common.o -o Maps/bin/tests

Maps/obj/main.o: Maps/main.c
	cc -c Maps/main.c -o Maps/obj/main.o

Tests/bin/main:	Tests/obj/common.o Tests/obj/stack_tests.o Maps/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o
	cc Maps/obj/main.o Maps/obj/node.o Maps/obj/graph.o Maps/obj/stack.o -o  Maps/bin/main

Tests/obj/common.o: Tests/common/common.c Tests/common/common.h
	cc -c Tests/common/common.c -o Tests/obj/common.o

Tests/obj/stack_tests.o: Tests/stack/stack_tests.c Tests/stack/stack_tests.h
	cc -c Tests/stack/stack_tests.c -o Tests/obj/stack_tests.o

Maps/obj/stack.o: Maps/stack/stack.c Maps/stack/stack.h
	cc -c Maps/stack/stack.c -o Maps/obj/stack.o

Maps/obj/node.o: Maps/node/node.c Maps/node/node.h
	cc -c Maps/node/node.c -o Maps/obj/node.o

Maps/obj/graph.o: Maps/graph/graph.c Maps/graph/graph.h
	cc -c Maps/graph/graph.c -o Maps/obj/graph.o

