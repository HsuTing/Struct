#include <stdio.h>
#include <stdlib.h>

void move(int element, char from, char buffer, char to);

int main(void){
	int num = 0;

	do{
		printf("Please enter the number of disk[1-16]:");
		scanf("%d", &num);
	
		if((num < 1) || (num > 16))
			continue;
		move(num, 'A', 'B', 'C');
	}while(num != -1);
	
	system("pause");
	return 0;
}

void move(int element, char from, char buffer, char to){
	if(element == 1)
		printf("disk is moved from %c to %c\n", from, to);
	else{
		move(element-1, from, to , buffer);
		printf("disk is moved from %c to %c\n", from, to);
		move(element-1, buffer, from, to);
	}
}