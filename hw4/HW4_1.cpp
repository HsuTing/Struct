#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct matrixNode *matrixPointer;
typedef struct matrixNode {
	int row;
	int col;
	int value;
	matrixPointer next;
};

void creat_head(matrixPointer head, int num);
matrixPointer insert_node(matrixPointer temp, int i, int j, int value);
void transpose(matrixPointer head);
void print_matrix(matrixPointer head);
int search(matrixPointer head, int i,int j);

int main(void){
	int num = 0, count = 0, value = 0;;

    do{
	   cout << "input matrix size (n*n):" ;
	   cin >> num;
   }while(num <= 0);
	
	matrixPointer head = (matrixPointer)malloc(sizeof(matrixNode));
	creat_head(head, num);
	matrixPointer temp = (matrixPointer)malloc(sizeof(matrixNode));
	head->next = temp;

	cout << "input element:" << endl;
	for(int i = 0; i < num; i++)
		for(int j = 0; j < num; j++){
			cin >> value;
			if(value != 0){
				count++;
				temp = insert_node(temp, i, j, value);
		}
	}
	head->value = count;
	cout << endl;
	cout << "Before transpose" << endl;
	print_matrix(head);
    transpose(head);
    cout << "After transpose" << endl;
    print_matrix(head);

	system("pause");
	return 0;
}

void creat_head(matrixPointer head, int num){
	head->row = num;
	head->col = num;
	head->next = NULL;
}

matrixPointer insert_node(matrixPointer temp, int i, int j, int value){
	matrixPointer node = (matrixPointer)malloc(sizeof(matrixNode));
	temp->row = i;
	temp->col = j;
	temp->value = value;
	node->next = NULL;
	temp->next = node;
	return node;
}

void transpose(matrixPointer head) {
    matrixPointer now = head;
	while(now->next != NULL){
		int temp = now->row;
		now->row = now->col;
		now->col = temp;
		now = now->next;
	}
}

void print_matrix(matrixPointer head) {
    for(int i = 0; i < head->row; i++) {
       for(int j = 0; j < head->col; j++){
          cout << search(head, i, j) << " ";
       }
       cout << endl;
    }
}

int search(matrixPointer head, int i, int j) {
    matrixPointer now = head->next;
    while(now->next != NULL){
        if((now->row == i) && (now->col == j))
             return now->value;
        now = now->next;
    }
    return 0;
}
