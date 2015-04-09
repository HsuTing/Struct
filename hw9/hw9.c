#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_num(void);
void input(int num, int cost[num][num]);

int main (void) {
	int i = 0, j = 0, num = count_num();
	int cost[num][num];
	memset(cost, 0, sizeof(cost));

	printf("input:\n");
	input(num, cost);
	printf("\noutput:\n");

	return 0;
}

int count_num(void) {
	FILE* fp = fopen("input.txt", "r");
	int count = 0;
	char ch;

	while((ch = fgetc(fp)) != '\n') {
		if(ch == ' ') {
			count = count + 1;
		}		
	}

	fclose(fp);
	return count + 1;
}

void input(int num, int cost[num][num]) {
	FILE* fp = fopen("input.txt", "r");
	int i = 0, j = 0, temp;

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			fscanf(fp, "%d", &cost[i][j]);
			printf("%2d ", cost[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
}
