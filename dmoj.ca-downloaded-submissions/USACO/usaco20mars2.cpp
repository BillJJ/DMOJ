#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5+5;

pii a[MM];
int cow[MM]; // which cow currently has this cereal
int ans[MM];
int res = 0;

void kick(int i){ // doesn't get first preference anymore
    res--;
    if(cow[a[i].second] > i){
        res++;
        kick(cow[a[i].second]);
        cow[a[i].second] = i;
    } else if(cow[a[i].second] == 0){
        cow[a[i].second] = i;
        res++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }

    for(int i = n; i >= 1; i--){
        res++;
        if(cow[a[i].first]){
            kick(cow[a[i].first]);
        }
        cow[a[i].first] = i;
        ans[i] = res;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}