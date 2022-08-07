#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 2e5+5;

string name[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

string year[5000];
map<string, int> pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for(int i = 0; i < 5000; i++){
        year[i] = name[i%12];
    }

    int n; cin >> n;
    string input[8]; for(auto & i : input) cin >> i;
    pos["Bessie"] = 2400;
    // Bessie starts at place 2400
    if(input[3] == "previous"){
        for(int i = 2400-1; i > 0; i--){
            if(year[i] == input[4]){
                pos[input[0]] = i;
                break;
            }
        }
    } else{
        for(int i = 2400+1; i < 2599; i++){
            if(year[i] == input[4]){
                pos[input[0]] = i;
                break;
            }
        }
    }

    while(--n){
        for(int i = 0; i < 8; i++) cin >> input[i];
        if(input[3] == "previous"){
            for(int i = pos[input[7]]-1; i > 0; i--){
                if(year[i] == input[4]){
                    pos[input[0]] = i;
                    break;
                }
            }
        } else{
            for(int i = pos[input[7]]+1; i < 5000; i++){
                if(year[i] == input[4]){
                    pos[input[0]] = i;
                    break;
                }
            }
        }
    }

    cout << abs(2400-pos["Elsie"]);

    return 0;
}