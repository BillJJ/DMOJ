#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e5+5;

int w[200][200];
string s, t;

bool work(char x, char y){
    string one="", two="";
    for(char c : s){
        if(c == x || c == y) one += c;
    }
    for(char c : t){
        if(c == x || c == y) two += c;
    }
    return one == two;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s >> t;

    for(int i = 'a'; i <= 'r'; i++){
        for(int j = 'a'; j <= 'r'; j++){
            w[i][j] = w[j][i] = work(i, j);
        }
    }

    int q; cin >> q;
    while(q--){
        string l; cin >> l;
        bool flag = 1;
        for(int i = 0; i < l.size(); i++){
            for(int j = i+1; j < l.size(); j++){
                flag &= w[l[i]][l[j]];
            }
            flag &= w[l[i]][l[i]];
        }
        if(flag)cout<<"Y";
        else cout << "N";
    }

    return 0;
}