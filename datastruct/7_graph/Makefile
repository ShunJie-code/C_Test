CFLAGS = -g -Wall -I../4_stackqueue
CFILES = main.c graph.c dfs_traverse.c bfs_traverse.c mtly.c mcst.c shortestpath.c topologicalsort.c
CFILES += ../4_stackqueue/linkqueue.c
hello: $(CFILES) | Makefile
	gcc $(CFLAGS) -o main $(CFILES)
.PHONY: clean
clean:
	rm -f main *.o