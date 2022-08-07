#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

vector<pair<string, char>> fg;
string s;

unordered_map<int, string> dp;
string go(int i){
    if(i == s.size()) return "";
    if(dp.find(i) != dp.end()) return dp[i];

    string res = "";
    for(auto[v, k] : fg){
        if(i + v.size() > s.size()) continue;
        if(s.substr(i,v.size())==v){
            string nxt = go(i+v.size());
            if(nxt == "-1") continue;

            if(res=="")res=k+nxt;
            else{
                if(nxt.size()+1 < res.size()) res = k+nxt;
                else if(nxt.size()+1 == res.size()) res = min(res, k+nxt);
            }
        }
    }
    if(res == "" && i < s.size()) return dp[i] = "-1";
    return dp[i] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n,m; cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++){
        char c; string r; cin >> c >>r;
        fg.push_back({r, c});
    }

    cout << go(0);

    return 0;
}