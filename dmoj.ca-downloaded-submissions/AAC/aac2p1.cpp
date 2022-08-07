#include <bits/stdc++.h>
using namespace std;

int letter[27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    for(char c : s){
        letter[int(c) - 97]++;
    }

    int total = 0;

    for(int i : letter){
        if(i & 1) total++;
    }

    if(total == 0){
        cout << 1;
        return 0;
    }

    cout << total;
    return 0;
}