#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int b[MM];
unordered_map<int, int> freq;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n*n; i++){
        cin >> b[i];
        freq[b[i]]++;
    }
    vector<int> a;
    for(auto[k, v]: freq){
        if(v & 1) a.push_back(k/2);
    }

    sort(a.begin(), a.end());
    for(int i =0; i < n; i++){
        cout << a[i] << " \n"[i == n-1];
    }

    return 0;
}