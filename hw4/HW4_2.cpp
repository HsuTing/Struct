#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node* nodoPointer;
typedef struct node{
    int data;
    nodoPointer next;
};
 
nodoPointer XOR (nodoPointer a, nodoPointer b);
void insert(nodoPointer* tail, int data);
nodoPointer find(nodoPointer tail);
void printList (nodoPointer head);
void right_to_left(nodoPointer tail);
void left_to_right(nodoPointer head);
 
int main(void){
	int num = 0;
    nodoPointer head = NULL;
	nodoPointer tail = NULL;
	
	do{
		cout << "input(input -1 to leave):";
		cin >> num;
			
		if(num == -1)
			break;
		insert(&tail, num);
	}while(num != -1);

	cout << "output" << endl;
	head = find(tail);
	printList (head);
	cout << "left to right" << endl;
	left_to_right(head);
	cout << "right to left" << endl;
	right_to_left(tail);
 
	system("pause");
    return (0);
}

nodoPointer XOR (nodoPointer a, nodoPointer b){
    return (nodoPointer) ((unsigned int) (a) ^ (unsigned int) (b));
}

void insert(nodoPointer* tail, int data){
    nodoPointer temp  = (nodoPointer)malloc(sizeof (node) );
    temp->data = data;
    temp->next = XOR(*tail, NULL);
 
    if (*tail != NULL){
        nodoPointer tempnode = XOR((*tail)->next,  NULL);
        (*tail)->next = XOR(temp, tempnode);
    }
 
    *tail = temp;
}

nodoPointer find(nodoPointer tail){
	nodoPointer now = tail;
    nodoPointer prev = NULL;
    nodoPointer tempnode;
 
    while (now != NULL){
        tempnode = XOR (prev, now->next);
        prev = now;
        now = tempnode;
    }
	
	return prev;
}

void printList (nodoPointer head){
    nodoPointer now = head;
    nodoPointer prev = NULL;
    nodoPointer tempnode;
 
    while (now != NULL){
        cout << "data=" << now->data << "address=" << now << endl;
        tempnode = XOR (now->next, prev);
        prev = now;
        now = tempnode;
    }
}

void right_to_left(nodoPointer tail){
    nodoPointer now = tail;
    nodoPointer prev = NULL;
    nodoPointer tempnode;
 
    while (now != NULL){
        cout << "data=" << now->data << "link=" <<  XOR (prev, now->next) << endl;
        tempnode = XOR (prev, now->next);
        prev = now;
        now = tempnode;
    }
}

void left_to_right(nodoPointer head){
    nodoPointer now = head;
    nodoPointer prev = NULL;
    nodoPointer tempnode;
 
    while (now != NULL){
        cout << "data=" << now->data << "link=" << XOR (now->next, prev) << endl;
        tempnode = XOR (now->next, prev);
        prev = now;
        now = tempnode;
    }
}