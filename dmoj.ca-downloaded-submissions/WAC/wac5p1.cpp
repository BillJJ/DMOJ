#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MM = 1e3+5;
const int MV = 1e6+5;
int freq[MV];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, max_val = 0; cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x; freq[x]++;
        max_val = max(max_val, x);
    }

    ll total = 0;
    for(int i = max_val; i > 0; i--){
        if(freq[i] == 0) continue;

        for(int j = i-1; j > 0; j--){
            if(freq[j] == 0) continue;

            freq[j] -= min(freq[i], freq[j]);
        }
        total += freq[i] * i;
    }
    cout << total << '\n';
    return 0;
}