#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MM = 2e5+5;

string j[] = {"ka", "ki", "ku", "ke", "ko", "na", "ni", "nu", "ne", "no", "ha", "hi", "fu", "he", "ho", "ma", "mi", "mu", "me",
"mo", "ra", "ri", "ru", "re", "ro", "a", "i", "u", "e", "o"};

const string con = "knhmr", vow = "aiueo";

void solve(){
    string s; cin >> s;
    int i = 0;
    bool flag = 0;
    string b= "";
    while(i < s.size()){
        if(s[i] == 'f'){
            b +="fu";
            i += 2;
        } else if(con.find(s[i]) != con.npos){
            b += s[i];
            i += 1;
            if(i >= s.size()){cout << "NO\n"; return;}
            if(s[i-1] == 'h'){
                if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o'){
                    b += s[i];
                    i += 1;
                } else{cout << "NO\n"; return;}
            } else{
                if(vow.find(s[i]) == vow.npos){cout << "NO\n"; return;}
                else{
                    b += s[i];
                    i += 1;
                }
            }
        } else if(vow.find(s[i]) != vow.npos){
            b+=s[i];
            i+=1;
        } else{cout << "NO\n"; return;}
    }

    if(s == b){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }
    return;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}