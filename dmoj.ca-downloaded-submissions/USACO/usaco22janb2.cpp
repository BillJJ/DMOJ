#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

int a[4], b[4], c[4];

bool check(int x[4], int y[4]){ // return if x beats y
    int w=0,l=0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(x[i] > y[j]) w++;
            else if(x[i] < y[j]) l++;
        }
    }
    return w > l;
}

void solve(){
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    for(int i = 1; i <= 10; i++){
        c[0] = i;
        for(int j = 1; j <= 10; j++){
            c[1] = j;
            for(int k = 1; k <= 10; k++){
                c[2] = k;
                for(int l = 1; l <= 10; l++){
                    c[3] = l;

                    if(check(a, b) && check(c, a) && check(b, c)){
                        cout << "yes\n";
                        return;
                    } else if(check(b, a) && check(c, b) && check(a, c)){
                                                cout << "yes\n";
                        return;
                    }

                }
            }
        }
    }
    cout << "no\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}