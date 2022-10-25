#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	if (scanf("%d", &n) != 1 && n >= 1) {
		printf("n/a");
	} else {
		int** array = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i < n; ++i) {
			array[i] = (int*)malloc(n * sizeof(int));
		}
		int ceil = 0;
		int floor = n - 1;
		int left = 0;
		int right = n - 1;
		int num = 1;
		while (num <= n*n) {
			for (int j = left; j <= right && num <= n*n; ++j) {
				array[ceil][j] = num * num;
				++num;
			}
			ceil++;
			for (int i = ceil; i <= floor && num <= n*n; ++i) {
				array[i][right] = num * num;
				++num;
			}
			right--;
			for (int j = right; j >= left && num <= n*n; --j) {
				array[floor][j] = num * num;
				++num;
			}
			floor--;
			for (int i = floor; i >= ceil && num <= n*n; --i) {
				array[i][left] = num * num;
				++num;
			}
			left++;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%d ", array[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < n; ++i) {
			free(array[i]);
		}
		free(array);
	}
	return 0;
}