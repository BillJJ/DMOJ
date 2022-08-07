#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM=5e3+5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<char> a(n);
    for(auto &i: a) cin >> i;
    int res=0;
    for(int i = 0;i<n;i++){
        char x;
        cin>>x; res+=(x==a[i]);
    }
    cout<<res;
    return 0;
}