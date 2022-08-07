#include <bits/stdc++.h>
using namespace std;

int a[4005];
unordered_set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;


    for(int i = 0; i < n; i++){
        cin >> a[i]; s.insert(a[i]);
    }

    if(n <= 2) {
        if(n == 1){
            cout << 1;
            return 0;
        }
        if(abs(a[0] - a[1]) & 1){
            cout << 1;
            return 0;
        }
        cout << 2;
        return 0;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)continue;
            int diff = (a[i] - a[j]);
            if(diff & 1) continue;

            if(s.find((a[i] + a[j]) / 2) != s.end()){
                cout << 3; return 0;
            }
        }
    }

    if(n >= 3){
        cout << 2; return 0;
    }

    return 0;
}