#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < 2*n; i++){
        int a; cin >> a; v.push_back({a, i+1});
    }

    sort(v.begin(), v.end());

    int total = 0;

    for(int i = 0; i < n; i++){
        if(v[i].first != v[i+n].first) total++;
    }

    cout << total << '\n';
    for(int i = 0; i < n; i++){
        cout << v[i].second << ' ' << v[i+n].second << '\n';
    }

    return 0;
}