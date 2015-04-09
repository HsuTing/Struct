#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int count_num(void);
void input(int num, int cost[num][num], int distance[num][num]);
void all_cost(int num, int distance[num][num], int record[num][num][2]);
void output(int num, int distance[num][num], int record[num][num][2]);
void find(int num, int record[num][num][2], int i, int j);

int main (void) {
	int i = 0, j = 0, num = count_num();
	int cost[num][num], distance[num][num], record[num][num][2];
	memset(cost, 0, sizeof(cost));
	memset(distance, 0, sizeof(distance));
	memset(record, 0, sizeof(record));

	printf("input:\n");
	input(num, cost, distance);
	printf("\noutput:\n");
	all_cost(num, distance, record);
	output(num, distance, record);

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

void input(int num, int cost[num][num], int distance[num][num]) {
	FILE* fp = fopen("input.txt", "r");
	int i = 0, j = 0;

	printf("Input node number:%d\n", num);
	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			fscanf(fp, "%d", &cost[i][j]);
			if(cost[i][j] == INT_MAX) {
				printf("Input matrix[%d][%d]:%s\n", i, j, "max");
				continue;
			}
			printf("Input matrix[%d][%d]:%d\n", i, j, cost[i][j]);
		}
	}

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			distance[i][j] = cost[i][j];
		}
	}

	fclose(fp);
}

void all_cost(int num, int distance[num][num], int record[num][num][2]) {
	int i = 0, j = 0, k = 0;

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			for(k = 0; k < num; k++) {
				if(distance[i][k] + distance[k][j] < distance[i][j] && distance[i][k] != INT_MAX && distance[k][j] != INT_MAX) {
					distance[i][j] = distance[i][k] + distance[k][j];
					record[i][j][0] = 1;
					record[i][j][1] = k;
				}
			}
		}
	}

	for(i = num - 1; i >= 0; i--) {
		for(j = num - 1; j >= 0; j--) {
 			for(k = num - 1; k >= 0; k--) {
				if(distance[i][k] + distance[k][j] < distance[i][j] && distance[i][k] != INT_MAX && distance[k][j] != INT_MAX) {
					distance[i][j] = distance[i][k] + distance[k][j];
					record[i][j][0] = 1;
					record[i][j][1] = k;
				}
			}
		}
	}
}

void output(int num, int distance[num][num], int record[num][num][2]) {
	int i = 0, j = 0;

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			if(i == j) {
				continue;
			}
			if(record[i][j][0] == 0) {
				if(distance[i][j] == INT_MAX) {
					continue;
				}
				printf("The shortest path from %d to %d:%d->%d\n", i, j, i, j);
				printf("The cost from %d to %d:%d\n\n", i, j, distance[i][j]);
			}
			else {
				printf("The shortest path from %d to %d:%d", i, j, i);
				find(num, record, i ,j);
				printf("->%d\nThe cost from %d to %d:%d\n\n", j, i, j, distance[i][j]);
			}
		}
	}
}

void find(int num, int record[num][num][2], int i, int j) {
	if(record[i][j][0] == 1) {
		if(record[i][ record[i][j][1] ][0] == 1) {
			find(num, record, i, record[i][j][1]);
		}
		printf("->%d", record[i][j][1]);

		if(record[ record[i][j][1] ][j][0] == 1) {
			find(num, record, record[i][j][1], j);
		}
	}
}
