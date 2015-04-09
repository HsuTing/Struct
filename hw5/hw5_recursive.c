#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node* nodePointer;
struct node {
	int data;
	nodePointer right;
	nodePointer left;
};

int max = 0;
int max_number = 0;
void max_node(nodePointer head, int number);
void add_node(nodePointer head, int data);
void print_node(nodePointer head, int number);
void delete_node(nodePointer head, int number, int delete_numebr);

int main(void) {
	int number = 0;
	nodePointer head = malloc(sizeof(struct node));
	head->right = NULL;
	head->left = NULL;

	do {
		printf("Input number(enter -1 to end):");
		scanf("%d", &number);
		head->data = number;

		while(1) {
			scanf("%d", &number);
			if(number == -1) {
				break;
			}
			add_node(head, number);
		}

		print_node(head, 0);
		printf("\n");

		while(1) {
			printf("Delete(Enter -1 to end):");
			scanf("%d", &number);
			if(number == -1) {
				break;
			}
			delete_node(head, 0, number);
			print_node(head, 0);
			printf("\n");
		}
		head = malloc(sizeof(struct node));
		printf("Enter -1 to end:");
		scanf("%d", &number);
	}while(number != -1);

	return 0;
}

void max_node(nodePointer head, int number) {
	nodePointer now = malloc(sizeof(struct node));
	now = head;

	if(now->left != NULL) {
		print_node(now->left, number * 2 + 1);
	}
	if(now->right != NULL) {
		print_node(now->right, number * 2 + 2);
	}

	if(now->data > max) {
		max = now->data;
		max_number = number;
	}
}

void add_node(nodePointer head, int data) {
	nodePointer now = malloc(sizeof(struct node));
	now = head;

	while(now->right != NULL || now->left != NULL) {
		if(data > now-> data) 	{
			if(now->right == NULL) {
				break;
			}
			else {
				now = now->right;
			}
		}
		else {
			if(now->left == NULL) {
				break;
			}
			else {
				now = now->left;
			}
		}
	}

	nodePointer temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	if(data > now->data) {
		now->right = temp;
	}
	else {
		now->left = temp;
	}
}

void print_node(nodePointer head, int number) {
	nodePointer now = malloc(sizeof(struct node));
	now = head;

	if(now->left != NULL) {
		print_node(now->left, number * 2 + 1);
	}
	if(now->right != NULL) {
		print_node(now->right, number * 2 + 2);
	}
	printf("index:%d value:%d\n", number, now->data);
}

void delete_node(nodePointer head, int number, int delete_number) {
	nodePointer now = malloc(sizeof(struct node));
	now = head;

	if(now->left != NULL) {
		delete_node(now->left, number * 2 + 1, delete_number);
	}
	if(now->right != NULL) {
		delete_node(now->right, number * 2 + 2, delete_number);
	}

	if(number * 2 + 1 == delete_number) {
		if(now->left->left == NULL && now->left->right == NULL) {
			now->left = NULL;
		}
		else if(now->left->left != NULL && now->left->right == NULL) {
			now->left = now->left->left;
		}
		else if(now->left->left == NULL && now->left->right != NULL) {
			now->left = now->left->right;
		}
		else if(now->left->left != NULL && now->left->right != NULL) {
			max = now->left->left->data;
			max_number = (number * 2 + 1) * 2 + 1;
			max_node(now->left->left, (number * 2 + 1) * 2 + 1);
			now->left->data = max;
			delete_node(head, 0, max_number);
		}
	}
	else if(number * 2 + 2 == delete_number) {
		if(now->right->left == NULL && now->right->right == NULL) {
			now->right = NULL;
		}
		else if(now->right->left != NULL && now->right->right == NULL) {
			now->right = now->right->left;
		}
		else if(now->right->left == NULL && now->right->right != NULL) {
			now->right = now->right->right;
		}
		else if(now->right->left != NULL && now->right->right != NULL) {
			max = now->right->left->data;
			max_number = (number * 2 + 2) * 2 + 1;
			max_node(now->right->left, (number * 2 + 2) * 2 + 1);
			now->right->data = max;
			delete_node(head, 0, max_number);
		}
	}
}
