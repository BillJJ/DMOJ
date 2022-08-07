#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 1e5+5;

int a[MM];
int freq[(int)1e6+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    ll total = 0;
    int distinct = 0;
    for(int l = 0, r = 0; r < n; r++){
        if(++freq[a[r]] == 1) distinct++;
        while(distinct >= k){
            total += n - r;
            if(--freq[a[l++]] == 0) distinct--;
        }
    }

    cout << total;

    return 0;
}