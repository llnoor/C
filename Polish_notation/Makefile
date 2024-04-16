all: graph

graph: C_dynamic.o graph.o C_notation.o C_graph.o
	gcc graph.o C_dynamic.o C_notation.o C_graph.o -o ../build/graph

C_dynamic.o: C_dynamic.h C_dynamic.c
	gcc -c -Wall -Wextra -Werror C_dynamic.c

C_notation.o: C_notation.h C_notation.c
	gcc -c -Wall -Wextra -Werror C_notation.c
	
C_graph.o: C_graph.h C_graph.c
	gcc -c -Wall -Wextra -Werror C_graph.c

graph.o: graph.c
	gcc -c -Wall -Wextra -Werror graph.c

clean:
	rm -f *.o