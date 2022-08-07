#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
const int MM = 8388608 + 5;

bool a[27];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string s; cin >> s;
    for(char c : s) a[c-'a'] = 1;

    for(int i = 0; i < 27; i++){
        if(!a[i]){
            cout << (char)(i+'a');
            break;
        }
    }

    return 0;
}