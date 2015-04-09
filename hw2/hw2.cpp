#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void){
	int m,n,x,y, move;
	srand(time(NULL));

	do{
		cout << "input n:";
		cin >> n;
	}while(n < 3 || n >40 );
	
	do{
		cout << "input m:";
		cin >> m;
	}while( m < 3 || m > 20);
	
	do{
		cout << "Input initial bug position X:";
		cin >> x;
	}while( x < 0 || x > n);
	
	do{
		cout << "Input initial bug position Y:";
		cin >> y;
	}while( y < 0 || y > m);
	
	int map [n][m];
	int imove[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
	int jmove[8] = { 1, 1, 1, 0, -1, -1, -1, 0};
	
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j++)
			map[i][j] = 0;
			
	for(move = 1; move <= 50000; move++){
		int k = ( rand()% 7 ) + 0;
		int count = 0;
		
		if(x + imove[k] < 0)
			continue;
		if(x + imove[k] > n)
			continue;
		if(y + jmove[k] < 0)
			continue;
		if(y + jmove[k] > m)
			continue;
		x = x + imove[k];
		y = y + jmove[k] ;
		map[x][y] = map[x][y] + 1;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(map[i][j] > 0)
					count++;
			}
		}
		
		if(count  == n * m)
			break;
	}
	
	cout << "total:" << move << endl;
	for(int i =0; i < n; i++){
		for(int j =0; j< m; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}