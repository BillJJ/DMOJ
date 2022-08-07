#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MM = 1e5+5;

struct bot{
    string s; int l, r;
};

vector<bot> a;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string cmd; int x, y; cin >> cmd >> x >> y;
        a.push_back({cmd, x, y});
    }

    reverse(a.begin(), a.end());
    int l=-1, r=-1;
    for(auto[s, x, y] : a){
        if(s == "off" && l != -1){
            l+=min(x, y); r += max(x, y);
        } else if(s == "on" && l != -1){
            l -= max(x, y); r -= min(x, y);
        } else if(s == "none" && l==-1){
            l = x, r = y;
        } else if(s == "none"){
            l = max(l, x), r = min(r, y);
        }
    }

    cout << (l<0?0:l) << " " << r << '\n';

    reverse(a.begin(), a.end());
    l=-1,r=-1;
    for(auto[s, x, y] : a){
        if(l==-1){
            if(s == "none") l=x,r=y;
        } else if(s == "on"){
            l += min(x, y), r += max(x, y);
        } else if(s == "none"){
            l = max(l, x), r = min(y, r);
        } else if(s == "off"){
            l -= max(x, y), r -= min(x, y);
        }
    }
    cout << (l<0?0:l) << " " << r << '\n';

    return 0;
}