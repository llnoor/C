all: graph

graph: dynamic.o graph.o notation.o graph.o
	gcc graph.o dynamic.o notation.o graph.o -o ../build/graph

dynamic.o: dynamic.h dynamic.c
	gcc -c -Wall -Wextra -Werror dynamic.c

notation.o: notation.h notation.c
	gcc -c -Wall -Wextra -Werror notation.c
	
graph.o: graph.h graph.c
	gcc -c -Wall -Wextra -Werror graph.c

graph.o: graph.c
	gcc -c -Wall -Wextra -Werror graph.c

clean:
	rm -f *.o
