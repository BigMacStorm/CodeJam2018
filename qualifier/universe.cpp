#include <iostream>

using namespace std;

int check(string s){
    int sum = 0;
    int current = 1;
    for(int x=0; x<s.size(); x++){
        if(s[x] == 'S'){
            sum += current;
        }
        else{
            current *= 2;
        }
    }
    return sum;
}



void solve(int shield, string s){
    int moves = 0;
    bool flip = true;
    while(true){
        if(check(s) <= shield){
            cout << moves << endl;
            return;
        }
        if(!flip){
            cout << "IMPOSSIBLE" << endl;
            return;
        }else{
            flip = false;
        }

        for(int x=s.size()-1; x>=1; x--){
            if(s[x] == 'S' && s[x-1] == 'C'){
                s[x-1] = 'S';
                s[x] = 'C';
                moves++;
                flip = true;
                break;
            }
        }
    }
}



int main(){
    int cases;
    int shield;
    string command;
    cin >> cases;
    for(int x=0; x<cases; x++){
        cin >> shield;
        cin >> command;
        cout << "Case #" << x+1 << ": ";
        solve(shield, command);
    }
}
