#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* str = (char*)malloc(sizeof(char));
	char c;
	int size = 1;
	while (scanf("%c", &c) && c != '\n') {
		str[size-1] = c;
		size++;
		str = (char*)realloc(str, size * sizeof(char));
	}
	str[size-1] = '\0';
	char* substr = (char*)malloc(sizeof(char));
	int sizesub = 1;
	while (scanf("%c", &c) && c != '\n') {
		substr[sizesub-1] = c;
		sizesub++;
		substr = (char*)realloc(substr, sizesub * sizeof(char));
	}
	char * p = substr;
	substr[sizesub-1] = '\0';
	char * ptr;
	char*  start = str;
	int flag = 1;
	while (flag) {
		ptr = strstr(start, substr);
		if (ptr != NULL) {
			start = ptr + 1;
		} else {
			flag = 0;
		}
	}
	start--;
	for (ptr = str; ptr < str+strlen(str); ptr++) {
		if (!(ptr >= start && ptr < start + strlen(substr))) {
			printf("%c", *ptr);
		}
	}
	free(str);
	free(substr);
	return 0;
}