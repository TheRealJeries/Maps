all: bin/main

bin/main: obj/main.o obj/node.o obj/graph.o
	cc obj/main.o obj/node.o obj/graph.o -o  bin/main

obj/main.o: main.c
	cc -c main.c -o obj/main.o

obj/node.o: node/node.c node/node.h
	cc -c node/node.c -o obj/node.o

obj/graph.o: graph/graph.c graph/graph.h
	cc -c graph/graph.c -o obj/graph.o

