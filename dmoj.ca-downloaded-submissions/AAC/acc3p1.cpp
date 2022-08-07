#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e6+5;
int freq[MM], a[MM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    ll total = 0; int distinct = 0;

    int l = 0, r = 0;
    while(r < n){
        freq[a[r]]++;
        if(freq[a[r]] == 1) distinct++;

        while(l <= r && distinct >= k){
            total += n - r;

            freq[a[l]]--;
            if(freq[a[l]] == 0) distinct--;
            l++;
        }
        r++;
    }

    cout << total << '\n';

    return 0;
}