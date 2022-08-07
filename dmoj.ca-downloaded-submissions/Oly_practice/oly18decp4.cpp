#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+5;

vector<int> a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    ll total = 0;
    for(int l=0, r = n-1; l < r;){
        if(a[r] + a[l] > m){
            r--;
        } else{
            total += r-l;
            l++;
        }
    }
    cout << total;
    return 0;
}