#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e3+5;

int res = 0, k;

void f(set<pii> vis, vector<int> s){
    if(vis.empty()){
        bool flag=1;
        for(int i = 1; i <= 4;i++){
            if(i != k) flag &= (s[i]<s[k]);
        }
        res+=flag;
        return;
    }
    pii p = *vis.begin();
    vis.erase(vis.begin());

    s[p.first]+=3;
    f(vis, s);
    s[p.first]-=3;

    s[p.second]+=3;
    f(vis, s);
    s[p.second]-=3;

    s[p.first]++,s[p.second]++;
    f(vis, s);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    set<pii> vis;
    vector<int> s(5);
    for(int i = 1; i <= 4; i++){
        for(int j = i+1; j <=4;j++){
            vis.insert({i,j});
        }
    }

    int n; cin >> k >> n;
    for(int i = 1; i <= n; i++){
        int a, b, s1, s2; cin >>a>>b>>s1>>s2;
        if(a>b) swap(a,b);
        if(s1 > s2){
            s[a]+=3;
        } else if(s2 > s1) s[b]+=3;
        else s[a]++, s[b]++;
        vis.erase({a,b});
    }

    f(vis, s);
    cout << res;

    return 0;
}