#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 5e5+5;

struct trip{
    int a, b, c;
};
trip a[MM];

int bit[MM];

void add(int i, int v){
    for(; i<= MM; i+=i&-i){
        bit[i] = min(bit[i], v);
    }
}

bool query(int i, int v){
    for(;i>0; i-=i&-i){
        if(bit[i] < v) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(bit, 0x3f, sizeof bit);

    int n; cin >> n;
    for(int i = 1, x; i <= n; i++) {cin >> x; a[x].a = i;}
    for(int i = 1, x; i <= n; i++) {cin >> x; a[x].b = i;}
    for(int i = 1, x; i <= n; i++) {cin >> x; a[x].c = i;}

    sort(a+1, a+n+1, [](trip x, trip y){return x.a < y.a;});
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!query(a[i].b, a[i].c)) res++;
        add(a[i].b, a[i].c);
    }

    cout << res;

    return 0;
}