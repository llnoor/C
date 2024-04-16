all: graph

graph: s21_dynamic.o graph.o s21_notation.o s21_graph.o
	gcc graph.o s21_dynamic.o s21_notation.o s21_graph.o -o ../build/graph

s21_dynamic.o: s21_dynamic.h s21_dynamic.c
	gcc -c -Wall -Wextra -Werror s21_dynamic.c

s21_notation.o: s21_notation.h s21_notation.c
	gcc -c -Wall -Wextra -Werror s21_notation.c
	
s21_graph.o: s21_graph.h s21_graph.c
	gcc -c -Wall -Wextra -Werror s21_graph.c

graph.o: graph.c
	gcc -c -Wall -Wextra -Werror graph.c

clean:
	rm -f *.o