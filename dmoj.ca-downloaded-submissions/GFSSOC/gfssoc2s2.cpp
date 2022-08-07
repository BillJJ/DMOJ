#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MM = 1e5+5;

vector<vector<string> > combs;
set<vector<string>> settt;
string s[11]; int c[11];

int main()  {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    for(int i = 0; i < n; i++){
        cin >> s[i] >> c[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            for(int k = 0; k < n; k++){
                if(i == k || j == k) continue;

                if(c[i]+c[j]+c[k] <= t){
                    combs.push_back({s[i], s[j], s[k]});
                    sort(combs.back().begin(), combs.back().end());
                }
            }
        }
    }

    settt.insert(combs.begin(), combs.end());
    combs.clear();
    for(const vector<string> &v : settt){
        combs.push_back(v);
    }
    sort(combs.begin(), combs.end());
    for(const vector<string> &v : combs){
        for(string str : v){
            cout << str << " ";
        }
        cout << "\n";
    }

    return 0;
}