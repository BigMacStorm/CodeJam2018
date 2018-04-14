#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ppii;

bool srtd(vector<int> a, vector<int> b){
	return a[2] < b[2];
}


double solve(){
	int n;
	int goal;
	cin >> n >> goal;
	vector<vector<int> > mem;
	int t, i;
	double min;
	double max;
	double base;
	double difference;
	double ans;
	
	double running = 0;
	double runningm = 0;
	double runningb = 0;
	
	for(int x=0; x<n; x++){
		cin >> t >> i;
		vector<int> temp;
		if(t < i) swap(t, i);
		base = ((t*2) + (i*2));
		max = (base + (2.0 * sqrt( (t*t) + (i*i) ) ));
		min = (base + (2*i));
		difference = max-min;
		running += max;
		runningm += min;
		runningb += base;
		temp.push_back(base);
		temp.push_back(max);
		temp.push_back(min);
		temp.push_back(difference);
		mem.push_back(temp);
	}
	
	if(running <= goal){
		return running;
	}
	if(runningb == goal){
		return runningb;
	}
	if(runningm <= goal && running >= goal){
		return goal;
	}
	sort(mem.begin(), mem.end(), srtd);
	ans = runningb;
	bool flag = true;	
	for(int x=0; x<mem.size(); x++){
		ans += mem[x][1];
		ans -= mem[x][0]
		if(ans + mem[x+1][2] - mem[x+1][0] > goal){
			return ans;
		}
	}
	while(flag){
		for(int x=0; x<mem.size(); x++){
			if(ans - mem[x][0] + mem[x][2] < goal){
				ans -= mem[x][0];
				ans += mem[x][2];
				if(ans - mem[x][2] + mem[x][1] > goal){
					return goal;
				}
				if((ans - mem[x][2] + mem[x][1] + mem[x+1][2] - mem[x+1][0]) > goal){
					return ans - mem[x][2] + mem[x][1];
				}
			}
		}
		return ans;
	}
}


int main(){

	int cases = 0;
	cout.precision(6);
	cin >> cases;
	for(int x=0; x<cases; x++){
		cout << "Case #" << x+1 << ": ";
			cout << fixed << solve() << endl;
	}		

return 0;
}
