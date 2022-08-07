#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<int> a;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 0, x; i < n; i++) {
        cin >> x; a.push_back(x);
    }

    int res = 0;
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < a.size(); i++){
        while(!a.empty() && i+1 > a.back()) a.pop_back();
        res = i+1;
    }

    cout << res;

    return 0;
}