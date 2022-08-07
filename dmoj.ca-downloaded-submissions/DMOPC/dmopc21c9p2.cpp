#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 1e6+5;

string s, t;
void solve(){
    cin >> s >> t;
    stack<char> stk;

    int tar=0;
    for(int i = 0; i < s.size(); i++){
        if(tar == t.size()){
            cout << "NO\n";  return;
        }
        if(t[tar] == s[i]){
            if(!stk.empty()) {cout << "NO\n"; return;}
            tar++;
        } else if(s[i] == 'z'){cout << "NO\n"; return;}
        else{
            char c = s[i];
            if(stk.empty()){
                stk.push(c);
                continue;
            }
            while(!stk.empty() && c == stk.top() && c!='z'){
                stk.pop();
                c++;
            }
            if(c == t[tar]){
                if(!stk.empty()) {cout << "NO\n"; return;}
                tar++;
            } else stk.push(c);
        }
    }
    if(tar == t.size() && !stk.empty()){
        cout << "NO\n";  return;
    }
    while(tar < t.size() && !stk.empty()){
        char c = stk.top();
        while(!stk.empty() && c != t[tar] && c <= 'z' && c == stk.top()){
            stk.pop();
            c++;
        }
        if(c == t[tar]){
            if(!stk.empty()) {cout << "NO\n"; return;}
        } else{cout << "NO\n"; return;}
    }
    if(tar == t.size() && !stk.empty()){
        cout << "NO\n";  return;
    }
    if(tar < t.size()){cout << "NO\n"; return;}
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}