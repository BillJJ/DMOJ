#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    string s; int k; cin >> s >> k;

    string least = s.substr(0, k);

    for(int i = 1; i+k < s.size(); i++){
        string t = s.substr(i, k);
        if(t < least){
            least = t;
        }
    }

    cout << least;
    return 0;
}