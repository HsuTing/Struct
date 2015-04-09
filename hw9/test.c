#include <stdlib.h>
#include <stdio.h>
#define MAX_VERTICES 10

typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
};

typedef struct {
	int count;
	nodePointer link;
} hdnodes;
hdnodes graph[MAX_VERTICES];

void topSort(hdnodes graph[], int m);

int main(void) {
	
}

void topSort(hdnodes graph[], int n) {
	int i, j, k, top;
	nodePointer ptr;
	top = -1;
	for(i = 0; i < n; i++) {
		if(!graph[i].count) {
			graph[i].count = top;
			top = i;
		}
	}

	for(i = 0; i < n; i++) {
		if(top == -1) {
			fprintf(stderr, "\nNetwork has a cycle. Sort terminated.\n");
			return;
		}
		else {
			j = top;
			top = graph[top].count;
			printf("v%d, ", j);
			for(ptr = graph[j].link; ptr; ptr = ptr->link) {
				k = ptr->vertex;
				graph[k].count--;
				if(!graph[k].count) {
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}
