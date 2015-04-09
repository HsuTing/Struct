#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_num(void);
void input(int num, int map[num][num]);
void output(int num, int graph[num][num]);
void original(int num, int map[num][num], int graph[num][num]);
void foreset(int num, int tree[num], int graph[num][num]);
int count_edge(int num, int graph[num][num]);
void final(int num, int tree[num], int map[num][num], int graph[num][num]);

int main(void) {
	int i = 0, j = 0, num = count_num();
	int map[num][num], graph[num][num], tree[num];
	memset(map, 0, sizeof(map));
	memset(graph, 0, sizeof(graph));
	memset(tree, 0, sizeof(tree));

	input(num, map);
	original(num, map, graph);
	foreset(num, tree, graph);
	final(num, tree, map, graph);
	output(num, graph);

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

void input(int num, int map[num][num]) {
	FILE* fp = fopen("input.txt", "r");
	int i = 0, j = 0;

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			fscanf(fp, "%d", &map[i][j]);
		}
	}

	fclose(fp);
}

void output(int num, int graph[num][num]) {
	FILE* fp = fopen("output.txt", "w");
	int i =0, j = 0;

	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			fprintf(fp, "%d ", graph[i][j]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}

void original(int num, int map[num][num], int graph[num][num]) {
	int i = 0, j = 0;
	for(i = 0; i < num; i++) {
		int min = -1;
		for(j = 0; j < num; j++) {
			if(min == -1 && map[i][j] != -1) {
				min = map[i][j];
			}

			if(map[i][j] < min && map[i][j] != -1) {
				min = map[i][j];
			} 
		}

		for(j = 0; j < num; j++) {
			if(map[i][j] == min) {
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}
}

void foreset(int num, int tree[num], int graph[num][num]) {
	int i = 0, j = 0, temp = num;
	for(i = 0; i < num; i++) {
		for( j = 0; j < num; j++) {
			if(graph[i][j] == 1) {
				if(tree[i] == 0 && tree[j] == 0) {
					tree[i] = temp + 1;
					temp = temp + 1;
					tree[j] = tree[i];
				}
				else if(tree[i] == 0 && tree[j] != 0) {
					tree[i] = tree[j];
				}
				else if(tree[i] != 0 && tree[j] == 0) {
					tree[j] = tree[i];
				}
			}
		}
	}
}

int count_edge(int num, int graph[num][num]) {
	int i = 0, j = 0, count = 0;
	for(i = 0; i < num; i++) {
		for(j = 0; j < num; j++) {
			count = count + graph[i][j];
		}
	}

	return count / 2;
}

void final(int num, int tree[num], int map[num][num], int graph[num][num]) {
	int i = 0, j = 0, edge = 0;
	if((edge = count_edge(num, graph)) == num - 1) {
		return;
	}

	int temp = num + 1;
	while(1) {
		int min = -1, min_i = -1, min_j = -1;
		for(i = 0; i < num; i++) {
			if(tree[i] == temp) {
				for(j = 0; j < num; j++) {
					if(map[i][j] != -1 && graph[i][j] == 0 &&  min == -1) {
						min = map[i][j];
						min_i = i;
						min_j = j;
					}

					if(map[i][j] != -1 && graph[i][j] == 0 && map[i][j] < min) {
						min = map[i][j];
						min_i = i;
						min_j = j;
					}
				}
			}
		}

		if(min_i != -1 && min_j != -1) {
			graph[min_i][min_j] = 1;
			graph[min_j][min_i] = 1;
		}

		for(i = 0; i < num; i++) {
			if(tree[i] == temp) {
				tree[i] = tree[min_j];
			}
		}

		edge = edge + 1;
		if(edge == num - 1) {
			break;
		}
		temp = temp + 1;
	}
}
