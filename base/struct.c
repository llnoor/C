#include <stdio.h>
#include <stdlib.h>

struct student{
	int score;
	char surname[20];
};

int main(){
	int n;
	if (scanf("%d", &n) != 1 || n < 1) {
		printf("n/a");
	} else {
		struct student * list = (struct student*)malloc(n * sizeof(struct student));
		int ball = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &list[i].score);
			scanf("%s", list[i].surname);
			ball += list[i].score;
		}
		int middle = ball / n;
		for (int i = 0;  i < n; ++i) {
			if (list[i].score >= middle) {
				printf("%s", list[i].surname);
			}
			if (i < n -1 ) {
				printf("\n");
			}
		}
		free(list);
	}
	return 0; 
}