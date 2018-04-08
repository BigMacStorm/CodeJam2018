#include <iostream>
#include <vector>

using namespace std;

bool leftsolved(int d[][100], int x, int y){
		
	return ((d[x-1][y-1] == 1) && (d[x][y-1] == 1) && (d[x+1][y-1] == 1));
}

bool fullsolved(int d[][100], int x, int y){
	return (leftsolved(d, x, y) && leftsolved(d, x, y+1) && leftsolved(d, x, y+2));
}

bool solve(){
	int size;
	int i, j;
	int count = 0;
	
	int d[100][100];
	for(int x=0; x<100; x++){
		for(int y=0; y<100; y++){
			d[x][y] = 0;
		}
	}
	
	cin >> size;
	int w, h;
	if(size == 20){
		w=4;
		h=5;
	}else if(size == 10){
		w=4;
		h=3;
	}else{
		w=20;
		h=10;
	}
	
	int tlx=10;
	int tly=10;
	
	int x=1;
	int y=1;
	
	while(x<w-1){
		while(y<h-1){
			cout << x+tlx << " " << y+tly << endl;
			cin >> i >> j;
			count++;
			if(count > 1010) return true;
			if(i == j && j==0){
				return false;
			}
			if(i == -1 || j ==-1){
				return true;
			}
			d[i][j] = 1;
			
			if(y != h-2){
				if(leftsolved(d, x+tlx, y+tly)){
					y++;	
				}				
			}
			else{
				if(fullsolved(d, x+tlx, y+tly)){
					y=1;
					x++;
				}
			}		
		}	
	}
}


int main(){
	int cases;
	cin >> cases;
	for(int x=0; x<cases; x++){
		if(solve()){
			return 1;
		}
	}
	return 0;
}
