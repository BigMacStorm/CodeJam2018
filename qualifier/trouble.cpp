#include <iostream>
#include <vector>

using namespace std;

void solve(int run, vector<int> v){
	int temp;
	bool flip = true;
	while(flip){
		flip = false;
		for(int x=0; x<v.size()-2; x++){
			if(v[x] > v[x+2]){
				temp = v[x];
				v[x] = v[x+2];
				v[x+2] = temp;
				flip = true;
			}
		}
	}
	
	/*
	cout << "vector after sort: " << endl;
	for(int x=0; x<v.size(); x++){
		cout << v[x] << " ";
	}
	cout << endl;
	*/
	
	for(int x=0; x<v.size()-1; x++){
		if(v[x] > v[x+1]){
			cout << "Case #" << run+1 << ": " << x << endl;
			return;
		}
	}
	cout << "Case #" << run+1 << ": OK" << endl;
}

int main(){
	int cases;
	int count;
	int temp;
	cin >> cases;
	for(int x=0; x<cases; x++){
		cin >> count;
		vector<int> v (count);
		for(int y=0; y<count; y++){
			cin >> v[y];		
		}
		solve(x, v);	
	}	
	
	return 0;
}
