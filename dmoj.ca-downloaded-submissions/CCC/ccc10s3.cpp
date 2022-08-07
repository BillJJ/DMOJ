#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e3+5, MV=1e6;

int a[MM*2], n, k;

int check(int len){
    int res = INT_MAX;
    for(int start = 1; start <= n; start++){
        int cnt = 1;
        int reach = len*2+a[start];
        for(int i = start+1; i <= n+start-1; i++){
            if(a[i] > reach){
                cnt++;
                reach = a[i]+len*2;
            }
        }
        res = min(res, cnt);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n ;i ++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1;i <= n; i++){
        a[i+n] = a[i]+1e6;
    }
    cin >> k;

    int l=0,r=1e6;
    while(l < r){
        int mid = (r-l)/2+l;
        if(check(mid) <= k) r= mid;
        else l=mid+1;
    }
    cout << (l+r)/2;
    return 0;
}