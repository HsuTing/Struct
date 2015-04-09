#include <iostream>
#include <cstdlib>

using namespace std;

int check(string infix);
void move(int i, char prefix[], int length);
void clear(int temp_length, char temp[], int length);
int insert_temp(int i, int temp_length, int length, char temp[], char prefix[]);

int main(void){
	string infix = "";

	while(1){
		do{
			cout << "Input infix:";
			cin >> infix;
			
			if(infix == "-1")
				break;
		}while(check(infix) == 0);
		
		if(infix == "-1")
			break;
		
		int length = infix.length();
		int temp_length = 0;
		char prefix[ length ];
		char temp[ length ];
		
		for(int i = 0; i < length; i++)
			prefix[i] = 0;
		for(int i = 0; i < length; i++)
			temp[i] = 0;

		for(int i = length - 1; i >= 0; i--){
			if(infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/' || infix.at(i) == ')'){
				temp[temp_length] = infix.at(i);
				temp_length++;
				move(i, prefix, length);
			}
			else if(infix.at(i) == '('){
				temp_length = insert_temp(i, temp_length, length, temp, prefix);
			}
			else{
				prefix[i] = infix.at(i);
			}
		}
		
		for(int i = 0; i < temp_length; i++)
			cout << temp[i];
		for(int i = 0; i < length; i++)
			cout << prefix[i];
		cout <<endl;
	}

	system("pause");
	return 0;
}

int check(string infix){
	int count_operator = 0, count_num = 0;
	for(int i = 0; i < infix.length(); i++){
		if(infix.at(i) == '+' || infix.at(i) == '-' || infix.at(i) == '*' || infix.at(i) == '/' )
			count_operator++;
		else if(infix.at(i) != '(' && infix.at(i) != ')' )
			count_num++;
	}
	
	if(count_operator != count_num - 1)
		return 0;
	else
		return 1;
}

void move(int i, char prefix[], int length){
	for(; i < length - 1 ; i++){
		prefix[i] = prefix[i + 1];
	}
	prefix[ length - 1 ] = 0;
}

void push(int i, char prefix[], int length){
	for(int j = length - 1; j > i; j--){
		prefix[j] = prefix[j - 1];
	}
	prefix[i] = 0;
}

void clear(int temp_length, char temp[], int length){
	temp[temp_length - 1] = 0;
	for(int i = length - 1; i >= temp_length; i--){
		temp[i] = temp[i - 1];
	}
}

int insert_temp(int i, int temp_length, int length, char temp[], char prefix[]){
	prefix[i] = temp[temp_length - 1];
	clear(temp_length, temp, length);
	temp_length--;
	while(temp[temp_length - 1] != ')'){
		push(i, prefix, length);
		clear(temp_length, temp, length);
		temp_length--;
		prefix[i] = temp[temp_length - 1];
	}
	temp[temp_length - 1]  =0;
	
	return temp_length - 1;
}