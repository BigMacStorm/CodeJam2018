#include <iostream>
#include <vector>
using namespace std;

vector<int> gettop(vector<string> mem){
	vector<int> temp;
	int sum = 0;
	for(int x=0; x<mem[0].size(); x++){
		sum = 0;
		for(int y=0; y<mem.size(); y++){
			if(mem[y][x] == '@'){
				sum++;
			}
		}
		temp.push_back(sum);
	}
	return temp;
}

vector<int> getside(vector<string> mem){
	vector<int> temp;
	int sum = 0;
	for(int x=0; x<mem.size(); x++){
		sum = 0;
		for(int y=0; y<mem[0].size(); y++){
			if(mem[x][y] == '@'){
				sum++;
			}
		}
		temp.push_back(sum);
	}
	return temp;
}

bool split(vector<int> mem, int sent){
	int sum = 0;
	int count = 0;
	for(int x=0; x<mem.size(); x++){
		sum += mem[x];
	}
	if((sum % (sent+1)) != 0)
}

bool solve(){
	vector<string> mem;
	int R, C, H, V;
	string temp;
	cin >> R >> C >> H >> V;
	for(int x=0; x<R; x++){
		cin >> temp;
		mem.push_back(temp);
	}
	vector<int> top = gettop(mem);
	vector<int> side = getside(mem);
	cout << "side: " << endl;
	for(int x=0; x<side.size(); x++){
		cout << side[x] << " ";
	}
	cout << endl;
	
	return (split(top, V) && split(side, H));
}

int main(){

	int cases = 0;
	cin >> cases;
	for(int x=0; x<cases; x++){
		cout << "Case #" << x+1 << ": ";
		if(solve()){
			cout << "POSSIBLE" << endl;
		}else{
			cout << "IMPOSSIBLE" << endl;
		}
	}

		

return 0;
}
