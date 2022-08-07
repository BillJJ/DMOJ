#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;

ll a[MM], psa[MM], ssa[MM];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 1;i <=n ;i++) cin >> a[i];
    for(int i = 1; i <= n; i++)psa[i] = psa[i-1] + a[i];
    for(int i = n; i >= 1; i--)ssa[i] = ssa[i+1] + a[i];
    
    int l = 1, r = n, res = 0;
    while(l < r){
        if(psa[l] == ssa[r]) {l++, r--;}
        else if(psa[l] < ssa[r]){
            l++, res++;
        } else{
            r--, res++;
        }
    }
    cout << res;
    return 0;
}