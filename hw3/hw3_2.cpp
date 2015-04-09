#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int check(string prefix);
void move(int i, float infix[][2]);
void check_sign(int i, float infix[][2]);

int main(void){
	string prefix = "";
	
	while(1){
		do{
			cout << "Input prefix:";
			cin >> prefix;
			
			if(prefix == "-1")
				break;
		}while(check(prefix) == 0);
		
		if(prefix == "-1")
			break;

		float infix[ prefix.length() ][2];
		
		for(int i = 0; i < prefix.length(); i++)
			infix[i][0] = prefix.at(i) - 48;
		for(int i = 0; i < prefix.length(); i++)
			infix[i][1] = 1;

		for(int i = prefix.length() - 1; i >= 0; i--){
			if(infix[i][0] < 0){
				switch((int)infix[i][0]){
					case -5:
						infix[i][0] = ( infix[i + 1][1] * infix[i + 1][0] ) + ( infix[i + 2][1] * infix[i + 2][0] );
						check_sign(i , infix);
						move(i, infix);
						i = i + 2;
						break;
					case -3:
						infix[i][0] = ( infix[i + 1][1] * infix[i + 1][0] ) - ( infix[i + 2][1] * infix[i + 2][0] );
						check_sign(i , infix);
						move(i, infix);
						i = i + 2;
						break;
					case -6:
						infix[i][0] = ( infix[i + 1][1] * infix[i + 1][0] ) * ( infix[i + 2][1] * infix[i + 2][0] );
						check_sign(i , infix);
						move(i, infix);
						i = i + 2;
						break;
					case -1:
						infix[i][0] = ( infix[i + 1][1] * infix[i + 1][0] ) / ( infix[i + 2][1] * infix[i + 2][0] );
						check_sign(i , infix);
						move(i, infix);
						i = i + 2;
						break;
					default:
						break;
				}
			}
		}
		
		cout << infix[ prefix.length() - 1 ][1] * infix[ prefix.length() -1 ][0] << endl;
	}
	
	system("pause");
	return 0;
}

int check(string prefix){
	int count_operator = 0, count_num = 0;
	for(int i = 0; i < prefix.length(); i++){
		if(prefix.at(i) == '+' || prefix.at(i) == '-' || prefix.at(i) == '*' || prefix.at(i) == '/' )
			count_operator++;
		else
			count_num++;
	}
	
	if(count_operator != count_num - 1)
		return 0;
	else
		return 1;
}

void move(int i, float infix[][2]){
	for(; i >= 0; i--){
		infix[i + 2][0] = infix[i][0];
		infix[i + 2][1] = infix[i][1];
	}
	infix[0][0] = 0;
	infix[0][1] = 0;
	infix[1][0] = 0;
	infix[1][1] = 0;
}

void check_sign(int i, float infix[][2]){
	if(infix[i][0] < 0){
		infix[i][1] = -1;
		infix[i][0] = infix[i][0] * -1;
	}
}