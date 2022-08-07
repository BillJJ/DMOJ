#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=1e5+5, MV = 1e6 + 5;
int a[MM], p[MV];

int freq[MV];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for(int i = 1; i < MV; i++){
        if(!freq[i]) continue;

        for(int j = i; j < MV; j += i){
            p[j]+= freq[i];
        }
    }

    for(int i = 1; i <= n; i++){
        cout << max(p[a[i]]-1, 0) <<"\n";
    }

    return 0;
}