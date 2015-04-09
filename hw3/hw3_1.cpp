#include <iostream>
#include <cstdlib>

using namespace std;

void push_front(int, int[10], int);
void push_back(int, int[10], int);
void pop_front(int[10], int);

int main(void){
	int dequeue[10];
	int num = 0;
	int control = 0;
	int temp;

	for(int i = 0; i < 10; i++)
		dequeue[i] = 0;

	do{
		do{
			cout << "Input(1) or delete(2):";
			cin >> control;
		}while(control != 1 && control != 2 && control != -1);
		
		switch(control){
			case 1:
				do{
					cout << "Input from left(1) or right (2):";
					cin >> control;
				}while(control != 1 && control != 2);
				
				switch(control){
					case 1:
						if(num == 10){
							cout << "Array is full." << endl;
							continue;
						}
						cout << "Input number:";
						cin >> temp;
						
						num++;
						push_front(temp, dequeue, num);
						cout << "Print array:";
						for(int i = 0; i < num; i++)
							cout << " " << dequeue[i];
						cout << endl;
						break;
					case 2:
						if(num == 10){
							cout << "Array is full." << endl;
							continue;
						}
						cout << "Input number:";
						cin >> temp;
						
						num++;
						push_back(temp, dequeue, num);
						cout << "Print array:";
						for(int i = 0; i < num; i++)
							cout << " " << dequeue[i];
						cout << endl;
						break;
					default:
						break;
				}
				break;
			case 2:
				do{
					cout << "delete from left(1) or right(2):";
					cin >> control;
				}while(control != 1 && control != 2);
					
				switch(control){
					case 1:
						if(num == 0){
							cout << "Array is empty." << endl;
							continue;
						}
						
						num--;
						pop_front(dequeue, num);
						cout << "Print array:";
						for(int i = 0; i < num; i++)
							cout << " " << dequeue[i];
						cout << endl;
						break;
					case 2:
						if(num == 0){
							cout << "Array is empty." << endl;
							continue;
						}
						num--;
						cout << "Print array:";
						for(int i = 0; i < num; i++)
							cout << " " << dequeue[i];
						cout << endl;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		
	}while(control != -1);

	system("pause");
	return 0;
}

void push_front(int temp, int dequeue[10], int num){
	for(int i = num; i > 0; i--){
		dequeue[i] = dequeue[i - 1];
	}
	dequeue[0] = temp;
	return;
}

void push_back(int temp, int dequeue[10], int num){
	dequeue[num - 1] = temp;
	return;
}

void pop_front(int dequeue[10], int num){
	for(int i = 0; i < num; i++){
		dequeue[i] = dequeue[i +1];
	}
	
	return;
}