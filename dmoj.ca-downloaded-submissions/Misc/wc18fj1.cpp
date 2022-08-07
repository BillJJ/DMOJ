#include <bits/stdc++.h>
using namespace std;

map<int, int> freq;

int main() {
    int n; cin >> n;
    
    for(int i = 0, x; i < n; i++){
        cin >> x; freq[x]++;
    }

    int best = 0, second = 0;
    freq[0] = 0;
    for(auto[k, v] : freq){
        if(v > freq[best]){
            second = best;
            best = k;
        } else if(v > freq[second]){
            second = k;
        }
    }

    cout << (freq[best]+freq[second]);
}